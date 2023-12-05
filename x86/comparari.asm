.model small
.data
	ok db 2
	num0 db 9,9,9,9,9
	num1 db 9,9,9,9,9
.code
MARE:
	mov CL,1
	mov ok,CL
	jmp final
MIC:
	mov CL,-1
	mov ok,CL
	jmp final
EGAL:
	mov CL,0
	mov ok,CL
	jmp final
start:
	mov AX,@data
	mov DS,AX
	mov BX,0
	mov CX,5h
testLoop:
	mov AL,num0[BX]
	cmp AL,num1[BX]
	ja MARE
	jb MIC
	inc BX
	loop testLoop
	jmp EGAL
final:	
	mov AH,4ch
	int 21h
end start