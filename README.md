<div align="center">

```text
  ██████╗ ██████╗ ██████╗     ███╗   ███╗██╗          ██████╗ ██████╗ ██████╗ ███████╗
 ██╔════╝██╔══██╗██╔══██╗    ████╗ ████║██║         ██╔════╝██╔═══██╗██╔══██╗██╔════╝
 ██║     ██████╔╝██████╔╝    ██╔████╔██║██║         ██║     ██║   ██║██████╔╝█████╗  
 ██║     ██╔═══╝ ██╔═══╝     ██║╚██╔╝██║██║         ██║     ██║   ██║██╔══██╗██╔══╝  
 ╚██████╗██║     ██║         ██║ ╚═╝ ██║███████╗    ╚██████╗╚██████╔╝██║  ██║███████╗
  ╚═════╝╚═╝     ╚═╝         ╚═╝     ╚═╝╚══════╝     ╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝
```

<img src="https://readme-typing-svg.demolab.com?font=JetBrains+Mono&weight=700&size=19&duration=2500&pause=1000&color=00F0FF&center=true&vCenter=true&width=700&lines=%24+clang%2B%2B+-O3+-std%3Dc%2B%2B20+-march%3Dnative;SYSTEMS+PROGRAMMING+%7C+BARE+METAL+TO+TENSORS;REVERSE-ENGINEERING+CPYTHON+AND+INFERENCE+RUNTIMES;DIRECT+MEMORY+ALLOCATION.+ZERO+GARBAGE+COLLECTION." alt="Terminal Output" />

<br/>

[![C++ Standard](https://img.shields.io/badge/C%2B%2B-17%20%7C%2020-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Toolchain](https://img.shields.io/badge/TOOLCHAIN-Apple_Clang_ARM64-FF9900?style=for-the-badge&logo=apple&logoColor=white)](https://clang.llvm.org/)
[![Linear Algebra](https://img.shields.io/badge/MATH_ENGINE-Eigen_3-D00000?style=for-the-badge)](https://eigen.tuxfamily.org/)
[![Target](https://img.shields.io/badge/TARGET-CPython_Core_%26_Inference-00F0FF?style=for-the-badge)](https://github.com/Shomay12/Working-with-Cpp)

</div>

---

### ARCHITECTURAL OBJECTIVE

High-performance computing, neural runtime execution, and tensor mathematics demand unmediated control over hardware memory hierarchies, cache alignment, and instruction throughput.

This repository tracks the systematic breakdown and reconstruction of low-level systems programming in C++:
* **Hardware Memory Mechanics:** Pointer arithmetic, stack vs. heap allocation, memory alignment, cache spatial/temporal locality.
* **CPython Execution Layer:** Demystifying CPython object models (`PyObject`), reference counting, and high-throughput C/C++ extension bindings.
* **Tensor & Inference Runtimes:** Constructing custom SIMD-optimized linear algebra operations, GEMM kernels, and compute graphs from first principles.

---

### COMPILATION PIPELINE

```mermaid
flowchart LR
    A["Source Code (.cpp)"] --> B["Clang Preprocessor"]
    B --> C["LLVM Clang Compiler"]
    C --> D["Target Code Optimization (ARM64)"]
    D --> E["Linker (Mach-O Binary)"]
    
    style A fill:#0d1117,stroke:#30363d,stroke-width:2px,color:#58a6ff
    style B fill:#0d1117,stroke:#30363d,stroke-width:2px,color:#7ee787
    style C fill:#0d1117,stroke:#30363d,stroke-width:2px,color:#ffa657
    style D fill:#0d1117,stroke:#30363d,stroke-width:2px,color:#d2a8ff
    style E fill:#0d1117,stroke:#238636,stroke-width:2px,color:#3fb950
```

---

### REPOSITORY MATRIX

```plaintext
cpp/
├── code_notes/
│   ├── intro_to_cpp/
│   │   ├── intro.cpp          # I/O streams and runtime entrypoints
│   │   ├── v2.cpp             # Namespace isolation, Eigen matrix allocations
│   │   ├── cpp_intro.txt      # Compilation stages & architecture notes
│   │   └── cpp_v2.txt         # Linker & header resolution mechanics
│   │
│   ├── 01_varconst/
│   │   ├── v3.cpp             # Memory immutability, const semantics, stream routing
│   │   └── cpp_v3.txt         # Memory lifecycle: Allocation -> Mutation -> Sink
│   │
│   └── 02_datatype/
│       ├── v4.cpp             # IEEE-754 floats, integer representations
│       ├── modifier.cpp       # Signed vs. unsigned bits, integer wrap-around & underflow
│       ├── typecasting.cpp    # Explicit C-style casting, numeric string serialization
│       ├── myString.cpp       # Byte sequences, escape control characters
│       ├── user_ip.cpp        # Stream buffering: cin vs. getline
│       └── v4.txt             # Primitive, derived, and user-defined type definitions
│
├── .vscode/                   # LSP & include path configurations
├── .clangd                    # Clangd flags (-I/opt/homebrew/include/eigen3)
├── Makefile                   # Deterministic build directives
└── README.md                  # System architecture manual
```

---

### MEMORY & TYPE TOPOLOGY

```mermaid
graph TD
    subgraph Data_Types ["Data Type Hierarchy"]
        direction TB
        ROOT["Data Types"]
        PRIM["Primitive Types<br/>bool (1B) | char (1B) | int (4B) | float (4B) | double (8B)"]
        DERIV["Derived Types<br/>Arrays | Functions | Pointers (*) | References (&)"]
        USER["User-Defined Types<br/>struct | class | union | enum | typedef"]
        
        ROOT --> PRIM
        ROOT --> DERIV
        ROOT --> USER
    end

    style Data_Types fill:#0d1117,stroke:#30363d,stroke-width:1px,color:#c9d1d9
    style ROOT fill:#161b22,stroke:#58a6ff,stroke-width:2px,color:#58a6ff
    style PRIM fill:#161b22,stroke:#7ee787,stroke-width:1px,color:#7ee787
    style DERIV fill:#161b22,stroke:#ffa657,stroke-width:1px,color:#ffa657
    style USER fill:#161b22,stroke:#d2a8ff,stroke-width:1px,color:#d2a8ff
```

#### Core Hardware & Language Mechanics
* **Bit Widths & Modifiers:** `unsigned int` shifts the signed integer range $[-2^{31}, 2^{31}-1]$ strictly positive $[0, 2^{32}-1]$. Supplying negative literals directly invokes two's complement modulo wrap-around (`-100` becomes `4294967196`).
* **Immutability Contract:** `const` qualifiers enforce compile-time read-only storage and must be initialized at definition site.
* **Vector Math (Eigen 3):** SIMD-vectorized matrix operations executed without heap overhead via header-only template specialization.

---

### TOOLCHAIN COMMANDS

#### Native Binary Compilation
```zsh
clang++ -std=c++17 -Wall -Wextra code_notes/02_datatype/user_ip.cpp -o user_ip
./user_ip
```

#### Linear Algebra Target (Eigen Integration)
```zsh
clang++ -std=c++17 -I/opt/homebrew/include/eigen3 code_notes/intro_to_cpp/v2.cpp -o v2
./v2
```

#### CPU Cycle Instrumentation
```zsh
time ./v2
```

---

### EXECUTION ROADMAP

- [x] Compilation pipeline, namespaces, and standard stream buffers
- [x] Const correctness, immutability, and stream routing
- [x] Memory layout analysis across 32-bit and 64-bit primitive types
- [x] Two's complement integer wrap-around & underflow analysis
- [x] Typecasting, explicit conversions, and string serializations
- [x] Header-only SIMD matrix math integration (Eigen 3)
- [ ] Control flow optimizations & branch prediction mechanics
- [ ] Direct heap allocation, pointers, references, and pointer arithmetic
- [ ] Cache-coherent structures (Struct of Arrays vs. Array of Structs)
- [ ] CPython C-API bindings & native extension loading
- [ ] Custom lightweight tensor computation engine

---

<div align="center">
<sub>Shomay Singh // Machine Learning Core & Systems Research</sub>
</div>
