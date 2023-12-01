;Sa se scrie un program care citeste de la tastura un numar din zecimal.
;Numarul are maxim 5 cifre. Pentru a se citi se va folosi (mov ah, 1 / int 21h)
;si se va testa caracterul citit in AL sa nu fie enter (code ascii 13).
;Odata citit numarul va fi stocata in zona de date si apoi afisat pe ecran.;S
;Se vor crea proceduri pentru a citi / afisa numarul (vor fi folosite in urmatoarele probleme).
.model small
.stack 100
.data
	msgInput db 'Enter your number: $'
	msgOutput db 'Your number is: $'
	digits db 0
	num db -1
.code
read proc
	mov BX,0
	lea DX,msgInput
	mov AH,9h
	int 21h
readLoop:
	mov AH,1h
	int 21h
	cmp AL,13
	jz readEnd
	sub AL,30h
	mov byte ptr num[BX],AL
	inc digits 
	inc BX
	jmp readLoop
readEnd:
ret
read endp
write proc
	mov BX,0
	mov CX,0
	mov CL,digits
	mov DL,10 ;cod ASCII pentru rand nou
	mov AH,2h
	int 21h
	mov DL,13;cod ASCII pentru return carriage(setare cursor pe stanga)
	mov AH,2h
	int 21h
	lea DX,msgOutput
	mov AH,9h
	int 21h
writeLoop:
	mov DL,byte ptr num[BX]
	add DL,30h
	mov AH,2h
	int 21h
	inc BX
	loop writeLoop
ret
write endp
start:
	mov AX,@data
	mov DS,AX
	call read
	call write
	mov AH,4ch
	int 21h
end start