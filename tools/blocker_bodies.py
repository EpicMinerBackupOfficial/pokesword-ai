import sys, os, json, io, collections
sys.path.insert(0, os.path.join(os.path.abspath("."), "tools"))
import call_register as CR, straight_line as SL, match_harness as MH
md=MH._md()
att=collections.Counter(); bod=collections.defaultdict(set)
for mod in ("main","sdk","subsdk0","subsdk1"):
    reg={(r["addr"],r["size"]) for r in json.load(io.open("data/matched_%s.json"%mod,encoding="utf-8"))["matched"]}
    for addr,size,name,ident,target,work,n in CR.candidates(mod,reg,md,10**9):
        for nargs,ret in CR.prototype_order(work,mod,target):
            calls={target:{"name":"g","nargs":nargs,"ret":ret}}
            try:
                SL.StraightLine(work).translate(ident,calls=calls); break
            except SL.Bail as e:
                m=str(e)
                if m.startswith("unsupported mnemonic"): k="unsupported "+m.split("'")[1]
                elif "is not an argument register" in m and ".16b" in m: k="v0.16b operand"
                elif "is not an argument register" in m: k="other operand: "+m.split("operand ")[1].split(" ")[0]
                elif "not modelled" in m: k=m
                else: k="other: "+m[:38]
                att[k]+=1; bod[k].add((mod,addr))
                continue
            except Exception: continue
print("  %-44s %8s %8s" % ("blocker","attempts","BODIES"))
for k,v in att.most_common(12):
    print("  %-44s %8d %8d" % (k[:44], v, len(bod[k])))
print("  TOTAL distinct bodies blocked: %d" % len({b for s in bod.values() for b in s}))
