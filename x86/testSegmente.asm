;=====================
;BYTE-divizibil cu 1
;WORD-divizibil cu 2
;PARA-divizibil cu 16
;PAGE-divizibil cu 32
;=====================
.model small
.stack 100
.data	
	data1 segment ;implicit e setat pe modul PARA(multiplu de 16)
	v1 db 5
	v11 db 16 dup(-1)
	data1 ends
	data2 segment
	v2 dw 25 ;OBS:v2 mereu e pus la adresa cu multiplu de 16(in cazul nostru 20h)
	v22 dw -1
	data2 ends
	data3 segment
	v3 dw 100
	data3 ends
	data4 segment BYTE;segmentul va incepe de la o adresa multiplu de 1(deci fix dupa segmentul data3)
	v4 dw 0FFh,0FFh,0
	data4 ends
	dgrup group data1, data2
	esgrup group data3,data4
	cod segment
assume cs:cod, ds:dgrup, es:esgrup
start:
	mov ax, dgrup
	mov ds, ax
	mov ax, data3
	mov es, ax
;referiri la date
	mov bl, v1 ;se utilizează DS (asociat cu dgrup)
	mov cx,v2
	add v3, bx ;se utilizează ES (asociat cu data3)
	mov ah,4ch
	int 21h
cod ends
end start