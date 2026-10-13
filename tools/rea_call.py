"""Call REA tools over MCP directly, without depending on the host's catalogue.

Two reasons this exists rather than using the `tools.rea.*` bridge:

  * the harness's tool catalogue is explicitly partial, and it no longer lists the
    `rea` namespace at all, so `search` returns nothing for it and the bridge is
    not callable even though the server is live and correctly registered;
  * `claude mcp list` reports the same server as "failed to connect" because its
    health check has a short timeout, while a real handshake answers `initialize`
    and returns 170 tools. Two of the three ways of asking disagree, so the only
    trustworthy check is speaking the protocol.

So this is a small MCP client: launch, initialize, `tools/call`, print the result.
Framing is newline-delimited JSON, which the handshake probe confirmed by getting
a reply from it.

    python tools/rea_call.py list
    python tools/rea_call.py schema inspect_binary_layout
    python tools/rea_call.py call inspect_binary_layout '{"path": "..."}'

Exit code 0 on a tool result, 1 on a protocol error, 2 when the server refused.
The distinction matters: a refusal is a finding about REA, a protocol error is a
finding about this client, and they should never be reported as the same thing.
"""

import io
import json
import os
import queue
import subprocess
import sys
import threading
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NODE = r"C:\Program Files\nodejs\node.exe"
MJS = os.path.join(os.environ["APPDATA"], "npm", "node_modules",
                   "rea-agents", "scripts", "rea.mjs")
TIMEOUT = 120


class Rea(object):
    def __init__(self):
        env = dict(os.environ)
        env["NODE_NO_WARNINGS"] = "1"
        self.p = subprocess.Popen(
            [NODE, MJS, "--mcp"], stdin=subprocess.PIPE,
            stdout=subprocess.PIPE, stderr=subprocess.PIPE,
            text=True, bufsize=1, env=env)
        self.q = queue.Queue()
        self.err = []
        threading.Thread(target=self._pump, daemon=True).start()
        threading.Thread(target=self._pump_err, daemon=True).start()
        self._id = 0

    def _pump(self):
        for line in iter(self.p.stdout.readline, ""):
            self.q.put(line)
        self.q.put(None)

    def _pump_err(self):
        for line in iter(self.p.stderr.readline, ""):
            self.err.append(line.rstrip())

    def rpc(self, method, params, timeout=TIMEOUT):
        self._id += 1
        msg = {"jsonrpc": "2.0", "id": self._id, "method": method,
               "params": params}
        self.p.stdin.write(json.dumps(msg) + "\n")
        self.p.stdin.flush()
        end = time.time() + timeout
        while time.time() < end:
            try:
                line = self.q.get(timeout=max(0.2, end - time.time()))
            except queue.Empty:
                continue
            if line is None:
                raise RuntimeError("server closed stdout; stderr=%s"
                                   % (self.err[:3],))
            line = line.strip()
            if not line:
                continue
            try:
                obj = json.loads(line)
            except ValueError:
                continue
            if obj.get("id") == self._id:
                return obj
        raise RuntimeError("timed out after %ds on %s" % (timeout, method))

    def notify(self, method, params):
        self.p.stdin.write(json.dumps(
            {"jsonrpc": "2.0", "method": method, "params": params}) + "\n")
        self.p.stdin.flush()

    def handshake(self):
        r = self.rpc("initialize", {
            "protocolVersion": "2024-11-05", "capabilities": {},
            "clientInfo": {"name": "rea_call", "version": "1"}}, timeout=60)
        self.notify("notifications/initialized", {})
        return (r.get("result") or {}).get("serverInfo") or {}

    def tools(self):
        r = self.rpc("tools/list", {}, timeout=60)
        return (r.get("result") or {}).get("tools") or []

    def call(self, name, args):
        r = self.rpc("tools/call", {"name": name, "arguments": args})
        return r

    def close(self):
        try:
            self.p.kill()
        except Exception:                                # noqa: BLE001
            pass


def render(res, limit=4000):
    """Flatten an MCP tool result into text, and say whether REA refused.

    `limit=None` returns the whole payload. That matters when the caller is going
    to `json.loads` it: a truncated JSON document is not a small answer, it is an
    unparseable one, and the resulting decode error says nothing about REA.
    """
    out = []
    for block in (res.get("result") or {}).get("content") or []:
        out.append(block.get("text") or json.dumps(block))
    text = "\n".join(out)
    if (res.get("result") or {}).get("isError"):
        return True, text
    if res.get("error"):
        return True, "rpc error: %s" % json.dumps(res["error"])[:limit or 2000]
    return False, (text[:limit] if limit else text)


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 1
    verb = sys.argv[1]
    if not os.path.exists(MJS):
        print("rea.mjs not found: %s" % MJS)
        return 1

    r = Rea()
    try:
        info = r.handshake()
        if verb == "list":
            ts = r.tools()
            names = sorted(t.get("name", "") for t in ts)
            print("server %s %s -- %d tools"
                  % (info.get("name"), info.get("version"), len(names)))
            for n in names:
                print("  %s" % n)
            return 0
        if verb == "schema":
            if len(sys.argv) < 3:
                print("usage: schema <tool>")
                return 1
            for t in r.tools():
                if t.get("name") == sys.argv[2]:
                    print(json.dumps(t.get("inputSchema") or {}, indent=1))
                    return 0
            print("no such tool: %s" % sys.argv[2])
            return 2
        if verb == "call":
            if len(sys.argv) < 3:
                print("usage: call <tool> [json-args]")
                return 1
            name = sys.argv[2]
            args = json.loads(sys.argv[3]) if len(sys.argv) > 3 else {}
            refused, text = render(r.call(name, args))
            print(text)
            return 2 if refused else 0
        print("unknown verb: %s" % verb)
        return 1
    finally:
        r.close()


if __name__ == "__main__":
    sys.exit(main())