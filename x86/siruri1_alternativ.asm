;Exercitiul 3 pag 46 indrumar
.model small
.data
sir1 db 'Ana are mere'
sir2 db 'Axa are pere'
lungime equ $-sir2
pozitie db 0

.code
Start:
mov ax,@data
mov ds,ax
mov es,ax
cld
lea si,sir1
lea di,sir2
mov cx,lungime
repe cmpsb
jne AmDiferente
jmp Sfarsit
AmDiferente:
inc cx
mov ax,lungime
sub ax,cx

Sfarsit:

mov ax,4C00h
int 21h
end start


