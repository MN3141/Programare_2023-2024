;the current program works only for 8 bit numbers
.model small
.stack 100
.data
	num db 11 ;the number which we want to multiply
	constant db 14;the constatnt with which we want to do it
.code
start:
	mov ax,@data
	mov ds,ax
	mov ah,1
	mov al,num
while_loop:add num,al
	 add ah,1
	 cmp constant,ah
	 jz final
	 jmp while_loop
final: 
	mov ah,4ch
	int 21h
end start