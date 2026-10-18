#!/usr/bin/env python3
"""Find names a function reads but nothing in scope defines.

`py_compile` cannot see this class of bug. It resolves names at RUNTIME, so a
function that reads a name it does not have compiles clean, imports clean, and
fails the first time that line executes -- and if the line is inside a broad
`except`, it fails forever without anyone noticing.

That is not hypothetical. `tools/ping_watchdog.py` had

    time.sleep(min(5, max(1, interval)))          # `interval` is not a parameter

inside `supervise`, whose docstring says "Nothing in here may raise". The
NameError fired on every cycle of the inner wait loop, the except swallowed it,
and the watchdog spent 6,065 restarts churning tier-2 pids while reporting itself
healthy and the ping chain below went stale for 3.5 days.

This is a scope check, not a type check: it collects every name a function can
see (its parameters, its own assignments and nested defs, the module's globals,
builtins) and reports the loads that are in none of them.

    python tools/undefined_names.py
    python tools/undefined_names.py --path tools/ping_watchdog.py
"""

import argparse
import ast
import builtins
import io
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def module_names(tree):
    """Every name bound at module scope."""
    out = set()
    for node in tree.body:
        if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef, ast.ClassDef)):
            out.add(node.name)
        elif isinstance(node, (ast.Import, ast.ImportFrom)):
            for a in node.names:
                out.add((a.asname or a.name).split(".")[0])
        elif isinstance(node, ast.Assign):
            for t in node.targets:
                for n in ast.walk(t):
                    if isinstance(n, ast.Name):
                        out.add(n.id)
        elif isinstance(node, ast.AnnAssign) and isinstance(node.target, ast.Name):
            out.add(node.target.id)
        elif isinstance(node, (ast.For, ast.While, ast.If, ast.With)):
            # `for x in ...:` at module level binds x for the rest of the module.
            for sub in ast.walk(node):
                if isinstance(sub, ast.Name) and isinstance(sub.ctx, ast.Store):
                    out.add(sub.id)
    return out


def function_names(node):
    """Every name this function (and its nested defs) can read."""
    seen = []

    def walk(fn, bound):
        args = fn.args
        for a in list(args.posonlyargs) + list(args.args) + list(args.kwonlyargs):
            bound.add(a.arg)
        if args.vararg:
            bound.add(args.vararg.arg)
        if args.kwarg:
            bound.add(args.kwarg.arg)
        body_bound = set(bound)
        # Pre-pass: every name assigned ANYWHERE in the body counts as bound, so
        # use-before-assignment inside a branch is not reported. That is a
        # different (rarer) bug and this tool is about names with no binding at
        # all.
        for sub in ast.walk(fn):
            if sub is fn:
                continue
            if isinstance(sub, ast.Name) and isinstance(sub.ctx, (ast.Store, ast.Del)):
                body_bound.add(sub.id)
            if isinstance(sub, (ast.FunctionDef, ast.AsyncFunctionDef, ast.ClassDef)):
                body_bound.add(sub.name)
            if isinstance(sub, ast.ExceptHandler) and sub.name:
                body_bound.add(sub.name)
            if isinstance(sub, (ast.Import, ast.ImportFrom)):
                for a in sub.names:
                    body_bound.add((a.asname or a.name).split(".")[0])
            if isinstance(sub, ast.Global):
                body_bound.update(sub.names)
            if isinstance(sub, ast.Nonlocal):
                body_bound.update(sub.names)
            if isinstance(sub, ast.Lambda):
                for a in (list(sub.args.posonlyargs) + list(sub.args.args)
                          + list(sub.args.kwonlyargs)):
                    body_bound.add(a.arg)
            # Only the comprehension forms have a `.target`. A `GeneratorExp` does
            # not -- `(x for x in y)` -- and walking it as if it did is an
            # AttributeError in the checker, which is a poor advertisement for a
            # tool whose whole job is to find things other tools miss.
            if isinstance(sub, (ast.ListComp, ast.SetComp, ast.DictComp)) \
                    and hasattr(sub, "target"):
                for n in ast.walk(sub.target):
                    if isinstance(n, ast.Name):
                        body_bound.add(n.id)
        seen.append((fn, body_bound))
        for sub in ast.walk(fn):
            if isinstance(sub, (ast.FunctionDef, ast.AsyncFunctionDef)) and sub is not fn:
                walk(sub, body_bound)

    walk(node, set())
    return seen


def check(path):
    try:
        tree = ast.parse(io.open(path, encoding="utf-8").read())
    except SyntaxError as e:
        return [("%s: SyntaxError: %s" % (path, e), 0)]
    globals_ = module_names(tree) | set(dir(builtins)) | {
        "__name__", "__file__", "__doc__", "__spec__", "__package__", "__builtins__"}
    bad = []
    # Only TOP-LEVEL functions. A nested def closes over its enclosing scope, and
    # `function_names` already walks into nested defs with the parent's bindings --
    # so calling it again for each one `ast.walk(tree)` happens to find checks the
    # same code with the enclosing scope MISSING, and every closure variable comes
    # back as an undefined name. That was 20+ false positives before this line.
    for node in tree.body:
        if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)):
            for fn, bound in function_names(node):
                for sub in ast.walk(fn):
                    if sub is fn:
                        continue
                    if isinstance(sub, ast.Name) and isinstance(sub.ctx, ast.Load):
                        if sub.id not in bound and sub.id not in globals_:
                            bad.append(("%s: %s() reads '%s'"
                                        % (path, fn.name, sub.id), sub.lineno))
    return bad


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--path", default=None)
    a = ap.parse_args()

    paths = [a.path] if a.path else [
        os.path.join(ROOT, "tools", f) for f in sorted(os.listdir(
            os.path.join(ROOT, "tools"))) if f.endswith(".py")]
    bad = []
    for p in paths:
        bad.extend(check(p))
    # A SET, deduped by message text. This was a list, because a blanket search
    # and replace for an unhashable-tuple crash earlier in this file also replaced
    # this one -- and the tool crashed on every invocation with
    # `'list' object has no attribute 'add'`, which is not a useful advertisement
    # for a tool whose whole purpose is finding things other tools miss.
    seen = set()
    for msg, line in bad:
        if msg in seen:
            continue
        seen.add(msg)
        print("  %s" % msg)
    print("")
    print("  %d distinct undefined name(s) across %d file(s)"
          % (len(seen), len(paths)))
    return 1 if seen else 0


if __name__ == "__main__":
    sys.exit(main())