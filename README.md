# 🚀 Working with C++ (ML Core & Systems Journey)

[![Language: C++](https://img.shields.io/badge/Language-C%2B%2B17%20%2F%20C%2B%2B20-blue.svg)](https://isocpp.org/)
[![Compiler: Apple Clang](https://img.shields.io/badge/Compiler-Apple%20Clang-orange.svg)](https://clang.llvm.org/)
[![Libraries: Eigen](https://img.shields.io/badge/Libraries-Eigen%203-red.svg)](https://eigen.tuxfamily.org/)
[![Focus: ML Core & CPython](https://img.shields.io/badge/Focus-Systems%20%7C%20ML%20Core%20%7C%20Inference-green.svg)](#motivation)

Welcome to my C++ learning journey! This repository documents my hands-on exploration of C++, from system-level fundamentals, memory layout, and compiler internals to linear algebra libraries (Eigen) and high-performance computing.

---

## 🎯 Motivation & Goals

> *"To master machine learning from first principles, you must understand the engine beneath the hood."*

My goal with this repository is to build deep foundational knowledge in C++ to eventually:
- **Understand CPython Internals & Extensions:** Dive into Python's C runtime and write native C/C++ extensions.
- **Build Custom ML Inference Engines:** Understand how frameworks like PyTorch, TensorFlow, and ONNX Runtime execute tensor math at hardware-level efficiency.
- **Master Direct Memory Management:** Harness raw pointers, cache locality, and explicit resource management without relying on garbage collection.

---

## 📂 Repository Structure

```plaintext
.
├── code_notes/
│   ├── intro_to_cpp/          # Foundations, compiler flow, namespaces & Eigen demo
│   │   ├── intro.cpp          # Classic Hello World & standard I/O
│   │   ├── v2.cpp             # Custom namespaces, standard streams & Eigen matrices
│   │   ├── cpp_intro.txt      # Core concepts: why C++, compilation stages, father of C++
│   │   └── cpp_v2.txt         # Namespaces, directives & header mechanics
│   │
│   ├── 01_varconst/           # Variables, immutability & memory representation
│   │   ├── v3.cpp             # Variables, const correctness, string formatting
│   │   └── cpp_v3.txt         # Data pipeline: Store -> Process -> Display
│   │
│   └── 02_datatype/           # Type system breakdown
│       └── v4.txt             # Primitive, Derived & User-Defined types with memory sizes
│
├── .vscode/                   # IDE IntelliSense and include paths configuration
├── .clangd                    # Clangd language server compiler flags
├── Makefile                   # Fast build configurations
└── README.md                  # Project overview and notes
```

---

## 🧠 Topics & Key Takeaways

### 1. Introduction & Compilation Flow
- **Compilation Model:** `Source Code (.cpp)` ➔ `Pre-processing` ➔ `Compilation (Clang)` ➔ `Assembly / Object Code` ➔ `Linker` ➔ `Native Binary`.
- **Pre-processor Directives:** `#include <iostream>`, `#include <Eigen/Dense>`.
- **Namespaces:** Isolating scope using `namespace myName { ... }` and avoiding name clashing (`using namespace std;`).

### 2. Variables & Constants (`const`)
- **Variables vs. Constants:** Why `const` variables must be initialized at definition time and cannot be reassigned.
- **String Formatting & I/O:** Using stream insertion `<<` versus pointer arithmetic pitfalls (`"string" + int`).

### 3. Data Types & Memory Sizes
| Category | Types | Typical Size (bytes) | Description |
| :--- | :--- | :--- | :--- |
| **Primitive** | `bool`, `char`, `int`, `float`, `double`, `void` | 1 to 8 bytes | Fundamental types built directly into the language |
| **Derived** | Arrays, Functions, Pointers (`*`), References (`&`) | Architecture dependent | Types constructed from primitive foundations |
| **User-Defined** | `struct`, `class`, `union`, `enum`, `typedef` | Custom footprint | Custom data structures designed by the developer |

### 4. Linear Algebra & Numerical Computing (Eigen 3)
- Integrating header-only linear algebra libraries for matrix multiplications and vector transformations.
- Setting up compiler include paths (`-I/opt/homebrew/include/eigen3`).

---

## 🛠️ How to Compile & Run

### Standard Compilation
Using `clang++` (macOS / Linux):

```zsh
# Compile and run a basic file:
clang++ code_notes/intro_to_cpp/intro.cpp -o intro && ./intro
```

### Compiling with External Libraries (e.g. Eigen)
Because Eigen is installed via Homebrew (`/opt/homebrew/include/eigen3`), provide the include path with `-I`:

```zsh
clang++ -I/opt/homebrew/include/eigen3 code_notes/intro_to_cpp/v2.cpp -o v2 && ./v2
```

> **Tip:** To avoid typing `-I...` every time, export it to your shell environment:
> ```zsh
> export CPLUS_INCLUDE_PATH="/opt/homebrew/include/eigen3:$CPLUS_INCLUDE_PATH"
> ```

---

## 🗺️ Learning Roadmap

- [x] C++ Basics, Compilation & Namespaces
- [x] Variables, `const` semantics & Stream I/O
- [x] Data Types & Memory Footprint Analysis
- [x] Third-party Library Integration (Eigen 3)
- [ ] Control Flow, Loops & Functions
- [ ] Pointers, References & Dynamic Memory (`new`/`delete`)
- [ ] Object-Oriented Programming (Classes, Inheritance, Polymorphism)
- [ ] Modern C++ (Smart Pointers, Lambdas, Move Semantics, RAII)
- [ ] CPython C-API / Pybind11 Integration
- [ ] Custom Matrix & Tensor Engine from scratch

---

## 👤 Author
**Shomay Singh**  
Exploring Machine Learning Core, Systems Programming & C++.
