.model small
.stack 100
.data
	bcd0 db 90h;nr BCD trb sa fie in format hexa!
	bcd1 db 9h
	bcd2 db 0h
.code
start:
	mov ax, @data
	mov ds, ax
	mov ax,0
	add al,bcd0
	add al,bcd1
	daa ;lucreaza cu AL!
	mov bcd2,al
	mov ah,4ch
	int 21h
	end start