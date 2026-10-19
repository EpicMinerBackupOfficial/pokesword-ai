"""Wake the session headlessly. This is the part that was never built.

`heartbeat.py` has been reporting a healthy ping for as long as it has existed --
thousands of beats, a green `yes` in `ping_watchdog.py --status` -- and it never
once woke the agent. Read what a beat does:

    push in -> match_progress -> audit -> loop state -> push out

Four probes and two `git push`es. Not one line anywhere in it sends anything to
the session. It is a status reporter, and its green column means "a Python process
is sleeping", which is not the same claim as "the agent wakes up".

So the wake path has to be built, and the pieces turned out to be sitting in
plain sight:

    OPENCODE_SESSION_ID=ses_f0d99ceb2ffeM6oHtC2XiR2C6x     (in this process's env)
    opencode-cli.exe run --session <id> --prompt "<text>" --auto

`--session` continues a specific session and `--prompt` sends it a message, so a
watchdog can re-enter *this* conversation on a timer without a token and without
the desktop app's help: the CLI talks to the same local server and carries the
auth itself. `opencode-cli.exe api` exists for direct server access for the same
reason, but `run` is the one that produces a turn.

### Why it rate-limits, and why it refuses to overlap

A wake starts a turn. If the agent is *already* working, a second one overlaps it
and two turns interleave on the same session -- which produces two agents
committing at once. That is worse than not waking at all, so:

  * a lock file holds the turn's duration, and a wake inside it is skipped and
    reported as such rather than fired;
  * `OPENCODE_SESSION_ID` is captured once into `work/ping_session.txt` and reused,
    because a detached watchdog launched earlier has the *old* session in its
    environment and would otherwise send the wake to a conversation that is no
    longer live. `--session <stale>` would create a new session, which is how you
    end up with a silent agent working alone in a session nobody is watching.

    python tools/wake.py --status
    python tools/wake.py --once
    python tools/wake.py --loop --every 240
"""

import argparse
import io
import json
import os
import subprocess
import nocon  # noqa: E402  -- installs the no-console default for every subprocess below
import sys
import time

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
WORK = os.path.join(ROOT, "work")
SESSION_FILE = os.path.join(WORK, "ping_session.txt")
LOCK = os.path.join(WORK, "wake.lock")

# Where find_cli() looked last time it failed. Reported, so a dead wake loop
# says WHERE it looked instead of just not running.
LAST_CLI_SEARCH = []
STATE = os.path.join(WORK, "wake_state.json")

# Resolved at RUN TIME, never hardcoded to a version.
#
# These two lists used to name two exact versions under
# %APPDATA%\ai.opencode.desktop\cli\<version>\. The desktop app now ships the
# CLI at %LOCALAPPDATA%\Programs\@opencodedesktop\resources\opencode-cli.exe,
# so the hardcoded list stopped resolving, find_cli() returned None, and the
# wake loop died with:
#
#     FileNotFoundError: [WinError 2] The system cannot find the file specified
#
# after 23 successful beats -- which is why the session had to be pinged by hand
# for the next nineteen hours while the decomp loop and the heartbeat chain both
# reported healthy. A pinned path is a bug with a release cycle.
CLI_CANDIDATES = [
    # Current desktop layout.
    os.path.join(os.environ.get("LOCALAPPDATA", ""), "Programs",
                 "@opencodedesktop", "resources", "opencode-cli.exe"),
    # Per-user versioned layout, for older installs.
    os.path.join(os.environ.get("APPDATA", ""), "ai.opencode.desktop", "cli",
                 "2.0.26", "opencode-cli.exe"),
    os.path.join(os.environ.get("APPDATA", ""), "ai.opencode.desktop", "cli",
                 "2.0.27", "opencode-cli.exe"),
]

# Directory roots scanned newest-first for a versioned CLI.
CLI_ROOTS = [
    os.path.join(os.environ.get("APPDATA", ""), "ai.opencode.desktop", "cli"),
    os.path.join(os.environ.get("LOCALAPPDATA", ""), "Programs",
                 "@opencodedesktop", "resources"),
]

DEFAULT_PROMPT = (
    "Continue the Pokemon Sword decomp. Run "
    "`python tools/health_check.py` first, then `python tools/match_progress.py`. "
    "If the figure is unchanged from the last beat, the generators are exhausted: "
    "look for a new reachable population instead of re-running the old generators. "
    "Do the work, commit, and push. Keep the reply short -- report what changed, "
    "what is blocked, and what you would do next. If nothing is actionable, say so "
    "in one line rather than padding."
)


def find_cli():
    """Newest CLI found, or None with the searched roots recorded.

    `LAST_CLI_SEARCH` is kept because a silent None is exactly what made this
    failure invisible for nineteen hours: the loop died, the file it wrote said
    `last_rc: 0` from the previous successful beat, and nothing recorded that the
    binary had moved.
    """
    global LAST_CLI_SEARCH
    for p in CLI_CANDIDATES:
        if os.path.exists(p):
            LAST_CLI_SEARCH = [p]
            return p
    searched = []
    for root in CLI_ROOTS:
        searched.append(root)
        if not os.path.isdir(root):
            continue
        for ver in sorted(os.listdir(root), reverse=True):
            p = os.path.join(root, ver, "opencode-cli.exe")
            if os.path.exists(p):
                LAST_CLI_SEARCH = searched
                return p
            # Some layouts put the exe directly in the root.
            direct = os.path.join(root, "opencode-cli.exe")
            if os.path.exists(direct):
                LAST_CLI_SEARCH = searched
                return direct
    LAST_CLI_SEARCH = searched
    return None


def session_id():
    """The session to wake, preferring the one captured earlier.

    The live environment wins only if it differs from what was captured *and* the
    captured one looks stale. Simpler and safer: environment first, then file, and
    write the file whenever we learn one. A wake that guesses a session creates a
    new one, so this never invents an id.
    """
    env = os.environ.get("OPENCODE_SESSION_ID")
    if env:
        if os.path.exists(SESSION_FILE):
            try:
                old = io.open(SESSION_FILE, encoding="utf-8").read().strip()
            except OSError:
                old = ""
            if old and old != env:
                print("  session changed: %s -> %s" % (old, env))
        os.makedirs(WORK, exist_ok=True)
        io.open(SESSION_FILE, "w", encoding="utf-8").write(env)
        return env
    if os.path.exists(SESSION_FILE):
        s = io.open(SESSION_FILE, encoding="utf-8").read().strip()
        if s:
            return s
    return None


def lock_held():
    """-> seconds remaining on a live wake, or 0."""
    if not os.path.exists(LOCK):
        return 0
    try:
        start = float(io.open(LOCK, encoding="utf-8").read().strip())
    except (OSError, ValueError):
        return 0
    age = time.time() - start
    return 0 if age > 3600 else max(0.0, 3600 - age)


def acquire():
    os.makedirs(WORK, exist_ok=True)
    if lock_held():
        return False
    io.open(LOCK, "w", encoding="utf-8").write(str(time.time()))
    return True


def release():
    try:
        os.remove(LOCK)
    except OSError:
        pass


def record(**kw):
    st = {}
    if os.path.exists(STATE):
        try:
            st = json.load(io.open(STATE, encoding="utf-8"))
        except Exception:                               # noqa: BLE001
            st = {}
    st.update(kw)
    st["beats"] = int(st.get("beats", 0)) + 1
    io.open(STATE, "w", encoding="utf-8").write(json.dumps(st, indent=1))


def progress_line():
    try:
        r = subprocess.run([sys.executable,
                            os.path.join(ROOT, "tools", "match_progress.py")],
                           capture_output=True, text=True, encoding="utf-8",
            errors="replace", cwd=ROOT, timeout=180)
        for ln in r.stdout.splitlines():
            if ln.strip().startswith("TOTAL"):
                return ln.strip()
    except Exception:                                   # noqa: BLE001
        pass
    return "TOTAL (unreadable)"


API_PATH = "/api/session/%s/prompt"


API_MODEL = "/api/session/%s/model"
MODEL_ID = "space-bunny-free"
MODEL_PROVIDER = "opencode"


API_MSGS = "/api/session/%s/message"


def wait_idle(cli, sess, max_wait, poll=15):
    """Block until the session reports idle again, or `max_wait` elapses.

    Without this the loop posts on a fixed timer whether or not the previous turn
    finished, and the prompts stack: four arrived back to back before this was
    added. Nothing errors -- `resume: true` accepts each one, the session just
    accumulates them, and each queued turn then does work that the one before it
    already did.

    The last entry in the message list is `type: "idle"` once the turn has settled
    (an `assistant` entry means it is still running), which is enough to tell.
    Returns True if it went idle, False on timeout.
    """
    import json as _json
    end = time.time() + max_wait
    while time.time() < end:
        try:
            r = subprocess.run(
                [cli, "api", "GET", API_MSGS % sess],
                cwd=ROOT, capture_output=True, text=True,
                encoding="utf-8", errors="replace", timeout=60)
            data = _json.loads(r.stdout or "{}")
            items = data.get("data") if isinstance(data, dict) else None
            items = items or []
            if items and items[-1].get("type") == "idle":
                return True
        except Exception:                               # noqa: BLE001
            pass
        time.sleep(poll)
    return False


def wake(cli, sess, prompt, timeout):
    # Two calls, in this order.
    #
    # 1. POST /api/session/{id}/model  -- pin the model.
    #
    #    A session that does not already have one falls back to a default that is
    #    gated on this provider account, and every wake fails identically:
    #
    #      finish=error  provider.auth
    #      "This model requires you to complete the following before use:
    #       18+ age confirmation."
    #
    #    The endpoint's body is `{"model": {"id", "providerID"}}` -- nesting matters,
    #    and `{"providerID": ..., "modelID": ...}` returns
    #    `InvalidRequestError: Missing key at ["model"]`.
    #
    #    For a session that already runs on this model it is a harmless no-op, so
    #    it is sent unconditionally rather than guessed at.
    #
    # 2. POST /api/session/{id}/prompt -- {"text": ..., "resume": true}
    #
    # Verified end to end against a throwaway session:
    #
    #      finish=stop  model=space-bunny-free  text=WAKE_OK
    def call(path, body, timeout=120):
        cmd = [cli, "api", "POST", path, "--data", json.dumps(body)]
        return subprocess.run(cmd, cwd=ROOT, capture_output=True,
                           text=True, encoding="utf-8",
                           errors="replace",
                              timeout=timeout)

    r = call(API_MODEL % sess,
             {"model": {"id": MODEL_ID, "providerID": MODEL_PROVIDER}},
             timeout=60)
    if r.returncode:
        print("  model pin failed (rc=%d): %s" % (r.returncode,
                                                 (r.stderr or r.stdout)[:200]))

    body = {"text": prompt, "resume": True}
    cmd = [cli, "api", "POST", API_PATH % sess, "--data", json.dumps(body)]
    print("  waking %s" % sess)
    sys.stdout.flush()
    try:
        r = subprocess.run(cmd, cwd=ROOT, capture_output=True,
                           text=True, encoding="utf-8",
                           errors="replace",
                           timeout=timeout)
        tail = (r.stdout or r.stderr or "").strip().splitlines()
        for ln in tail[-4:]:
            print("    %s" % ln[:180])
        print("  rc=%d" % r.returncode)
        return r.returncode
    except subprocess.TimeoutExpired:
        print("  wake timed out after %ds" % timeout)
        return 124
    finally:
        release()
    print("  waking %s" % sess)
    sys.stdout.flush()
    try:
        r = subprocess.run(cmd, cwd=ROOT, capture_output=True,
                           text=True, encoding="utf-8",
                           errors="replace",
                           timeout=timeout)
        tail = (r.stdout or r.stderr or "").strip().splitlines()
        for ln in tail[-6:]:
            print("    %s" % ln[:150])
        print("  rc=%d" % r.returncode)
        return r.returncode
    except subprocess.TimeoutExpired:
        print("  wake timed out after %ds" % timeout)
        return 124
    finally:
        release()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--status", action="store_true")
    ap.add_argument("--once", action="store_true")
    ap.add_argument("--loop", action="store_true")
    ap.add_argument("--every", type=int, default=240)
    ap.add_argument("--delay", type=int, default=0,
                    help="sleep this long before the first wake")
    ap.add_argument("--timeout", type=int, default=3600)
    ap.add_argument("--prompt", default=None)
    a = ap.parse_args()

    cli = find_cli()
    sess = session_id()

    if a.status:
        print("  cli      : %s" % (cli or "NOT FOUND"))
        print("  session  : %s" % (sess or "NONE"))
        print("  lock held: %s" % ("yes, %.0fs left" % lock_held()
                                   if lock_held() else "no"))
        print("  progress : %s" % progress_line())
        if os.path.exists(STATE):
            print("  state    : %s" % io.open(STATE, encoding="utf-8").read()
                  .strip().replace("\n", " "))
        return 0

    if not cli:
        print("  opencode-cli.exe not found under %APPDATA%\ai.opencode.desktop"
              "\\cli")
        return 1
    if not sess:
        print("  no session id: OPENCODE_SESSION_ID is unset and %s is empty"
              % os.path.relpath(SESSION_FILE, ROOT))
        return 1

    prompt = a.prompt or DEFAULT_PROMPT

    if a.loop:
        print("  waking %s every %ds" % (sess, a.every))
        sys.stdout.flush()
        if a.delay:
            # The first wake is deferred so that launching this from inside a turn
            # does not immediately re-enter the turn that launched it. A wake sent
            # while the agent is still working is the overlap the lock exists to
            # prevent, and the launcher is by definition still working.
            print("  first wake in %ds" % a.delay)
            sys.stdout.flush()
            time.sleep(a.delay)
        while True:
            held = lock_held()
            if held:
                print("  [%s] skipped: a wake is already running (%.0fs left)"
                      % (time.strftime("%H:%M:%S"), held))
                record(skipped=1)
            else:
                before = progress_line()
                rc = wake(cli, sess, prompt, a.timeout)
                # Hold until the woken turn has actually finished before sleeping
                # the interval. Posting on a fixed timer regardless is what let
                # four prompts queue up: each was accepted, none errored, and each
                # queued turn repeated the work of the one before it.
                idle = wait_idle(cli, sess, a.timeout)
                after = progress_line()
                record(last_rc=rc, last_before=before, last_after=after,
                       last_idle=idle)
                print("  [%s] %s -> %s  (idle=%s)"
                      % (time.strftime("%H:%M:%S"), before, after, idle))
            sys.stdout.flush()
            time.sleep(a.every)

    # default: a single wake
    if lock_held():
        print("  skipped: a wake is already running (%.0fs left)" % lock_held())
        return 0
    acquire()
    before = progress_line()
    rc = wake(cli, sess, prompt, a.timeout)
    after = progress_line()
    record(last_rc=rc, last_before=before, last_after=after)
    print("  %s -> %s" % (before, after))
    return 0


if __name__ == "__main__":
    sys.exit(main())