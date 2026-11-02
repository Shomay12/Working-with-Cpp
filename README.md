<div align="center">

<img src="assets/hero_banner.svg" alt="C++ Systems Engine Header" width="100%" />

<br/>

[![C++ Standard](https://img.shields.io/badge/SPEC-C%2B%2B17%20%2F%20C%2B%2B20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Toolchain](https://img.shields.io/badge/ARCH-Apple_Silicon_ARM64-FF9900?style=for-the-badge&logo=apple&logoColor=white)](https://clang.llvm.org/)
[![Linear Algebra](https://img.shields.io/badge/SIMD_ENGINE-Eigen_3-D00000?style=for-the-badge)](https://eigen.tuxfamily.org/)
[![Target](https://img.shields.io/badge/RUNTIME-CPython_Core_%26_Systems-00F0FF?style=for-the-badge)](https://github.com/Shomay12/Working-with-Cpp)

</div>

---

### LOW-LEVEL SYSTEM OBJECTIVES

High-performance computing and native engine architecture require direct governance over hardware cache lines, memory pages, and pipeline branch prediction.

```text
┌───────────────────────────────────────────────────────────────────────────┐
│ SYSTEM LAYER                MECHANICS UNDER THE HOOD                      │
├───────────────────────────────────────────────────────────────────────────┤
│ Memory Allocations          Stack frame locality vs. Heap fragmentation   │
│ Instruction Pipeline        Branch predictors, cache misses, loop unroll  │
│ Hardware Registers          SIMD vector registers (NEON / AVX-512)        │
│ CPython Virtual Machine     Native C API extensions, PyObject references  │
└───────────────────────────────────────────────────────────────────────────┘
```

---

### HARDWARE LATENCY & CACHE PIPELINE

<div align="center">
  <img src="assets/memory_bus.svg" alt="Hardware Cache Latency Pipeline" width="100%" />
</div>

Direct memory access speed scales drastically depending on where data resides relative to the CPU arithmetic logic units:
* **Registers (L0):** Direct single-cycle instruction execution (~0.3 ns).
* **L1 Data Cache:** Micro-architectural cache hits (~4 cycles).
* **L2/L3 Shared Caches:** Inter-core arbitration (~12 to 40 cycles).
* **Unified Memory (RAM):** Highest latency penalty (~200 cycles) when traversing virtual memory page tables.

---

### COMPILATION & CODEGEN PIPELINE

```mermaid
flowchart TD
    subgraph Frontend ["Front-End Phase"]
        SRC["Source Code Files (.cpp, .hpp)"] --> PRE["Preprocessor: Macro Expansion and Headers"]
        PRE --> LEX["Lexer and Parser: Token Stream to AST Generation"]
    end

    subgraph Middle ["Optimizer Phase (LLVM)"]
        LEX --> IR["LLVM Intermediate Representation (IR)"]
        IR --> OPT["Dead Code Elimination and Loop Vectorization (-O3)"]
    end

    subgraph Backend ["Target Architecture (ARM64)"]
        OPT --> ASM["Assembly Emission (Mach-O ARM64 Instructions)"]
        ASM --> LINK["Linker: Symbol Resolution and Dynamic Libraries"]
        LINK --> ELF["Executable Native Binary"]
    end

    style Frontend fill:#0a0e14,stroke:#00f0ff,stroke-width:1px,color:#00f0ff
    style Middle fill:#0a0e14,stroke:#39ff14,stroke-width:1px,color:#39ff14
    style Backend fill:#0a0e14,stroke:#ff0055,stroke-width:1px,color:#ff0055
    style SRC fill:#161b22,stroke:#30363d,color:#c9d1d9
    style PRE fill:#161b22,stroke:#30363d,color:#c9d1d9
    style LEX fill:#161b22,stroke:#30363d,color:#c9d1d9
    style IR fill:#161b22,stroke:#30363d,color:#c9d1d9
    style OPT fill:#161b22,stroke:#30363d,color:#c9d1d9
    style ASM fill:#161b22,stroke:#30363d,color:#c9d1d9
    style LINK fill:#161b22,stroke:#30363d,color:#c9d1d9
    style ELF fill:#1f6feb,stroke:#58a6ff,stroke-width:2px,color:#ffffff
```

---

### BITSTREAM ARCHITECTURE & MEMORY TOPOLOGY

<div align="center">
  <img src="assets/type_system.svg" alt="Bitstream Architecture and Primitive Layout" width="100%" />
</div>

```mermaid
flowchart TD
    subgraph Virtual_Address_Space ["Virtual Memory Layout (Process Space)"]
        direction TB
        STACK["Stack Segment (Fast, Local Scope, Growth: Downward)"]
        GAP["Unallocated Address Range"]
        HEAP["Heap Segment (Dynamic Allocation, Growth: Upward)"]
        BSS["BSS Segment (Uninitialized Globals and Statics)"]
        DATA["Data Segment (Initialized Globals and Constants)"]
        TEXT["Text Segment (Binary Machine Instructions, Read-Only)"]
        
        STACK --> GAP --> HEAP --> BSS --> DATA --> TEXT
    end

    style Virtual_Address_Space fill:#0d1117,stroke:#30363d,stroke-width:1px,color:#c9d1d9
    style STACK fill:#161b22,stroke:#58a6ff,color:#58a6ff
    style GAP fill:#0d1117,stroke:#21262d,color:#484f58
    style HEAP fill:#161b22,stroke:#ff7b72,color:#ff7b72
    style BSS fill:#161b22,stroke:#d2a8ff,color:#d2a8ff
    style DATA fill:#161b22,stroke:#ffa657,color:#ffa657
    style TEXT fill:#161b22,stroke:#7ee787,color:#7ee787
```

---

### STREAM I/O BUFFER ARCHITECTURE

```mermaid
flowchart LR
    KBD["Keyboard Input"] --> BUF["Standard Input Buffer (stdin)"]
    BUF -->|"cin stream (whitespace delimited)"| VAR1["Variable 1"]
    BUF -->|"getline stream (newline delimited)"| VAR2["Full Line String"]

    style KBD fill:#161b22,stroke:#30363d,color:#c9d1d9
    style BUF fill:#161b22,stroke:#ffa657,stroke-width:2px,color:#ffa657
    style VAR1 fill:#161b22,stroke:#7ee787,color:#7ee787
    style VAR2 fill:#161b22,stroke:#58a6ff,color:#58a6ff
```

---

### REPOSITORY DIRECTORY MATRIX

```plaintext
cpp/
├── assets/
│   ├── hero_banner.svg        # Coded vector HUD with animated scanline
│   ├── memory_bus.svg         # Animated hardware bus data stream
│   └── type_system.svg        # IEEE-754 & binary bit-level map
│
├── code_notes/
│   ├── intro_to_cpp/
│   │   ├── intro.cpp          # Entrypoint mechanics, standard streams
│   │   ├── v2.cpp             # Namespace isolation, Eigen vector math
│   │   ├── cpp_intro.txt      # Clang toolchain, compilation steps
│   │   └── cpp_v2.txt         # Preprocessor mechanics & header linking
│   │
│   ├── 01_varconst/
│   │   ├── v3.cpp             # Const qualifier enforcement, stream chaining
│   │   └── cpp_v3.txt         # Memory state pipeline: Store -> Process -> Display
│   │
│   └── 02_datatype/
│       ├── v4.cpp             # IEEE-754 primitives, memory width verification
│       ├── modifier.cpp       # Signed vs. unsigned bits, integer wrap-around
│       ├── typecasting.cpp    # C-style truncation, std::to_string formatting
│       ├── myString.cpp       # Memory escape sequences (\n, \t, \", \b)
│       ├── user_ip.cpp        # Stream buffer flushing & token extraction
│       └── v4.txt             # Primitive, derived, and user-defined catalog
│
├── .vscode/                   # LSP include paths & settings
├── .clangd                    # Clangd compilation arguments
├── Makefile                   # Deterministic build directives
└── README.md                  # System manual
```

---

### TOOLCHAIN EXECUTION INTERFACE

```text
┌──[ user@arm64-darwin ]─[ ~/ML_CORE/cpp ]
└──$ clang++ -std=c++17 -Wall -Wextra code_notes/02_datatype/user_ip.cpp -o user_ip
└──$ ./user_ip
```

#### Accelerated Linear Algebra (Eigen 3)
```text
┌──[ user@arm64-darwin ]─[ ~/ML_CORE/cpp ]
└──$ clang++ -std=c++17 -I/opt/homebrew/include/eigen3 code_notes/intro_to_cpp/v2.cpp -o v2
└──$ ./v2
  3  -1
2.5 1.5
```

#### Microsecond Execution Profiling
```text
┌──[ user@arm64-darwin ]─[ ~/ML_CORE/cpp ]
└──$ time ./v2
./v2  0.00s user 0.00s system 60% cpu 0.004 total
```

---

### SYSTEM ROADMAP

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
- [ ] High-throughput data structures & memory pooling

---

<div align="center">
<sub>Shomay Singh // Systems Programming & C++ Architecture</sub>
</div>
