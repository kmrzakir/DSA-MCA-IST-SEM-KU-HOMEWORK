# Copilot instructions for this repository

## Project shape

This repository is a collection of standalone C++ data-structure and algorithm exercises, not a single application with a shared library or service layer. Each `.cpp` file is effectively its own mini-program and is usually self-contained.

Examples in the repo include:
- `main.cpp` for a small entry-point exercise
- `MaxHeap.cpp` for heap operations
- `Graph.cpp` for adjacency-matrix / adjacency-list graph work
- `Deque.cpp` for deque behavior
- `Hloo.cpp` and `ll-delte-count-display.cpp` for linked-list practice

Key implication: do not assume cross-file imports or a global project architecture. Most edits target one source file at a time and should be validated by compiling that file directly.

## Build, test, and validation commands

There is no Makefile, CMake project, or package manifest in this repository. Validation is done by compiling the relevant C++ source file with `g++` and then running the executable.

Typical commands:

```bash
# compile one exercise
 g++ -std=c++17 -Wall -Wextra -pedantic -o maxheap MaxHeap.cpp
 ./maxheap

# compile and run a different exercise
 g++ -std=c++17 -Wall -Wextra -pedantic -o graph Graph.cpp
 ./graph

# compile and run a deque sample
 g++ -std=c++17 -Wall -Wextra -pedantic -o deque Deque.cpp
 ./deque
```

For a single-file check, compile only the target file you changed rather than trying to validate the whole repository. `-Wall -Wextra -pedantic` acts as the de facto lint/quality pass for this project.

## Architecture and conventions

- The codebase is assignment-style C++ rather than production software: files are small, imperative, and use direct console I/O.
- Common patterns in the existing code include:
  - `main()` functions that prompt for input interactively
  - raw pointer-based linked-list / tree structures
  - direct `cout`/`cin` usage with `using namespace std;`
  - class-based data structures (`MaxHeap`, `Deque`, `Graph`) that are intended to be used as standalone demos
- Each file tends to be complete in itself; there is no central model, service, or shared utility layer to follow.
- When editing, prefer keeping the style consistent with the local file: simple C++ classes, minimal abstractions, and straightforward procedural flow rather than introducing framework-style patterns or project-wide infrastructure.

## Working style for future sessions

- Start by identifying which exercise file is relevant to the task; do not assume features are shared across files.
- If you change a specific implementation, validate it with a targeted compile/run command for that file.
- Keep fixes local to the relevant source file unless the task explicitly spans multiple exercises.
- Preserve the repo’s educational / classroom tone: compact, readable implementations with explicit data-structure logic over polished abstractions.

## Notes from the repository docs

The root `README.md` is intentionally minimal, so the practical source of truth is the code itself. This repository does not define a broader project workflow beyond compiling and running individual C++ programs.
