.model small
.data
	num0 db 9h,1h
	num1 db 0h,9h
	rez  db 0h,0h
.code
start:
	;9h+1h=0Ah
	;AAA
	;AH=AH++,AL=0
	mov AX,@data
	mov DS,AX
	mov AH,0h
	mov AL,num0+1
	add AL,num1+1
	aaa ;AH poate fi incrementat in urma acestei instructiuni!
		;ca la MUL(unde AH/DX retinea o parte din rezultat
		;DAA nu fae aceasta incrementare
	mov rez+1,AL
	mov AL,num0
	adc AL,num1
	aaa
	mov rez,AL
	mov AH,4ch
	int 21h
end start