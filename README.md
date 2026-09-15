# ConceptsSelfStudy

Personal self-study project on C++20 Concepts and Constraints, following a
CppCon 2024 talk. Each numbered file is a small, self-contained demo of one
idea, including the "why would this fail" cases - those are real code,
guarded behind `SHOW_COMPILE_ERRORS` (see below) rather than left as comments,
so you can actually see the compiler's own diagnostic instead of a paraphrase.

A few of those error blocks were themselves wrong on the first pass (e.g. a
`T&&` that turned an intended redefinition error into a different, subtler
bug) - caught and fixed by actually compiling them with `make errors` rather
than trusting the comment. Leaving that debugging trail visible is part of
the point of a self-study repo.

## Topics

| # | File | Covers |
|---|------|--------|
| 01 | `Introduction` | Basic `concept`, short concept syntax vs. `requires` clause |
| 02 | `InvalidConcept` | A misspelled requirement, and where the compiler actually reports the error |
| 03 | `Autos` | Abbreviated function templates (`auto` parameters) with concepts and `requires` clauses |
| 04 | `Ranges` | Constraining on `std::ranges::range_value_t` |
| 05 | `MultipleParameters` | Concepts that take more than one template parameter |
| 06 | `MultipleRequirements` | Combining several requirements (and standard concepts) into one |
| 07 | `RequiresRequires` | The `requires requires { ... }` ad-hoc constraint form |
| 08 | `Conditional` | `if constexpr` with a `requires` expression, and constraining `auto` params directly |

`src/ConceptsSelfStudy.cpp` just calls each topic's test functions in order.

## Layout

```
ConceptsSelfStudy.slnx / .vcxproj   Visual Studio solution + project
src/ConceptsSelfStudy.cpp           main()
src/cpp/                            implementation files (01_Introduction.cpp, ...)
src/include/                        headers (01_Introduction.h, ...)
bin/, obj/                          build output (git-ignored)
```

## Building

**Visual Studio**: open `ConceptsSelfStudy.slnx` and build (Debug/Release, x86/x64).

**WSL / Linux** (requires a C++20 compiler, e.g. g++ 11+):

```bash
make        # builds bin/wsl/ConceptsSelfStudy
make run    # builds and runs it
make clean
```

CI (`.github/workflows/build.yml`) builds and runs the project on every push
using the same `Makefile`.

## Seeing the compile errors

Blocks marked `COMPILE ERROR` in the source are real code, wrapped in
`#ifdef SHOW_COMPILE_ERRORS`, so they're excluded from a normal build. To see
the actual compiler diagnostic for all of them:

```bash
make errors
```

This is expected to fail - that's the point. It compiles each file
separately with `-DSHOW_COMPILE_ERRORS -fsyntax-only`, so you get every
file's real error without needing a full/linked build.

Note: within a single file, defining the flag turns on *every* guarded block
in that file (and its header) at once. A couple of files have more than one
guarded block, and in two spots (`01_Introduction`, `03_Autos`) enabling one
block changes which overload gets picked for another call in the same file -
so the specific error you see may not always be the one the nearest comment
describes, though it's always a genuine error from the same underlying
mistake. Comment out the block(s) you're not interested in, or compile with
a per-file flag, to isolate one at a time.
