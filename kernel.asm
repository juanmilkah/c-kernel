bits 32 ;foro the nasm
section .text
  ;multiboot_spec
  align 4
  dd 0x1BADB002; magic
  dd 0x00 ;flags
  dd -(0x1BADB002 + 0x00) ;checksum m+ f+ c =0

global start
extern kmain ;external function

start:
  cli ;block interupts
  mov esp, stack_space ;set stack poointer
  call kmain
  hlt ;halt cpu

section .bss
resb 8192 ; 8KB for stack
stack_space: 
