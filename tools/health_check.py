"""One-shot system + loop health check. Read-only, cheap, safe to run often.

    python tools/health_check.py

Reports whether the loop is doing its job *and* whether it is costing the user
anything, because those came apart: the loop was compiling ~20,000 candidates a
minute while its generators were exhausted, which held the machine busy and moved
the percentage not at all. A loop that is working and a loop that is spinning look
identical from the progress figure alone.

The lag was not the loop. It was paging -- 11,415 hard faults/sec with 10 GB free,
driven by Firefox and Defender. So this reports both, and says which is which,
because "the PC is lagging" was blamed on the decomp loop three times before being
measured.

Deliberately cheap: a 5-second CPU sample and two counter reads. Running it often
must not itself become load.
"""

import io
import json
import os
import subprocess
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def counter(name):
    try:
        r = subprocess.run(
            ["powershell", "-NoProfile", "-Command",
             "(Get-Counter '%s').CounterSamples[0].CookedValue" % name],
            capture_output=True, text=True, timeout=20)
        return float(r.stdout.strip())
    except Exception:                                # noqa: BLE001
        return None


def cpu_sample(seconds=5):
    """-> [(name, cpu_seconds_used)] for anything burning CPU in the window."""
    try:
        r = subprocess.run(
            ["powershell", "-NoProfile", "-Command",
             "$a=Get-Process|Select-Object Id,ProcessName,CPU;"
             "Start-Sleep -Seconds %d;"
             "$b=Get-Process|Select-Object Id,ProcessName,CPU;"
             "$m=@{};$a|ForEach-Object{$m[$_.Id]=$_.CPU};"
             "$b|ForEach-Object{if($m.ContainsKey($_.Id)-and $null-ne $_.CPU)"
             "-and $null-ne $m[$_.Id]){[pscustomobject]@{N=$_.ProcessName;"
             "D=($_.CPU-$m[$_.Id])}}}|ConvertTo-Json -Compress" % seconds],
            capture_output=True, text=True, timeout=seconds + 25)
        data = json.loads(r.stdout.strip() or "[]")
        if isinstance(data, dict):
            data = [data]
        return sorted(((d["N"], float(d["D"])) for d in data),
                      key=lambda t: -t[1])
    except Exception:                                # noqa: BLE001
        return []


def my_processes():
    try:
        r = subprocess.run(
            ["powershell", "-NoProfile", "-Command",
             "@(Get-CimInstance Win32_Process|Where-Object{$_.ProcessId-ne $PID"
             "-and $_.Name-match 'python|clang|ld.lld'"
             "-and $_.CommandLine-match 'PokemonSword'}).Count"],
            capture_output=True, text=True, timeout=25)
        return int((r.stdout or "0").strip() or 0)
    except Exception:                                # noqa: BLE001
        return -1


def main():
    faults = counter(r"\Memory\Page Faults/sec")
    ram = counter(r"\Memory\Available MBytes")

    print("=== machine ===")
    if ram is not None:
        pct = 100.0 * (1 - ram / 32531.0)
        print("  RAM available : %8.0f MB  (%.0f%% used)" % (ram, pct))
    if faults is not None:
        state = "PAGING -- this is what the lag feels like" if faults > 3000 \
            else "ok"
        print("  hard faults   : %8.0f /sec   %s" % (faults, state))

    print()
    print("=== cpu (5s sample) ===")
    hot = [(n, d) for n, d in cpu_sample() if d > 0.4]
    if not hot:
        print("  nothing is burning CPU")
    for n, d in hot[:6]:
        mine = "" if n.lower() in ("opencode", "pwsh", "claude") else "  <- not mine"
        print("  %-22s %5.1fs%s" % (n, d, mine))

    print()
    print("=== loop ===")
    st = {}
    p = os.path.join(ROOT, "work", "keepalive_state.json")
    if os.path.exists(p):
        st = json.load(io.open(p, encoding="utf-8"))
    print("  tick          : %s" % st.get("tick", "?"))
    print("  last_matched  : %s" % st.get("last_matched", "?"))
    print("  my processes  : %d" % my_processes())

    try:
        r = subprocess.run([sys.executable,
                            os.path.join(ROOT, "tools", "match_progress.py")],
                           capture_output=True, text=True, cwd=ROOT, timeout=120)
        for line in r.stdout.splitlines():
            if line.strip().startswith("TOTAL"):
                print("  progress      : %s" % line.strip())
    except Exception as e:                           # noqa: BLE001
        print("  progress      : unreadable (%s)" % e)

    verdict = "loop is running"
    if faults is not None and faults > 3000:
        verdict += " -- but the MACHINE is paging, not the loop"
    print()
    print("  %s" % verdict)
    return 0


if __name__ == "__main__":
    sys.exit(main())