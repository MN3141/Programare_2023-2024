.model small
.stack 100
.data 
	e_par db -1 ;-1:INCERT,0:IMPAR,1:PAR
	num dw 5h
.code
start:
	mov ax,@data
	mov ds,ax
	call paritate

paritate proc
	mov ax,num
	mov dx,0
	mov bx,2
	div bx
	cmp dx,0
	je DA
	mov e_par ,0
	jmp CAPAT 
DA: mov e_par ,1
CAPAT:
paritate endp
	mov ah,4ch
	int 21h
end start