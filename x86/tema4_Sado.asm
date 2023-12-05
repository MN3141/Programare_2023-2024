.model small
.stack 100
.data
    msg1 db 'Nr1: '
    msg1Len equ $-msg1
    msg2 db 'Nr2: '
    msg2Len equ $-msg2

    nr1 db 6 dup(0)
    nr2 db 6 dup(0)
    nr1Dec dw 0
    nr2Dec dw 0 
    rez dw 0 
    rezAscii db, 6 dup(0)
.code
read proc

et1:
    mov ah,1h
    int 21h
    cmp al,13
    jz break
    mov [bx],al
    inc bx
    loop et1
break:
    cmp cx,0
    jz newl
    ret
newl:
    call newline
    ret
read endp 

println proc

et2:
    mov ah,2h
    mov dl,[bx]
    int 21h
    inc bx
    loop et2

    ret
println endp

newline proc
    mov ah,2h
    mov dl,10
    int 21h
    ret
newline endp

convertAsciiToDecimal proc
    mov ax,0
et3:   
    mov bl,byte ptr[si]
    sub bl,30h
    add [di],bx
    mov ax,10
    mul word ptr[di]
    mov [di],ax
    inc si
    cmp byte ptr[si],0
    jnz et3
    mov ax,[di]
    mov bx,10
    div bx
    mov [di],ax

    ret
convertAsciiToDecimal endp

convertDecimalToAscii proc
    mov ax,si
    mov bx,10
    add di,cx
et5:
    mov dx,0
    idiv bx
    add dl,30h
    mov [di],dl
    dec di
    cmp ax,0
    jne et5

    ret
convertDecimalToAscii endp

cmmdc proc
    
et4:
    cmp ax,bx
    js bxGreaterAx
    sub ax,bx
    cmp ax,bx
    jnz et4
    mov rez,bx
    ret
bxGreaterAx:
    sub bx,ax
    cmp ax,bx
    jnz et4
    mov rez,bx
    ret
cmmdc endp

sizeSi proc
    mov bx,10
    mov ax,si
    mov cx,0
et6:
    mov dx,0
    div bx
    inc cx
    cmp ax,0
    jnz et6
    dec cx
    ret
sizeSi endp

start:
    mov ax,@data
    mov ds,ax

    lea bx,msg1
    mov cx,msg1Len
    call println
    mov cx,5
    lea bx,nr1
    call read

    lea bx,msg2
    mov cx,msg1Len
    call println
    mov cx,5
    lea bx,nr2
    call read

    lea si,nr1
    lea di,nr1Dec
    call convertAsciiToDecimal

    lea si,nr2
    lea di,nr2Dec
    call convertAsciiToDecimal

    mov ax,[nr1Dec]
    mov bx,[nr2Dec]
    call cmmdc
    
    mov si, rez
    call sizeSi
    lea di,rezAscii
    call convertDecimalToAscii
    
    mov si,rez
    call sizeSi
    inc cx
    lea bx,rezAscii
    call println

    mov ah, 4ch
    int 21h
end start