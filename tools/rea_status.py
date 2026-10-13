"""Report what is actually registered, in both opencode and Claude, for REA.

The session history claims REA was "installed and registered ... via
tools/register_rea_mcp.py with absolute paths", and separately that
`rea mcp add` failed with `spawn npx ENOENT`. Those are easy to conflate with
success. This reads both configs and prints what is really there, so the next
claim about REA is about a verified state rather than a remembered one.

Read-only. Writes nothing.
"""

import io
import json
import os
import subprocess
import sys


def show(path, keys):
    if not os.path.exists(path):
        print("  MISSING  %s" % path)
        return None
    try:
        data = json.load(io.open(path, encoding="utf-8"))
    except Exception as e:                                # noqa: BLE001
        print("  UNREADABLE %s (%s)" % (path, e))
        return None
    print("  %s" % path)
    for k in keys:
        node = data.get(k)
        if not isinstance(node, dict):
            print("    %-14s (absent)" % k)
            continue
        print("    %-14s %d server(s): %s"
              % (k, len(node), ", ".join(sorted(node)) or "-"))
        for name, cfg in sorted(node.items()):
            if "rea" not in name.lower():
                continue
            cmd = cfg.get("command") if isinstance(cfg, dict) else cfg
            args = cfg.get("args", []) if isinstance(cfg, dict) else []
            print("      -> %s" % name)
            print("         command : %s" % cmd)
            for a in args:
                print("         arg     : %s" % a)
            if isinstance(cfg, dict):
                env = cfg.get("env") or {}
                for k2, v2 in env.items():
                    print("         env %s: %s" % (k2, v2))
                if "disabled" in cfg:
                    print("         disabled: %s" % cfg["disabled"])
                if "enabled" in cfg:
                    print("         enabled : %s" % cfg["enabled"])
    return data


def run(cmd, timeout=60):
    try:
        r = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)
        return r.returncode, (r.stdout or "") + (r.stderr or "")
    except FileNotFoundError:
        return 127, "not found: %s" % cmd[0]
    except Exception as e:                                # noqa: BLE001
        return 1, str(e)


print("=== the CLI itself ===")
code, out = run(["rea", "--version"])
print("  rea --version -> rc=%d %s" % (code, out.strip()[:120]))
code, out = run(["rea", "--help"])
print("  rea --help (first lines):")
for line in out.splitlines()[:16]:
    print("    %s" % line.rstrip())

print()
print("=== rea mcp subcommand ===")
code, out = run(["rea", "mcp", "--help"])
print("  rc=%d" % code)
for line in out.splitlines()[:22]:
    print("    %s" % line.rstrip())

print()
print("=== registered in opencode ===")
show(os.path.join(os.environ["USERPROFILE"], ".config", "opencode",
                  "opencode.json"), ["mcp"])

print()
print("=== registered in Claude ===")
cj = os.path.join(os.environ["USERPROFILE"], ".claude.json")
show(cj, ["mcpServers"])
# Claude also scopes per-project servers inside .claude.json under "projects"
try:
    data = json.load(io.open(cj, encoding="utf-8"))
    projs = data.get("projects") or {}
    hit = False
    for proj, cfg in projs.items():
        srv = (cfg or {}).get("mcpServers") or {}
        for name in srv:
            if "rea" in name.lower():
                hit = True
                print("    project %s" % proj)
                print("      -> %s" % name)
                print("         command : %s" % srv[name].get("command"))
                for a in srv[name].get("args", []):
                    print("         arg     : %s" % a)
    if not hit:
        print("    no per-project rea entry in .claude.json")
except Exception as e:                                    # noqa: BLE001
    print("    (could not inspect projects: %s)" % e)

print()
print("=== is the MCP entry resolvable? ===")
for label, path, keys in (
        ("opencode", os.path.join(os.environ["USERPROFILE"], ".config",
                                  "opencode", "opencode.json"), ["mcp"]),
        ("claude", cj, ["mcpServers"])):
    try:
        data = json.load(io.open(path, encoding="utf-8"))
    except Exception:                                    # noqa: BLE001
        continue
    for k in keys:
        srv = data.get(k) or {}
        for name, cfg in srv.items():
            if "rea" not in name.lower() or not isinstance(cfg, dict):
                continue
            cmd = cfg.get("command")
            args = cfg.get("args") or []
            ok_cmd = bool(cmd) and os.path.exists(cmd)
            print("  %-9s %s" % (label, name))
            print("    command exists : %s   %s" % (ok_cmd, cmd or "-"))
            for i, a in enumerate(args):
                p = a if os.path.isabs(a) else os.path.join(
                    os.path.dirname(cmd or ""), a)
                print("    arg[%d] %-46s exists=%s"
                      % (i, a, os.path.exists(p)))