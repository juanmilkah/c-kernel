# Minimal Kernel In C

## Requirements

* An x86 computer (of course)
* Linux
* NASM assembler
* gcc
* ld (GNU Linker)
* grub

## Building the kernel

Create object files from kernel.asm and kernel.c

```bash
nasm -f elf32 kernel.asm -o kasm.o
```

Run the assembler to create the object file kasm.o in ELF-32 bit format.
The ’-c ’ option makes sure that after compiling, linking doesn’t implicitly happen.

```bash
gcc -m32 -c kernel.c -o kc.o
```

Run the linker with the linker script and generate the executable named kernel.

```bash
ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o
```

To Run the Kernel in Qemu Emulator

```bash
qemu-system-i386 -kernel kernel
```
This project is licensed by the [GPL-3.0 license](LICENSE)
