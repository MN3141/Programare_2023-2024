;Să se scrie un program care dă indicele caracterului începând de la
;care două şiruri diferă.
.model small
.stack 100
.data
	sir0 db 'Ana are mere$'
	len_sir0 equ $-sir0
	sir1 db 'Ana are pere$'
.code
different:
	dec SI
	lea AX,sir0
	sub SI,AX
	jmp finish
start:
	mov AX,@data
	mov DS,AX
	mov ES ,AX
	cld
	lea SI,sir0
	lea DI,sir1
	mov CX,0
	mov CL,len_sir0
	rep CMPSB 
	jne different
	mov SI,-1
finish:	
		mov DX,0
		mov DX,SI
		add DL,48
		int 21h
		mov AH,4ch
		int 21h
end start