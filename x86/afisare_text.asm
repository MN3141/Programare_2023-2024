.model small
.stack 100
.data
	sir db 'Sa se introduca un caracter de la tastatura$'
	caracter db 0
.code
start:
	mov ax,@data
	mov ds,ax
	lea dx,sir
	mov ah,9h
	int 21h
	mov ah,4ch
	int 21h
end start