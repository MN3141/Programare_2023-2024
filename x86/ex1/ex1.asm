;INIT
;=========================================================================
.model small
.stack 100
.data
tabel db 1, 2, 3, 4, 5, 10 dup(?) ;10 dup(?) pune 0 de 10 ori in memorie
tabel1 dw 1, 2, 3, 12H, 12
tabel2 dd 1, 2, 1234H
tabel3 dq 1, 2, 12345678H
tabel4 dt 1, 2,, 1234567890H
;COD
;=========================================================================
.code
start:
mov ax, @data
mov ds, ax
mov ax, 14h ;adresare imediată
mov ax, 14
mov al, tabel ;adresare directă
mov al, tabel[1] ;adresare directă <=>al<-*(tabel+1)
mov ax, word ptr tabel ;adresare directă – operatorul
;ptr este necesar, tabel fiind
;ptr=pointer,arata spre locatia de tipul specificat
mov ax, word ptr tabel[2]

;definit cu directiva DB

mov bx, offset tabel ;pointer
mov al, [bx+1] ;adresare indirectă
mov al, [bx] ;adresare indirectă
mov bx, 5
mov al, tabel[bx] ;adresare bazată
mov si, 1 ;si=Source Index,folosit mai mult pentru a indica inceputul unui sir
mov al, [bx][si] ;adresare bazată şi indexată ;al<-Mem[ds+bx+si]
mov si, 6
mov byte ptr [bx][si],2 ;adresare bazată şi indexată ;Scrie in locatia ds+xC valoarea 2 pe 1 octet
mov bp, offset tabel
mov al, [bp] ;adresare bazată cu deplasament nul
mov byte ptr ds:[bp][si][1], 7
mov word ptr ds:[bp][si][1], 19H

;adresare bazată şi indexată
;IESIRE
;=========================================================================
mov ah, 4ch
int 21h
end start