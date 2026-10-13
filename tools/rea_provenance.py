"""Use REA for the one thing it can actually do here: independent provenance.

The capability table settles the analysis question. Of 18 capabilities, 8 are
available on this host and every one of them is Apple/PE/CLI/artifact oriented;
10 more are blocked because they need macOS. None of the available ones reads ELF
code, names, or symbols, and the one ELF provider is `pwntools-elf`, which
supports Linux x64 only. So REA cannot help decompile these binaries here, and
installing it elsewhere would not change that -- the block is host and target
format, not configuration.

What it *can* do is `open_binary`, which reports format, kind, architecture and a
SHA-256 for a local image. That is worth having for a reason this project cannot
check itself: every existing integrity check is written by the same people who
produced the files. REA is an outside implementation, so a sha256 agreement here
is a genuine independent confirmation that `data/<mod>.elf` is still the retail
extraction and `build/<mod>.elf` is our rebuild.

That is a small claim and it is stated as a small claim. It does not decompile
anything. It does mean the retail-vs-rebuild distinction is not resting entirely
on this repository's word.
"""

import io
import json
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools"))

import rea_call as RC

OUT = os.path.join(ROOT, "data", "rea_provenance.json")


def digest_for(path):
    import hashlib
    h = hashlib.sha256()
    with io.open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def main():
    targets = []
    for sub in ("data", "build"):
        d = os.path.join(ROOT, sub)
        if not os.path.isdir(d):
            continue
        for n in sorted(os.listdir(d)):
            if n.endswith(".elf"):
                targets.append((sub, n, os.path.join(d, n)))

    r = RC.Rea()
    rows = []
    try:
        r.handshake()
        for sub, name, path in targets:
            refused, text = RC.render(r.call("open_binary", {"path": path}),
                                      limit=None)
            mine = digest_for(path)
            if refused:
                print("  %-22s REFUSED  %s" % ("%s/%s" % (sub, name), text[:150]))
                rows.append({"path": "%s/%s" % (sub, name), "size": os.path.getsize(path),
                             "sha256_local": mine, "rea": None, "error": text[:400]})
                continue
            got = json.loads(text)["result"]
            agree = (got.get("sha256") or "").lower() == mine
            print("  %-22s %-9s %-9s %s  sha256 %s"
                  % ("%s/%s" % (sub, name), got.get("format"),
                     got.get("architecture"), "AGREE" if agree else "DISAGREE",
                     (got.get("sha256") or "")[:16]))
            if not agree:
                print("      local : %s" % mine)
                print("      rea   : %s" % got.get("sha256"))
            rows.append({"path": "%s/%s" % (sub, name),
                         "size": os.path.getsize(path),
                         "format": got.get("format"),
                         "kind": got.get("kind"),
                         "architecture": got.get("architecture"),
                         "sha256_rea": got.get("sha256"),
                         "sha256_local": mine,
                         "sha256_agree": agree})
    finally:
        r.close()

    io.open(OUT, "w", encoding="utf-8").write(
        json.dumps({"source": "rea-agents open_binary", "images": rows},
                   indent=1, sort_keys=True))
    print()
    ok = sum(1 for x in rows if x.get("sha256_agree"))
    print("  %d/%d sha256 agree between REA and a local hash" % (ok, len(rows)))
    print("  wrote %s" % os.path.relpath(OUT, ROOT))


if __name__ == "__main__":
    main()