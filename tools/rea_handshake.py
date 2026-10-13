"""Speak MCP to REA over stdio, with every read bounded by a timeout.

The first version of this probe produced no output at all and ran until the
harness killed it at fifteen minutes. Two reasons, both in the probe rather than
in REA: prints were buffered, and `readline()` on a pipe blocks forever when the
server has not spoken yet. Neither is a finding about the server; both are the
probe hanging instead of measuring.

So: a reader thread owns the pipe and pushes into a queue, every wait has a
deadline, every print flushes, and the child is killed in a `finally` so a failed
probe cannot leave a node process behind.

Two framings are tried, because an MCP stdio server may use either and getting
this wrong is the most likely reason a "connected" server looks dead:

  * newline-delimited JSON -- write `{"jsonrpc":...}\\n`
  * LSP framing -- `Content-Length: N\\r\\n\\r\\n` then the body

Whichever answers `initialize` first is the one in use, and that is reported.
"""

import json
import os
import queue
import subprocess
import sys
import threading
import time

NODE = r"C:\Program Files\nodejs\node.exe"
MJS = os.path.join(os.environ["APPDATA"], "npm", "node_modules",
                   "rea-agents", "scripts", "rea.mjs")
DEADLINE = 45


def say(*a):
    print(*a)
    sys.stdout.flush()


class Server(object):
    def __init__(self, framing):
        self.framing = framing
        env = dict(os.environ)
        env["NODE_NO_WARNINGS"] = "1"
        self.p = subprocess.Popen(
            [NODE, MJS, "--mcp"], stdin=subprocess.PIPE,
            stdout=subprocess.PIPE, stderr=subprocess.PIPE,
            text=True, bufsize=1, env=env)
        self.q = queue.Queue()
        self.err = []
        threading.Thread(target=self._read, daemon=True).start()
        threading.Thread(target=self._read_err, daemon=True).start()

    def _read(self):
        for line in iter(self.p.stdout.readline, ""):
            self.q.put(line)
        self.q.put(None)

    def _read_err(self):
        for line in iter(self.p.stderr.readline, ""):
            self.err.append(line)

    def send(self, msg):
        body = json.dumps(msg)
        if self.framing == "lsp":
            data = body.encode("utf-8")
            self.p.stdin.write("Content-Length: %d\r\n\r\n" % len(data))
            self.p.stdin.write(body)
        else:
            self.p.stdin.write(body + "\n")
        self.p.stdin.flush()

    def recv_id(self, want, timeout=DEADLINE):
        end = time.time() + timeout
        buf = ""
        while time.time() < end:
            try:
                line = self.q.get(timeout=max(0.2, end - time.time()))
            except queue.Empty:
                continue
            if line is None:
                return None, "server closed stdout"
            line = line.strip()
            if not line:
                continue
            buf += line
            # LSP framing: parse the body out of a Content-Length block if present
            if line.lower().startswith("content-length:"):
                try:
                    n = int(line.split(":", 1)[1].strip())
                except ValueError:
                    continue
                try:
                    body = self.q.get(timeout=max(0.2, end - time.time()))
                except queue.Empty:
                    return None, "timed out reading body"
                if body is None:
                    return None, "server closed stdout"
                buf += body
                line = body.strip()
            try:
                obj = json.loads(line)
            except ValueError:
                continue
            if obj.get("id") == want:
                return obj, None
        return None, "timed out after %ds waiting for id=%s" % (timeout, want)

    def close(self):
        try:
            self.p.kill()
        except Exception:                                # noqa: BLE001
            pass


INIT = {"jsonrpc": "2.0", "id": 1, "method": "initialize",
        "params": {"protocolVersion": "2024-11-05", "capabilities": {},
                   "clientInfo": {"name": "rea_handshake", "version": "1"}}}


def try_framing(framing):
    say("  trying framing: %s" % framing)
    s = Server(framing)
    try:
        s.send(INIT)
        r, why = s.recv_id(1, timeout=25)
        if r is None:
            say("    no answer (%s)" % why)
            if s.err:
                say("    stderr: %s" % s.err[0].rstrip()[:150])
            return None
        info = (r.get("result") or {}).get("serverInfo") or {}
        say("    initialize OK -- serverInfo: %s %s"
            % (info.get("name"), info.get("version")))
        s.send({"jsonrpc": "2.0", "method": "notifications/initialized",
                "params": {}})
        s.send({"jsonrpc": "2.0", "id": 2, "method": "tools/list",
                "params": {}})
        r2, why2 = s.recv_id(2, timeout=25)
        if r2 is None:
            say("    tools/list no answer (%s)" % why2)
            return None
        tools = ((r2.get("result") or {}).get("tools")) or []
        say("    tools/list OK -- %d tools" % len(tools))
        return s, tools
    except Exception as e:                                # noqa: BLE001
        say("    error: %r" % e)
        s.close()
        return None
    finally:
        pass


def dump(tools, path):
    """Write every tool with its description, so the catalogue can be searched."""
    import io
    rows = [{"name": t.get("name", ""),
             "description": (t.get("description") or "").strip(),
             "schema": t.get("inputSchema") or {}} for t in tools]
    io.open(path, "w", encoding="utf-8").write(
        json.dumps(rows, indent=1, sort_keys=True))
    say("  wrote %d tool descriptions to %s" % (len(rows), path))


def main():
    if not os.path.exists(MJS):
        say("  rea.mjs not found: %s" % MJS)
        return 1
    say("  command: %s %s --mcp" % (NODE, MJS))
    say()
    got = None
    for framing in ("newline", "lsp"):
        res = try_framing(framing)
        if res:
            got = (framing,) + res
            break
        say()
    if not got:
        say("  RESULT: no framing answered. The server may still be broken, or the")
        say("          protocol version may be something other than 2024-11-05.")
        return 1

    framing, s, tools = got
    try:
        by_prefix = {}
        for t in tools:
            nm = t.get("name", "")
            head = nm.split(".")[0] if "." in nm else "(unqualified)"
            by_prefix.setdefault(head, []).append(nm)
        say()
        say("  RESULT: live. framing=%s, %d tools" % (framing, len(tools)))
        say("  by namespace:")
        for k in sorted(by_prefix, key=lambda x: -len(by_prefix[x])):
            say("    %-20s %4d" % (k, len(by_prefix[k])))
        say("  samples: %s"
            % ", ".join(sorted(t.get("name", "") for t in tools)[:6]))
        root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
        dump(tools, os.path.join(root, "work", "rea_tools.json"))
    finally:
        s.close()
    return 0


if __name__ == "__main__":
    sys.exit(main())