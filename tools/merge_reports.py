"""Merge `auto_match --report` files into the module registries.

    python tools/merge_reports.py work/rep_cfs_main.json work/rep_cfs_sdk.json
    python tools/merge_reports.py --check work/rep_cfs_main.json

## Why this exists

`sl_register.py` registers **straight-line** bodies: it drives
`auto_match.collect(module, ["straight"], limit)` and so never sees any other
shape. Running it after a shape-generator fix registers nothing for that shape --
it printed its "next steps" footer having added 24 unrelated `ret_only` records,
which is exactly the sort of thing that reads as progress.

`auto_match --report` writes the verified records for whatever shapes were asked
for. This merges them, preserving every field, and is idempotent on `(module,
addr)`.

## What it does not do

It does not verify. The records came from `auto_match`, which compares the
compiled bytes against the original; re-verifying here would duplicate that. The
check is structural: the report must already be a list of records, and a record is
added only if its address is not already present. A report that was hand-edited
into containing a wrong body would be merged as-is, so the report is treated as
trusted input -- which is why it is written by a tool, not by a person.
"""

import argparse
import collections
import io
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def load_report(path):
    with io.open(path, encoding="utf-8") as f:
        d = json.load(f)
    if isinstance(d, dict):
        # `--report` writes {module, population, matched}. Unwrap to `matched`
        # specifically: a generic "find a list" search finds `population` first
        # (it is a dict of per-shape counts) and yields "0 new" for every report,
        # which reads exactly like "already registered" and is how this went
        # wrong once.
        if "matched" in d and isinstance(d["matched"], list):
            return d["matched"]
        for key in ("rows", "results"):
            if isinstance(d.get(key), list):
                return d[key]
        raise SystemExit("%s has no 'matched' list (keys: %s)"
                         % (path, sorted(d)))
    if not isinstance(d, list):
        raise SystemExit("%s is not a list of records" % path)
    return d


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("reports", nargs="+")
    ap.add_argument("--check", action="store_true",
                    help="report what would be added, write nothing")
    a = ap.parse_args()

    by_mod = collections.defaultdict(list)
    for p in a.reports:
        full = p if os.path.isabs(p) else os.path.join(ROOT, p)
        recs = load_report(full)
        for r in recs:
            mod = r.get("module")
            if mod is None or "addr" not in r:
                continue
            by_mod[mod].append(r)
        print("  %-34s %5d records" % (os.path.basename(p), len(recs)))

    total = 0
    for mod, recs in sorted(by_mod.items()):
        path = os.path.join(ROOT, "data", "matched_%s.json" % mod)
        if not os.path.exists(path):
            print("  %-8s no registry; skipped" % mod)
            continue
        with io.open(path, encoding="utf-8") as f:
            reg = json.load(f)
        have = {r["addr"] for r in reg.get("matched", [])}
        add = [r for r in recs if r["addr"] not in have]
        shapes = collections.Counter(r.get("shape") for r in add)
        print("  %-8s %6d records, %6d new %s"
              % (mod, len(recs), len(add),
                 dict(shapes.most_common(4)) if add else ""))
        if not add or a.check:
            continue
        reg.setdefault("matched", []).extend(add)
        with io.open(path, "w", encoding="utf-8") as f:
            json.dump(reg, f, indent=1, sort_keys=True)
        total += len(add)

    if a.check:
        print("(check only; nothing written)")
    else:
        print()
        print("merged %d new records" % total)
        if total:
            print("next: python tools/decomp_project.py")
            print("      python tools/prog_cmake.py")
    return 0


if __name__ == "__main__":
    sys.exit(main())