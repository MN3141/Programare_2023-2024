.model small
.stack 100
.data
	param dw 3
	rez dw -1
.code
inputStruc struc
	_bp dw ?
	_ip dw ?
	_param dw ?
inputStruc ends
	putere2 proc
		push BP
		mov BP,SP
		mov BX,[BP]._param
		cmp BX,0
		jne rec
		mov AX,1
		jmp caput
	rec:
		dec BX
		push BX
		call putere2
		pop BX
		mov CL,2
		mul CL
	caput:
		pop BP
		ret
	mov rez,BX
	putere2 endp
start:
	mov AX,@data
	mov DS,AX
	mov BX,param
	push BX
	call putere2
	mov AH,4ch
	int 21h
end start