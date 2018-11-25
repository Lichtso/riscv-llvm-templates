CFLAGS = -target riscv32-unknown-elf -march=rv32imafdc -O1 -I include


all: build/target_spike build/target_rv8

clean:
	rm -rf build/

dump.spike: build/target_spike
	$(LLVM)llvm-objdump -mattr=m,a,f,d,c -disassemble -t -all-headers $<

dump.rv8: build/target_rv8
	$(RISCV)rv-bin dump -s -p -t -d $<

run.spike: build/target_spike
	$(RISCV)spike --isa=RV32IMAFDC +rfb $<

run.qemu: build/target_spike
	$(RISCV)qemu-system-riscv32 -nographic -machine spike_v1.10 -kernel $<

run.rv8: build/target_rv8
	$(RISCV)rv-sim $< TARGET=riscv32-unknown-elf ARCH=rv32imafdc

.PHONY: all clean dump.spike dump.rv8 run.spike run.qemu run.rv8

build/:
	mkdir -p build

build/%.o: src/%.s | build/
	$(LLVM)clang $(CFLAGS) -c -o $@ $<

build/%.o: src/%.c include/* | build/
	$(LLVM)clang $(CFLAGS) -c -o $@ $<

build/target_spike: build/spike.o build/htfi.o build/main.o
	$(LLVM)lld -flavor gnu -T src/spike.lds -o $@ $^

build/target_rv8: build/rv8.o build/semihost.o build/main.o
	$(LLVM)lld -flavor gnu -T src/rv8.lds -o $@ $^
