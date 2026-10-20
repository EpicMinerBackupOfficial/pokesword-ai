"""Resolve the project's clang 5.0.1 toolchain directory.

Migrated from Windows to Linux on 2026-10-19.  The compiler version is part of
the *measurement* (see decomp/docs/ceiling.md), so this only ever returns a
5.0.1 install -- never a random clang off PATH.  `tools/match_harness.py`
re-checks the version and fails loudly if it is wrong.

Order: $POKESWORD_CLANG (honoured by the callers), then an existing Linux
install, then the old Windows install, then the Linux path (so error messages
point at where the toolchain should be).
"""
import os

LINUX = os.path.expanduser("~/clang+llvm-5.0.1-x86_64-linux-gnu-debian8/bin")
WINDOWS = "C:" + os.sep + "llvm-5.0.1" + os.sep + "bin"


def default():
    for d in (LINUX, WINDOWS):
        if os.path.isdir(d):
            return d
    return LINUX
