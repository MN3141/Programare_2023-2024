; XLAT.ASM
;preluat din:http://www.c-jump.com/CIS77/ASM/DataTypes/T77_0280_xlat.htm
; Demonstrates character encoding using XLAT instruction
.MODEL small         ; Flat memory model
.STACK 100h     ; (default is 1-kilobyte stack)
.DATA           ; Begin initialized data segment
                ; Table for encrypting digits:
                ; Input digits:     0 1 2 3 4 5 6 7 8 9
                ; Encrypted digits: 4 6 9 5 0 3 1 8 7 2
    xlat_table	DB      "4695031872" 
.CODE           ; Begin code segment
start:      ; Beginning of code
	mov AX,@data
	mov DS,AX
    mov    BX, OFFSET xlat_table
    mov    AL, '5' ; put input character into AL
    sub    AL, '0' ; convert input character to index
    xlatb          ; AL = encrypted digit character
		;descifreaza un caracter
	mov AH,4ch
	int 21h
end start