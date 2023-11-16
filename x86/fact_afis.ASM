.model small
.stack 100
.data
        mesaj db 'Numarul este prea mare$'
        nr dw 5
	nrf db 8 dup(?)
.code
	afis proc
		mov dl,al
		add dl,'0'
		mov ah,2
		int 21h
		ret
	afis endp
start:
	mov ax,@data
	mov ds,ax
	mov bx,nr
	mov ax,nr
et:	dec bx 
	mul bx 
	jc sf1
	cmp bx,1
	jne et
	mov bx,10
	mov si,0
et1:	mov dx,0
	div bx
	mov nrf[si],dl
	inc si
	cmp ax,0
	jnz et1
et2:	mov al,nrf[si]
	call afis
	dec si
	jge et2
sf1:    jo afmesaj
	jmp sfarsit
afmesaj:  lea dx,mesaj
	mov ah,9h
	int 21h
sfarsit:mov ah,4ch
	int 21h
	end start
