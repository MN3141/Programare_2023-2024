;recursivitatea pute
.model small
.stack 
.data
	input dw 99999
.code
 inputStruc struc 
	_bp dw ?
	_ip dw ?
	_param dw ?
 inputStruc ends
sumDigits proc 
	push BP
	mov BP,SP
	mov AX,[BP]._param
	xor DX,DX;DX<-0
	cmp AX,0
	jne rec
	jmp caput
rec:
	mov CX,10
	DIV CX
	push DX
	push AX
	call sumDigits
	pop BX
	pop DX
	adc AX,DX
caput:
	pop BP
	ret
sumDigits endp
start:
	mov AX,@data
	mov DS,AX
	mov AX,input
	push AX
	call sumDigits
	add SP,2
	mov AH,4ch
	int 21h
end start