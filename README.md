# RISC-V LLVM Templates
Code templates to get started experimenting with the RISC-V LLVM toolchain.


## Platforms

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

### Spike
- [device tree compiler](https://github.com/dgibson/dtc)
- [frontend server](https://github.com/riscv/riscv-fesvr)
- [isa simulator](https://github.com/riscv/riscv-isa-sim)

### rv8
[rv8](https://github.com/rv8-io/rv8)
