"""Which REA capabilities are actually available on this host, and for what.

`binary_session` returns every operation with `available`, `reason` and
`availability_code`. Printed raw it is a wall of JSON; what matters is the
partition -- what works here, what is blocked by the host, and specifically
whether anything ELF/AArch64 can reach it.

The point is to replace "REA cannot read these binaries" -- a claim this project
has repeated and never scoped -- with the actual list, so the next reader can see
exactly which operation is refused and why, rather than re-testing the one they
remember.
"""

import io
import json
import os
import subprocess
import nocon  # noqa: E402  -- installs the no-console default for every subprocess below
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

import rea_call as RC

INTEREST = ("elf", "aarch64", "arm64", "binary", "layout", "byte", "symbol",
            "name", "disas", "proc", "xref", "string", "segment", "section")


def main():
    r = RC.Rea()
    try:
        r.handshake()
        refused, text = RC.render(r.call("binary_session", {}), limit=None)
        caps = json.loads(text)["result"]["capabilities"]
    finally:
        r.close()

    print("=== %d capabilities reported ===" % len(caps))

    avail = [c for c in caps if c.get("available")]
    blocked = [c for c in caps if not c.get("available")]

    print()
    print("--- AVAILABLE here (%d) ---" % len(avail))
    for c in sorted(avail, key=lambda x: x["operation"]):
        print("  %-34s" % c["operation"])

    print()
    print("--- BLOCKED, by reason (%d) ---" % len(blocked))
    by_reason = {}
    for c in blocked:
        by_reason.setdefault(c.get("reason") or "(no reason given)", []).append(
            c["operation"])
    for reason, ops in sorted(by_reason.items(), key=lambda kv: -len(kv[1])):
        print("  %s  (%d)" % (reason, len(ops)))
        for o in sorted(ops)[:14]:
            print("      %s" % o)
        if len(ops) > 14:
            print("      ... and %d more" % (len(ops) - 14))

    print()
    print("--- of the AVAILABLE ones, anything touching ELF / code / names? ---")
    hits = [c for c in avail
            if any(w in c["operation"].lower() for w in INTEREST)]
    for c in sorted(hits, key=lambda x: x["operation"]):
        print("  %-34s %s" % (c["operation"],
                              "; ".join(c.get("limitations") or [])[:90]))
    if not hits:
        print("  none")

    print()
    print("--- what REA says about the retail ELF ---")
    r2 = RC.Rea()
    try:
        r2.handshake()
        refused, text = RC.render(r2.call("open_binary", {
            "path": os.path.join(ROOT, "data", "sdk.elf")}), limit=4000)
        print("  %s" % text)
        refused2, text2 = RC.render(r2.call("inspect_binary_layout", {
            "path": os.path.join(ROOT, "data", "sdk.elf"),
            "detail": "complete"}), limit=700)
        print("  inspect_binary_layout -> exit %s" % ("refused" if refused2 else "ok"))
        print("  %s" % text2[:600])
    finally:
        r2.close()


if __name__ == "__main__":
    main()