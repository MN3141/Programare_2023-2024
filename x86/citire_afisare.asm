.model small
.stack 100
.data
	sir db 'Sa se introduca un caracter de la tastatura: $'
	caracter db 0
.code
start:
	mov ax,@data
	mov ds,ax
	lea dx,sir
	mov ah,9h ;afisare text
	int 21h;OBS:afisarea se face din DS:DL;din DS musai!
	;mov ah,1h ;citire de la tastatura cu ecou!!
	mov ah,7h ;citire de la tastatura fara ecou
	int 21h
	mov ah,2h;afisarea se face cu ce este in DL
	mov dl,al;valoarea citita e stocata in AL
	int 21h
	mov ah,4ch
	int 21h
end start