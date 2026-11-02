<div align="center">

![C++ Systems Engine](assets/banner.svg)

<br/>

[![C++](https://img.shields.io/badge/SPEC-C%2B%2B17%20%2F%2020-ff003c?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Toolchain](https://img.shields.io/badge/ARCH-Apple_Silicon_ARM64-d50000?style=for-the-badge&logo=apple&logoColor=white)](https://clang.llvm.org/)
[![Math Engine](https://img.shields.io/badge/MATH_ENGINE-Eigen_3-880e4f?style=for-the-badge)](https://eigen.tuxfamily.org/)
[![Target](https://img.shields.io/badge/RUNTIME-CPython_Core_%26_Systems-b71c1c?style=for-the-badge)](https://github.com/Shomay12/Working-with-Cpp)

</div>

---

## 1. HARDWARE CACHE & MEMORY ACCESS PIPELINE

<div align="center">

![Hardware Cache Latency Pipeline](assets/cache_hierarchy.svg)

</div>

---

## 2. LLVM CLANG CODEGEN & COMPILATION PIPELINE

<div align="center">

![LLVM Compilation Pipeline](assets/compilation_pipeline.svg)

</div>

---

## 3. C++ TYPE SYSTEM & MEMORY SPECIFICATIONS

<div align="center">

![C++ Type System Matrix](assets/type_matrix.svg)

</div>

---

## 4. VIRTUAL MEMORY PROCESS TOPOLOGY

```mermaid
flowchart TD
    subgraph Process_Address_Space ["Virtual Address Space Layout"]
        direction TB
        STACK["Stack Segment: Local scope, downward growth towards heap"]
        GAP["Unmapped Virtual Page Boundary"]
        HEAP["Heap Segment: Dynamic allocations, upward growth"]
        BSS["BSS Segment: Uninitialized global and static variables"]
        DATA["Data Segment: Initialized global and constant variables"]
        TEXT["Text Segment: Compiled binary machine instructions (Read-Only)"]
        
        STACK --> GAP --> HEAP --> BSS --> DATA --> TEXT
    end

    style Process_Address_Space fill:#140205,stroke:#4a0b14,stroke-width:1.5px,color:#ff8da1
    style STACK fill:#33060e,stroke:#ff1744,stroke-width:2px,color:#ffffff
    style GAP fill:#0a0103,stroke:#24050b,color:#59131f
    style HEAP fill:#2d060e,stroke:#ff003c,stroke-width:2px,color:#ffffff
    style BSS fill:#24050b,stroke:#d50000,color:#ffcdd2
    style DATA fill:#1a0307,stroke:#b71c1c,color:#ff8da1
    style TEXT fill:#140205,stroke:#880e4f,color:#ff5252
```

---

## 5. STREAM I/O BUFFER HANDLING

```mermaid
flowchart LR
    KBD["Terminal Input"] --> BUF["Standard Input Buffer (stdin)"]
    BUF -->|"cin >> token"| T1["Reads contiguous word, stops at whitespace"]
    BUF -->|"getline(cin, str)"| T2["Extracts full line through newline delimiter"]

    style KBD fill:#1f0409,stroke:#ff1744,stroke-width:1.5px,color:#ffffff
    style BUF fill:#33060e,stroke:#ff003c,stroke-width:2px,color:#ffcdd2
    style T1 fill:#24050b,stroke:#d50000,stroke-width:1.5px,color:#ff8da1
    style T2 fill:#3d0811,stroke:#ff003c,stroke-width:2px,color:#ffffff
```

---

## 6. REPOSITORY CODE MATRIX

```plaintext
cpp/
├── assets/
│   ├── banner.svg             # Animated vector red-theme header
│   ├── cache_hierarchy.svg    # Animated hardware cache latency pipeline
│   ├── compilation_pipeline.svg # Animated LLVM compilation flow
│   └── type_matrix.svg        # Graphical type system matrix & underflow map
│
├── code_notes/
│   ├── intro_to_cpp/
│   │   ├── intro.cpp          # Entrypoint structure and stream output
│   │   ├── v2.cpp             # Namespace partitioning and Eigen matrix math
│   │   ├── cpp_intro.txt      # Compilation stages, language background
│   │   └── cpp_v2.txt         # Linker mechanics and header inclusion
│   │
│   ├── 01_varconst/
│   │   ├── v3.cpp             # Const immutability and stream concatenation
│   │   └── cpp_v3.txt         # Memory lifecycle: Store -> Process -> Display
│   │
│   └── 02_datatype/
│       ├── v4.cpp             # Primitive variable allocation
│       ├── modifier.cpp       # Signed vs. unsigned bits and underflow
│       ├── typecasting.cpp    # Explicit truncation and string conversion
│       ├── myString.cpp       # Escape control characters (\n, \t, \", \b)
│       ├── user_ip.cpp        # Stream buffering: cin vs. getline
│       └── v4.txt             # Primitive, derived, and user-defined catalog
│
├── .vscode/                   # Editor include paths
├── .clangd                    # Clangd compilation flags
├── Makefile                   # Build directives
└── README.md                  # Documentation
```

---

## 7. TOOLCHAIN COMMANDS

### Standard Compilation
```zsh
clang++ -std=c++17 -Wall -Wextra code_notes/02_datatype/user_ip.cpp -o user_ip
./user_ip
```

### Linear Algebra Target (Eigen 3 Integration)
```zsh
clang++ -std=c++17 -I/opt/homebrew/include/eigen3 code_notes/intro_to_cpp/v2.cpp -o v2
./v2
```

### Process CPU Time Profiling
```zsh
time ./v2
```

---

## 8. PROGRESS TRACKER

- [x] Preprocessor directives, namespaces, and main function entrypoints
- [x] Variable declaration, mutation, and `const` immutability
- [x] Stream output (`cout <<`), format chaining, and avoiding pointer math bugs
- [x] Primitive types, bit widths, and IEEE-754 float precision
- [x] Integer modifiers (`signed`, `unsigned`, `long`, `short`) and underflow
- [x] Explicit type conversion (`(int)x`) and string serialization (`to_string`)
- [x] Escape sequences (`\n`, `\t`, `\"`, `\b`) and string operations
- [x] Input streams: token reading (`cin >>`) vs line reading (`getline`)
- [x] Third-party header-only integration: Eigen 3 for linear algebra
- [ ] Conditionals, logical operators, and switch statements
- [ ] Loops (`for`, `while`, `do-while`) and iteration performance
- [ ] Pointers, memory addresses (`&`), dereferencing (`*`), and pointer arithmetic
- [ ] Dynamic memory allocation (`new`, `delete`) and heap management
- [ ] Structs, classes, access specifiers, and object lifecycles

---

Shomay Singh
