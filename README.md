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
│   └── 02_datatype/           # Type system, modifiers, casting & user input
│       ├── v4.cpp             # Primitive types (int, float, double, char, bool)
│       ├── modifier.cpp       # Modifiers (unsigned, long) & underflow/wrap-around
│       ├── typecasting.cpp    # Explicit C-style casting & to_string() conversions
│       ├── myString.cpp       # std::string mechanics & escape sequences (\n, \t, \")
│       ├── user_ip.cpp        # User input handling: cin >> and getline()
│       └── v4.txt             # Deep dive: Primitive, Derived & User-Defined types
│
├── .vscode/                   # IDE IntelliSense and include paths configuration
├── .clangd                    # Clangd language server compiler flags
├── Makefile                   # Fast build configurations
└── README.md                  # Project documentation & notes
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

### 3. Data Types & Type System
| Category | Types | Typical Size | Description |
| :--- | :--- | :--- | :--- |
| **Primitive** | `bool`, `char`, `short`, `int`, `long`, `float`, `double`, `void` | 1 to 8 bytes | Fundamental types built directly into the language |
| **Derived** | Arrays, Functions, Pointers (`*`), References (`&`) | Architecture dependent | Types constructed from primitive foundations |
| **User-Defined** | `struct`, `class`, `union`, `enum`, `typedef` | Custom footprint | Custom data structures designed by the developer |

- **Type Modifiers (`unsigned`, `long`, `short`):**
  - `unsigned int`: Restricts values to non-negative numbers, doubling the positive range ($0$ to $4{,}294{,}967{,}295$). Passing a negative value causes integer underflow / wrap-around (e.g. `-100` becomes `4294967196`).
  - `long` / `long long`: Extends the integer capacity to represent large datasets.
- **Type Casting & Conversions:**
  - Explicit C-style cast: `(int)priceOfTea` truncates decimal fractions.
  - String conversions: `std::to_string(value)` for converting numerical values into concatenable strings.
- **Strings & Escape Sequences:**
  - Special characters: `\n` (newline), `\t` (tab), `\"` / `\'` (escaped quotes), `\b` (backspace).
- **User Input & Stream Handling:**
  - `cin >> var`: Reads single tokens separated by whitespace.
  - `getline(cin, str)`: Reads full lines including spaces (essential for full names or multi-word sentences).

### 4. Linear Algebra & Numerical Computing (Eigen 3)
- Integrating header-only linear algebra libraries for matrix multiplications and vector transformations.
- Setting up compiler include paths (`-I/opt/homebrew/include/eigen3`).

---

## 🛠️ How to Compile & Run

### Standard Compilation
Using `clang++` (macOS / Linux):

```zsh
# Compile and run any program:
clang++ code_notes/02_datatype/user_ip.cpp -o user_ip && ./user_ip
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
- [x] Type Modifiers (`unsigned`, `long`) & Underflow Behavior
- [x] Type Casting & String Conversions (`to_string`)
- [x] Strings, Escape Sequences & User Input (`cin`, `getline`)
- [x] Third-party Library Integration (Eigen 3)
- [ ] Control Flow, Conditionals & Loops
- [ ] Functions, Overloading & Scope
- [ ] Pointers, References & Dynamic Memory (`new`/`delete`)
- [ ] Object-Oriented Programming (Classes, Inheritance, Polymorphism)
- [ ] Modern C++ (Smart Pointers, Lambdas, Move Semantics, RAII)
- [ ] CPython C-API / Pybind11 Integration
- [ ] Custom Matrix & Tensor Engine from scratch

---

## 👤 Author
**Shomay Singh**  
Exploring Machine Learning Core, Systems Programming & C++.
