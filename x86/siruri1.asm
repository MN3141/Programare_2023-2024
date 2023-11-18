.model small
.stack 100
.data
	sir0 db 'ANA$'
    len_sir0 db $-sir0-1;mai scadem 1 deoarece sirurile considerate nu contin $
	sir1 db 'ANa ANA ANA AnA$'
    len_sir1 db $-sir1-1
	contor1 db 0 ;verificarea primului sir
	contor2 db 0;nr de aparitii a primului sir
.code
incrementare:inc contor1
jmp inapoi
verificare:
	mov AL,len_sir0
	cmp contor1,AL
	jz GASIT
	mov contor1,0
	lea SI,sir0 ;reluam parcurgerea primului sir
	jmp inapoi
GASIT:
	inc contor2 ;aparitie a sirului
	mov contor1,0
	lea SI,sir0
jmp inapoi
PROCEDURA proc
bucla:
	cmpsb
	jz incrementare
	jne verificare
inapoi:	loop bucla
ret
PROCEDURA endp
start:
	mov AX,@data
	mov DS,AX
	mov ES,AX
	lea SI,sir0
	lea DI,sir1
	mov CX,0
	mov CL,len_sir1
	call PROCEDURA
	mov DX,0
	mov DL,30h
	add DL,contor2
	mov ah,2h
	int 21h
	mov ah,4ch
	int 21h
end start
