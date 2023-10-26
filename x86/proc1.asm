.model small
.stack 100
.data
tabc db '0123456789ABCDEF'
.code
start: mov ax,@data
mov ds,ax
mov al,0 
repet: mov bx,offset tabc ;pune în BX adresa efectivă tabc
push ax ;salvează AL în stivă
xlat ;pune în AL octetul de la adresa efectivă [BX+AL]
call afisare ;apelul procedurii afisare
pop ax
inc al ;increment 
cmp al,10H
;se verifică dacă s-au afişat toate caracterele
jz sfarsit
jmp repet
afisare proc
mov dl,al
;pune în DL codul caracterului care trebuie afişat
mov ah,2h
;funcŃia DOS pentru afişarea caracterului din DL
int 21h
mov dl,' '
mov ah, 2h
int 21h
ret
afisare endp
sfarsit: mov ax,4c00h
;funcŃia DOS de ieşire în sistemul de operare
int 21h
end start