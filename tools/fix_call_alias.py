"""Rewrite the search alias out of registered `call` sources.

`call_register.py` compiles each candidate against a per-body alias,
`g_<target>_<addr>`, because two bodies in one TU that call the same callee with
different arities cannot both carry a prototype that agrees. That alias is right
for compiling and wrong for shipping: it is a name that exists only in the probe
TU, so the emitted `prog/matched/<module>/source/*.cpp` does not build.

    prog/matched/sdk/source/sdk_3.cpp:270:58:
        error: use of undeclared identifier 'g_512700_18b690'

The fix is a rename, not a re-derivation: the alias is unique per body, appears
only in that record's own source, and maps onto the `callee` already recorded
alongside it. So this rewrites the field in place -- no recompilation, and no risk
of the 2,856 bodies being re-derived differently this time.

It also fixes the real cause for next time, by rejecting an alias that leaked into
a registered source rather than letting the build find out.
"""

import io
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ALIAS = re.compile(r"\bg_[0-9a-f]+_[0-9a-f]+\b")


def main():
    total = 0
    for mod in ("main", "sdk", "subsdk0", "subsdk1"):
        path = os.path.join(ROOT, "data", "matched_%s.json" % mod)
        if not os.path.exists(path):
            continue
        data = json.load(io.open(path, encoding="utf-8"))
        changed = 0
        for r in data["matched"]:
            if r.get("shape") not in ("call", "delegator"):
                continue
            src = r.get("src") or ""
            if not ALIAS.search(src):
                continue
            real = r.get("callee")
            if not real:
                # `callee_synthetic` names are `callee_<hex>`; the alias carries
                # the target address in its first component, so recover it rather
                # than inventing a second convention.
                m = ALIAS.search(src)
                target = m.group(0).split("_")[1]
                real = "callee_%s" % target
                r["callee"] = real
                r["callee_synthetic"] = True
            new = ALIAS.sub(real, src)
            if new != src:
                r["src"] = new
                changed += 1
        if changed:
            io.open(path, "w", encoding="utf-8", newline="").write(
                json.dumps(data, indent=1, sort_keys=True))
        print("  %-9s %5d call source(s) rewritten" % (mod, changed))
        total += changed
    print("  total   %5d" % total)

    # Verify: nothing left carrying an alias.
    left = 0
    for mod in ("main", "sdk", "subsdk0", "subsdk1"):
        path = os.path.join(ROOT, "data", "matched_%s.json" % mod)
        if not os.path.exists(path):
            continue
        for r in json.load(io.open(path, encoding="utf-8"))["matched"]:
            if r.get("shape") in ("call", "delegator") and \
                    ALIAS.search(r.get("src") or ""):
                left += 1
    print("  aliases remaining: %d" % left)
    return 1 if left else 0


if __name__ == "__main__":
    sys.exit(main())