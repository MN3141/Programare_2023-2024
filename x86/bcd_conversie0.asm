;conversie BCD despachetat->BCD impachetat
.model small
.stack 100
.data
	num0 db 0h,1h,2h
	tampon db 0
	digits db tampon-num0
	num1 db -1
.code
bcdConvert proc
	mov SI,0;index num0
	mov BX,0;index num1
	mov CX,0
	mov CL,digits
    dec CL;lucram tot cu cate 2 cifre
bcdLoop:
	mov AX,word ptr num0[BX]
    add BX,2
    shl AL,4
    shr AX,4
    mov DS:num1[SI],AL
    inc SI
	loop bcdLoop
ret
bcdConvert endp
start:
	mov AX,@data
	mov DS,AX
	call bcdConvert
	mov AH,4ch
	int 21h
end start