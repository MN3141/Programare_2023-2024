.model small
.stack 100
.data
a db 1,2,3,4,56h
b dw 1234h, 5,-1
lb equ $-b
c dd 1,2,3,4,5
lc equ $-c
.code
start:
mov ax, @data
mov ds, ax
mov ah,4ch
int 21h
end start