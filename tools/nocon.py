"""Every subprocess this project starts INHERITS this project's hidden console.

`import nocon` is one line and it is the counterpart to the hidden console that
`ping_watchdog.py --arm` now creates.

## Why this module exists

The user reported a console window flashing up and vanishing several times a minute,
showing PYTHON. Four wrong answers were given before the right one, and each is
worth keeping because they are the same mistake at different scales:

  1. Counting `conhost.exe` deltas proved windows appeared but not what made them.
     Sampling every few seconds attributed them to `node.exe` and `cmd.exe` -- the
     MCP servers -- because a flashing console is gone before a slow sample sees it.
     **The observer beat the instrument:** the user could see the windows, and they
     said PYTHON.

  2. Fixing three `CREATE_NO_WINDOW` sites changed nothing. Those were the
     long-lived spawns; the flash was the short-lived children.

  3. Testing "does a child from a console-less parent open a window?" said no, and
     was right for the grandchild in that test and wrong about the real case.

  4. Catching one at last -- sampling every 100ms, inside a window's lifetime, and
     naming the OWNER -- gave 37 of 37 identical:

         clang++.exe -cc1 ... -o batch.o -x c++ batch.cpp

## The actual mechanism

`clang++` is a driver: it spawns `clang++ -cc1` to do the compile. That spawn is
made by CLANG, so no Python creation flag can reach it, and `-fintegrated-cc1`
(which would avoid it) does not exist in clang 5.0.1.

    parent python: NO console            <- spawned DETACHED
      -> clang++ inherits NO console
        -> clang++ spawns -cc1
          -> -cc1 has nothing to inherit, so Windows GIVES IT A NEW CONSOLE
            -> THAT IS THE WINDOW

The fix is therefore not "no console". It is a console that EXISTS and is HIDDEN,
created once by `--arm` with CREATE_NEW_CONSOLE | STARTF_USESHOWWINDOW/SW_HIDE, so
that everything down the tree inherits something real:

    A  parent DETACHED (console-less)        new consoles=2   WINDOW
    B  parent CREATE_NEW_CONSOLE + SW_HIDE   new consoles=0   NO WINDOW
    C  parent CREATE_NO_WINDOW (console-less) new consoles=1  WINDOW

(work/hidden_console.py)

## So what does THIS module do?

It must make every child INHERIT that hidden console, which means it must NOT add
DETACHED_PROCESS. A child spawned with no flags inherits the parent's console,
hidden or not; a child spawned DETACHED is handed nothing and breaks the chain for
everything beneath it, including clang's `-cc1`.

The single documented exception is `ping_watchdog.py --arm`, which must CREATE the
console in the first place, and it passes its own flags so this never overrides it.
"""
import os
import subprocess

# Nothing is forced here. The chain root creates a hidden console (see
# ping_watchdog.py --arm); every other process simply must not throw it away.
#
# This module is kept because it is the single place that STATES the contract, and
# because a reader who finds `--arm` spawning CREATE_NEW_CONSOLE needs to know that
# nothing downstream is allowed to strip it again.
CHAIN_ROOT_MUST_NOT_BE_DETACHED = True

def _hidden_si():
    """STARTUPINFO that shows the new console's window as hidden.

    CREATE_NEW_CONSOLE without this still puts a console on screen -- the flag says
    "give it a console", and the STARTUPINFO is what says "do not show it".
    """
    si = subprocess.STARTUPINFO()
    si.dwFlags |= subprocess.STARTF_USESHOWWINDOW
    si.wShowWindow = 0                      # SW_HIDE
    return si


# Used by ping_watchdog.py --arm only. Defined AFTER _hidden_si, because the first
# version of this file evaluated it above the function and every tool that imports
# nocon died with NameError at import time -- which is the worst possible failure
# mode for a module whose entire job is to be imported by everything.
HIDDEN_CONSOLE_FLAGS = (
    {"creationflags": subprocess.CREATE_NEW_CONSOLE,
     "startupinfo": _hidden_si()} if os.name == "nt" else {})