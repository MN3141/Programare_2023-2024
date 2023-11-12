.model small
.stack 100
.data
	num dw 10
	mesaj db "numar prea mare$"
.code
eroare:
	lea DX,mesaj
	mov AH,9h
	int 21h
	jmp final
start:
	mov ax,@data
	mov ds,ax
	mov CX, num
	mov AX,1
fact:
	mul CX
	jo eroare
	loop fact
final:	mov ah,4ch
		int 21h
end start
