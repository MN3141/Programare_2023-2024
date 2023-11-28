;conversie BCD impachetat->BCD despachetat
.model small
.stack 100
.data
	num0 db 12h,35h,7h
	tampon db -1
	digits db tampon-num0
	num1 db -2
.code
bcdConvert proc
	mov SI,0;index num0
	mov BX,0;index num1
	mov CX,0
	mov CL,digits
bcdLoop:
	mov AX,0
	mov AL,DS:num0[SI]
	shl AX,4
	shr AL,4
	mov num1[BX],AL
	inc BX
	mov num1[BX],AH
	inc BX
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