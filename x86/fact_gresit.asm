.model small
.stack 100
.data
	num dw 8
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
	mov BX,10
	mov CX,0
	DO: ;deja in AX se afla nr
	mov DX,0
	div BX
    add DX,30h ;30h='0' ASCII
	push DX
	add CX,1
	cmp AX,0
	je exit
	jmp DO
exit:
	call print
	mov ah,4ch
	int 21h
print proc
	mov BX,SP
        add BX,2
DO2:
	mov DX,SS:[BX];vrem sa luam din stiva
        add BX,2
	mov AH,2h
	int 21h
	mov AX,SP
	loop DO2
ret
print endp
final:	mov ah,4ch
		int 21h
end start
