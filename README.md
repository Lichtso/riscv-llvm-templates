# RISC-V LLVM Templates
This repo is similar to [riscv-probe](https://github.com/michaeljclark/riscv-probe) but utilizes the LLVM toolchain instead of the GNU toolchain.

## Contains
- Makefile
    - LLVM invocations
- Linker Script
    - Virtual memory map
    - Layout of the executable
- Assembly
    - Setting the stack pointer
    - Calling main()
    - Calling exit()
- C
    - Minimal host / target interface
    - Classical "Hello World!"

## Usage
Set the LLVM and RISCV environment variables if you haven't installed the prerequisites at their defaults.
- `make` to build all targets
- `make clean` to delete all targets
- To show the targets disassembly, sections, symbols, etc:
    - `make dump.spike`
    - `make dump.rv8`
- To run it:
    - `make run.spike`
    - `make run.qemu`
    - `make run.rv8`

## Prerequisites
You will need this repo, the llvm toolchain compiled with the experimental RISC-V target and at least one of the three simulators / emulators listed below.

### LLVM
```
git clone https://git.llvm.org/git/llvm.git
cd llvm/tools
git clone https://git.llvm.org/git/clang.git
git clone https://git.llvm.org/git/lld.git
cd ../..
mv llvm llvmSrc
mkdir llvm
cd llvm
cmake -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD="RISCV" -DLLVM_LINK_LLVM_DYLIB=ON ../llvmSrc/
make -j8 clang llc lld llvm-objdump llvm-readobj
```

### Simulators / Emulators
- Spike
    - [device tree compiler](https://github.com/dgibson/dtc)
    - [frontend server](https://github.com/riscv/riscv-fesvr)
    - [isa simulator](https://github.com/riscv/riscv-isa-sim)
- [qemu](https://github.com/riscv/riscv-qemu.git)
- [rv8](https://github.com/rv8-io/rv8)
