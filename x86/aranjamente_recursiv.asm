;int aranj(int n,int k)
;	{
;		if(k==1)
;			return n;
;		return aranj(n-1,k-1);
;	}
.model small
.stack 
.data
	n dw 4
	k dw 2
.code
 inputStruc struc 
	_bp dw ?
	_ip dw ?
	_param0 dw ?;n
	_param1 dw ?;k
 inputStruc ends
aranj proc 
	push BP
	mov BP,SP
	mov AX,[BP]._param0 ;n
	mov BX,[BP]._param1	;k
	cmp BX,1
	jne rec
	mov AX,n ;s-ar putea mai elegant
	jmp caput
rec:
	dec BX
	dec AX
	push BX
	push AX
	call aranj
	pop CX
	pop BX ;n
	mul CX
caput:
	pop BP
	ret
aranj endp
start:
	mov AX,@data
	mov DS,AX
	mov AX,n
	mov BX,k
	push BX
	push AX
	call aranj
	add SP,4
	mov AH,4ch
	int 21h
end start