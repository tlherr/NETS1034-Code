; Define Variables in the data section
section .data
    ; 0xA is newline, db = define byte. db allocates space, stores value and sets hello as address of this string in memory
    ; also could use equ (equate) which is more simple
    hello:      db 'hello world or something like that',0xA
    helloLen:   equ $-hello

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    ; There are six registers that store the arguments of the system call used. These are the EBX, ECX, EDX, ESI, EDI, and EBP.
    ; All the syscalls are listed in /usr/include/asm/unistd.h,
    ; Make system call to write (1=sys_exit, 2=sys_fork, 3=sys_read, 4=sys_write, 5=sys_open, 6=sys_close)
    mov eax,4
    ; set file descriptor to 1 (1 = STDOUT)
    mov ebx,1
    ; set string we are writing
    mov ecx,hello
    ; set the length of the string we are writing
    mov edx,helloLen
    ; call the kernel
    int 80h
    
    ; 'exit' system call
    mov eax,1            
    ; exit with error code 0
    mov ebx,0            
    ; call the kernel
    int 80h              