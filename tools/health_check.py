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
            capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=20)
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
            capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=seconds + 25)
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
            capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=25)
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
    state_age = None
    if os.path.exists(p):
        st = json.load(io.open(p, encoding="utf-8"))
        state_age = time.time() - os.path.getmtime(p)
    print("  tick          : %s" % st.get("tick", "?"))
    print("  last_matched  : %s" % st.get("last_matched", "?"))
    print("  my processes  : %d" % my_processes())
    if state_age is not None:
        print("  state age     : %ds" % int(state_age))

    # The watchdog stamp is a second, independent clock. Tier 1 restarting the
    # chain is not evidence the chain is working -- the watchdog stamped for
    # 21.8 hours while tier 2 and tier 3 were both dead -- so its stamp is
    # reported, never treated as proof of life on its own.
    wd = os.path.join(ROOT, "work", "ping_watchdog.json")
    if os.path.exists(wd):
        try:
            print("  watchdog age  : %ds"
                  % int(time.time() - os.path.getmtime(wd)))
        except OSError:
            pass

    try:
        r = subprocess.run([sys.executable,
                            os.path.join(ROOT, "tools", "match_progress.py")],
                           capture_output=True, text=True, encoding="utf-8", errors="replace", cwd=ROOT, timeout=120)
        for line in r.stdout.splitlines():
            if line.strip().startswith("TOTAL"):
                print("  progress      : %s" % line.strip())
    except Exception as e:                           # noqa: BLE001
        print("  progress      : unreadable (%s)" % e)

    # PROGRESS, not liveness.
    #
    # This used to be the literal string "loop is running", printed
    # unconditionally, which is why a loop dead for 22 hours was reported healthy
    # on every beat: every process existed, and existence was the only thing ever
    # checked. A blocked Python process and a working one are indistinguishable by
    # pid.
    #
    # What distinguishes them is that a working one rewrites its state file.
    #
    # The threshold must clear the loop's OWN designed maximum interval, not a
    # round number. keepalive backs off exponentially when a tick gains nothing:
    #
    #     sleep_s = min(a.max_interval, a.interval * (2 ** min(idle - 1, 4)))
    #
    # with --max-interval defaulting to 1800 and --interval to 60, so a healthy
    # exhausted loop ticks every 960s. The first version of this check used 300
    # and therefore called the loop STALLED at 677s while it was doing exactly
    # what it was designed to do -- ping.log recorded "no gain in 36 ticks;
    # backing off to 960s" at the moment the check cried wolf.
    #
    # A check that reports a healthy system as broken gets ignored, which is how
    # the original liveness-only check failed in the first place. Twice the
    # ceiling is the smallest threshold that cannot do that.
    #
    # Note the asymmetry that is kept -- STALLED is still reported when every
    # process is alive, because that is precisely the case the original missed.
    STALL_SECONDS = 3600
    if state_age is None:
        verdict = "loop has NO STATE FILE -- not running"
    elif state_age > STALL_SECONDS:
        verdict = ("loop is STALLED -- no tick for %ds (threshold %ds, 2x the "
                   "1800s backoff ceiling); processes may well all be alive"
                   % (int(state_age), STALL_SECONDS))
    else:
        # Under the ceiling, but a long gap may still be the designed backoff
        # rather than a tick in progress. Say which, so the number is readable.
        verdict = "loop is ticking (%ds since last state write)" % int(state_age)
        if state_age > 300:
            verdict += (" -- past a normal tick; likely the exhausted-generator "
                        "backoff (up to 960s), not a stall")

    if faults is not None and faults > 3000:
        verdict += " -- but the MACHINE is paging, not the loop"
    print()
    print("  %s" % verdict)
    return 0


if __name__ == "__main__":
    sys.exit(main())