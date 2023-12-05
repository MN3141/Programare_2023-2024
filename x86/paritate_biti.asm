.model small
.stack 100
.data 
	num dd 0ffffffffh
.code
ceva proc
	mov BX,0
	mov CX,1
	mov BP,SP
	add BP,2;pt a nu lucra cu IP,ci cu nr cuvintele salvata
bucla1:
	mov AX,[BP]
bucla2:
	shl AX,1
	adc BX,0;vom contoriza in functie de Carry Flag!
	cmp AX,0
	jnew bucla2
	add BP,2
	loop bucla1
ret
ceva endp
start:
	mov AX,@data
	mov DS,AX
	push word ptr num
	push word ptr num+2
	call ceva
	mov AH,4ch
	int 21h
end start