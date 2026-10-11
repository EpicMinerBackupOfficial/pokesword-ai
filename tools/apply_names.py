"""Apply the repo's existing naming resources to bodies that carry `sub_%x`.

## What was already here and unused

`data/name_propagation.csv` holds **6,176** proposed function names for `main`,
each with the rule that produced it:

    only-caller         5239   exactly one caller, so the name is unambiguous
    unique-callee        734   the callee is unique, so the name is unambiguous
    all-callers-agree   203   every caller agrees on the name

`data/rtti_classes.csv` holds **1,873** class names with module, address and
mangled form -- real data symbols in a binary that is otherwise stripped.

None of it reached the registry. `auto_match.collect` writes
`name = "sub_%x" % addr` and stops there, so 5,703 bodies that already have a
defensible name are emitted as `sub_860` while the registry's own name field sits
unused three directories away.

## What this does not claim

A propagated name is *evidence of a name*, not a verified one. It is applied to the
registry's `name` field, which is documentation, and it does not change any
verdict: nothing here can make a body count as matched. The rule and its support
count are recorded alongside so a reader can see why a name is there and judge it.

The `support` column is carried through unedited. For `only-caller` it is always 1
and means nothing; for `all-callers-agree` it is the number of callers that agreed,
which is the figure worth quoting.

## The names are NOT unique, and cannot be

    465 records named -> 259 distinct names, 81 of them reused
    ScbScene_2            x16
    NexMatchUpdateSessionSettingJob_ModifyAt   x19

A propagated name identifies a *callee concept*, not a function. Sixteen different
functions were all inferred to be `ScbScene_2`, which is a reasonable inference
about what they are and useless as an identifier.

So this does not and cannot rename the emitted symbols. `decomp_project.py` writes
the name into the `// <name>  (orig 0x..., <shape>)` banner above each body, which
is where a human reads it and where the information is worth having. The C symbol
stays `main_f_<hex>`, namespaced per module and unique, and the audit's
`prog/ namespaced symbols unique` check keeps it that way. Making these the real
identifiers would mean 16 functions called `ScbScene_2` in one translation unit,
which does not link.

That is the honest ceiling on this resource: 465 bodies now carry a name a reader
can use, and 22,663 still read `sub_<hex>`. The remaining 5,711 propagated names
belong to bodies that are not matched yet, so there is nothing to attach them to.

Naming a function `sub_860` when the repo has decided it is
`Real_FFT_optimization_must_be_even` costs nothing today and is not recoverable
later -- once a name is emitted it gets used, reviewed and depended upon.

Usage:
    python tools/apply_names.py            # rewrite the registries
    python tools/apply_names.py --dry-run  # report only
"""

import argparse
import collections
import csv
import io
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MODULES = ("main", "sdk", "subsdk0", "subsdk1", "rtld")


def load_propagated():
    p = os.path.join(ROOT, "data", "name_propagation.csv")
    if not os.path.exists(p):
        return {}
    out = collections.defaultdict(dict)
    with io.open(p, encoding="utf-8") as f:
        for r in csv.DictReader(f):
            try:
                a = int(r["addr"], 16)
            except (KeyError, ValueError):
                continue
            nm = (r.get("proposed_name") or "").strip()
            if not nm or nm.startswith("unnamed_"):
                continue
            out[r["module"]][a] = {
                "name": nm,
                "rule": r.get("rule", ""),
                "support": r.get("support", ""),
            }
    return out


def load_rtti():
    p = os.path.join(ROOT, "data", "rtti_classes.csv")
    if not os.path.exists(p):
        return {}
    out = collections.defaultdict(list)
    with io.open(p, encoding="utf-8") as f:
        for r in csv.DictReader(f):
            out[r["module"]].append(r)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()

    prop = load_propagated()
    rtti = load_rtti()
    print("resources: %d propagated names, %d RTTI symbols"
          % (sum(len(v) for v in prop.values()),
             sum(len(v) for v in rtti.values())))
    if not prop:
        print("nothing to apply")
        return 0

    total_renamed = 0
    total_records = 0
    for mod in MODULES:
        path = os.path.join(ROOT, "data", "matched_%s.json" % mod)
        if not os.path.exists(path):
            continue
        reg = json.load(open(path, encoding="utf-8"))
        recs = reg.get("matched", [])
        total_records += len(recs)
        names = prop.get(mod, {})
        if not names:
            continue
        renamed = 0
        for r in recs:
            hit = names.get(r.get("addr"))
            if not hit:
                continue
            cur = r.get("name") or ""
            # Only replace a placeholder. A hand-chosen or already-meaningful name
            # outranks a propagated guess, and overwriting one would silently
            # discard work this tool has no way to judge.
            if not cur.startswith("sub_"):
                continue
            r["name"] = hit["name"]
            r["name_rule"] = hit["rule"]
            r["name_support"] = hit["support"]
            renamed += 1
        if renamed:
            total_renamed += renamed
            print("  %-8s %6d/%6d records named" % (mod, renamed, len(recs)))
            if not a.dry_run:
                with io.open(path, "w", encoding="utf-8") as f:
                    json.dump(reg, f, indent=1, sort_keys=True)

    print()
    print("named %d of %d records" % (total_renamed, total_records))
    if rtti:
        print("RTTI: %d class symbols available for struct naming "
              "(not applied here -- it names types, not functions)"
              % sum(len(v) for v in rtti.values()))
    if a.dry_run:
        print("dry run: nothing written")
    else:
        print("next: python tools/decomp_project.py   (emit prog/)")
    return 0


if __name__ == "__main__":
    sys.exit(main())