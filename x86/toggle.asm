;toggle ASCII letters
.model small
.stack 100
.data
	letter db 'A'
.code
start:
	mov ax,@data
	mov ds,ax
	mov ah,letter
	xor ah,32
	mov letter,ah
	mov ah,4ch
	int 21h
end start