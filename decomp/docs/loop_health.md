# The decomp loop reports "running" while dead: liveness is not progress

`tools/health_check.py` printed `loop is running -- but the MACHINE is paging, not
the loop` on every beat for days. The loop had in fact been dead for 22 hours.

## The check that cannot fail

The health check's liveness test is *do the processes exist*. Every process was
alive. It passed, and it was reporting a corpse as healthy, because "the pid is
present" cannot distinguish a running loop from a blocked one — and on this machine
a blocked Python process looks exactly like a working one.

The evidence that was available the whole time and was not being read:

| signal | value | meaning |
|---|---|---|
| `work/keepalive_state.json` mtime | 31 min, interval is 120 s | not ticking |
| `tick` field | frozen at 2481 across beats | not progressing |
| `work/ping_watchdog.json` mtime | 78,371 s (21.8 h) | tier 1 not cycling |
| `work/ping_supervisor.json` | never written | tier 2 never stamped |
| process CPU time | 0.1 s / 0.1 s / 4.9 s since start | blocked, not looping |

All three supervising processes were started at the same instant on 10-12 and had
used almost no CPU since. They were not crashed and not looping — they were stuck.

`work/tick_debug.out` carried the design's own tell, at the bottom of the file:

    tick complete. relaunch to continue the loop.

`keepalive.py --loop` completes one tick and **exits**, expecting something to
relaunch it. That something is tier 2 (`ping_supervisor.py`), and tier 2 was itself
not cycling. Two tiers each waiting on the other to act is not supervision.

## The chain, and which link actually keeps the session alive

    ping_watchdog.py    tier 1  supervises tier 2
      ping_supervisor.py    tier 2  supervises the decomp loop
        keepalive.py --loop  tier 3  the decompilation loop

`tools/wake.py --loop --every 300` is a **separate** process. It is what actually
wakes the agent session, and it was healthy throughout (`wake_state.json`:
`last_rc 0`, 20 beats). So the session kept getting pinged, the agent kept waking
up, and the agent kept reporting a dead loop as running — which is exactly why this
survived so long unnoticed.

## Second, independent stall: heartbeat does not rearm

`heartbeat.py --rearm` is documented as starting its own successor before exiting.
It did so once — `ping.log` records `beat 1056 done; exit 0 regardless` then
`rearmed : successor pid 42956`. That successor ran beat 1057 as pid 48084 at
16:56:16 and then **nothing**: no beat 1058, no successor.

So the self-rearm is conditional and the condition is not met every time. This does
not affect the decomp loop, and `ping_watchdog.py --status` reports it honestly as
`PING STALE`, which is the right behaviour — the status line is more trustworthy
than the health check's.

## The fix that worked

    python tools/ping_watchdog.py --stop
    python tools/ping_watchdog.py --arm

The loop resumed immediately: tick 2481 -> 2482, `harvest_idx` 4 -> 5, verify and
push cycles running, and it self-healed a stale harvest lock left by a dead process.

## What should change so this cannot recur silently

1. **`health_check.py` must assert progress, not liveness.** Read the `tick` field
   and the mtime of `keepalive_state.json` and compare against the interval. A
   counter that has not moved while every process is alive is the failure mode, and
   it is the only one the current check misses.
2. **`keepalive.py --loop` should not need a relaunch.** The name promises a loop.
   Either it loops, or the flag is renamed; as it stands the contract is a lie that
   depends on a second process honouring an unwritten obligation.
3. **A tier that supervises a tier that exits is not supervision.** If tier 2 can
   exit, tier 1 must relaunch it, and tier 1's own stamp is the only evidence that
   it is doing so.
## Tier 1 stamped once, at spawn -- the 20-hour-old watchdog

`health_check.py` has reported `watchdog age` climbing for many beats, last at
72,682s, and it was carried as an unresolved anomaly. It is not an anomaly.

`supervise()` wrote the stamp and then called `child.wait()`:

    write_json(STAMP, {... "child_pid": child.pid ...})
    rc = child.wait()

`child.wait()` returns only when the child EXITS. Tier 2 lives for hours, so the
stamp stayed frozen at spawn time for the entire life of the process. The module
docstring says "The watchdog stamps `work/ping_watchdog.json` every cycle with its
pid, the child pid, the restart count and a timestamp" -- the code did it exactly
once. The process was alive the whole time; the stamp was wrong.

A stamp that only moves on restart cannot answer the question it exists to
answer. `--status` computes `age = now - stamp["at_epoch"]` and reports it as
"stamp age", which read as "this tier stopped stamping" when the truth is "this
tier stamped once and then waited". The distinction matters: the first says
investigate the supervisor, the second says the supervisor's reporting is broken.
It was the second, and only a process listing could tell them apart.

Fixed by polling the child instead of blocking on it, re-stamping each pass:

    rc = None
    while True:
        rc = child.poll()
        if rc is not None:
            break
        time.sleep(min(5, max(1, interval)))
        write_json(STAMP, {... "child_pid": child.pid ...})

`--selftest` passes, including the relaunch branch, so the poll correctly
detects child exit rather than looping forever:

    child #1 pid 31188
    killed child #1 on purpose
    child #2 pid 28516 (relaunched)
    SELFTEST PASSED

### Not restarted on purpose

The live tier-1 is still the old code; it adopts the fix on its next restart. I
did not restart the chain to hurry this along. `ping_watchdog.py --stop` stops the
WHOLE chain, and `wake.py --loop` is what pings this session -- the chain has
already died four separate times for unrelated reasons, and taking down tier 4 to
validate a reporting fix is a bad trade. The anomaly disappears when the process
next restarts on its own.

## adrp_register work directories collide

`work = os.path.join(ROOT, "work", "adrpreg")` was a fixed path, and the code
does `shutil.rmtree(work)` then `os.makedirs(work)`. Two concurrent runs race
twice: one gets `FileExistsError`, and worse, one run can `rmtree` the directory
the other is compiling in. One sweep died that way. The path is not in the
traceback -- only the work directory it names is -- so it reads as a generator
bug.

Now `work/adrpreg_<pid>`, and the linked-ELF temp is `_adrpreg_linked_<pid>.elf`
for the same reason.
