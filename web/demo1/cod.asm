.model small
.stack 100
.data
	messageInput1 db 'Enter the number of digits: $'
	messageInput2 db 'Enter the number: $'
	numDigits db 0
	num db 0
.code
input proc
	mov BX,0
	mov CX,0
	lea DX,messageInput1
	mov ah,9h ;afisare text
	int 21h
	mov AH,1h ;valoarea citita e stocata in AL!
	int 21h
	sub AL,30h ;problema:pt valori aiurea(litere,nr negative) nu exista masura de siguranta!
	mov numDigits,AL
	mov CL,AL
	mov DL,10 ;cod ASCII pt rand nou
	mov AH,2h
	int 21h
	mov DL,13 ;cod ASCII pt return carriage(setare cursor pe stanga)
	mov AH,2h
	int 21h
	lea DX,messageInput2
	mov AH,9h
	int 21h
readLoop:
		mov AH,1h
		int 21h
		sub AL,30h
		mov num[BX],AL
		inc BX
loop readLoop	
ret
input endp
output proc
	mov BX,0
	mov CX,0
	mov CL,numDigits
	mov DL,10
	mov AH,2h
	int 21h
	mov DL,13
	mov AH,2h
	int 21h
printLoop:
	mov DL,byte ptr num[BX]
	inc BX
	add DL,30h
	mov AH,2h
	int 21h
	loop printLoop
ret
output endp	
start:
	mov AX,@data
	mov DS,AX
	call input
	call output
	mov AH,4ch
	int 21h
end start