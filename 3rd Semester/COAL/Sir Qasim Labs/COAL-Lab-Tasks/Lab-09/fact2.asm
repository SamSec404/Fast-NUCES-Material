[org 0x0100]

    jmp start
    data: db 5
    result: db 0

    fact:
        mov bl,al
        dec bl

    factloop:
        mul bl
        dec bl
        cmp bl,1
        ja factloop
        ret

    start:
        mov al,[data]
        call fact
        mov [result],ax

    mov ax,0x4c00
    int 0x21