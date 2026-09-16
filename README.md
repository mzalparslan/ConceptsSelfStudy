# ConceptsSelfStudy

Self-study project on C++ Concepts and Constraints, following CppCon 2024. Each numbered file is a small demo of presentation page. Code includes compile errors guarded behind `SHOW_COMPILE_ERRORS`.

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
| 09 | `Ambiguties` | Two concepts with no ordering relation between them cause an ambiguous overload |
| 10 | `Subsumption` | Why logically-equivalent concepts aren't necessarily subsumption-equivalent to the compiler; `&&` vs `\|\|` |
| 11 | `SubsumeNotAutomatic` | A concept doesn't automatically subsume another just because it implies it - it has to be composed from it |
| 12 | `ConstraintsForMembers` | Constraining individual member functions of a class template with `requires` |
| 13 | `ConstraintsForNonTypes` | Constraining non-type template parameters (`template <auto Value> requires ...`) |

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

CI (`.github/workflows/build.yml`) builds and runs the project on every push using the same `Makefile`.

## Seeing the compile errors

```bash
make errors
```

This is expected to FAIL. It compiles each file separately with `-DSHOW_COMPILE_ERRORS -fsyntax-only`, so all errors are visible.