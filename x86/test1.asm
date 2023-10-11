.model small
.stack 100
.data
	var1 dB 0FCh
	var2 db 1,2 ;functioneaza ca pointerii din tablouri
.code
start:
mov ax, @data;@data e un pointer/label
mov ds, ax
mov bh,var1
mov bl,0d ;la mov operanzii trb sa fie de aceeasi dimensiune
mov cl,var2
mov ch,var2+1
mov ah,4ch
int 21h
end start