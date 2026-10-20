"""Register REA as an opencode MCP server, using absolute paths.

`rea mcp add` failed with `spawn npx ENOENT`: it shells out to bare `npx`, and the
global npm shim directory is not on the PATH the spawner inherits. The package is
installed and `rea.mjs` is present, so the fix is to write the config directly with
the two absolute paths that do exist.

    node C:\\...\\rea-agents\\scripts\\rea.mjs --mcp

Written by hand rather than by `rea mcp add` for that reason. `rea mcp add` is the
supported path and should be preferred if the PATH ever works; this exists because
it did not.

Idempotent: re-running replaces the entry rather than appending a second one.
"""

import io
import json
import os
import sys

CFG = os.path.expanduser("~/.config/opencode/opencode.json")
REA = os.path.expandvars(r"/home/terraelysio/.config/npm/node_modules/rea-agents/scripts/rea.mjs")
# Resolve `node` the same way rea_call.py and rea_handshake.py do. The Windows
# literal `C:\Program Files\nodejs\node.exe` is meaningless here: node arrives
# via mise at ~/.local/share/mise/installs/node/.../bin/node and is only on PATH
# through the shell that launched the bot.
NODE = __import__("shutil").which("node") or r"/usr/bin/node"


def main():
    if not os.path.exists(REA):
        print("rea.mjs not found at %s" % REA)
        print("  install it first:  npm install -g rea-agents")
        return 1
    if not os.path.exists(NODE):
        print("node not found at %s" % NODE)
        return 1

    with io.open(CFG, encoding="utf-8") as f:
        cfg = json.load(f)
    mcp = cfg.setdefault("mcp", {})
    if "rea" in mcp:
        print("  rea already registered; replacing")
    mcp["rea"] = {
        "type": "local",
        "command": [NODE, REA, "--mcp"],
        "enabled": True,
    }
    with io.open(CFG, "w", encoding="utf-8") as f:
        json.dump(cfg, f, indent=2)
    print("  registered rea in %s" % CFG)
    print("  command: %s %s --mcp" % (NODE, REA))
    print()
    print("  restart opencode for the server to be offered as tools")
    return 0


if __name__ == "__main__":
    sys.exit(main())