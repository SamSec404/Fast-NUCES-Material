[org 0x0100]

    jmp starting

    multiplicand: db 13
    multiplier:   db 5
    result:       dw 0

starting:
    mov bl,[multiplicand]
    mov dl,[multiplier]
    mov cl,4

    checkbit:
        shr dl,1
        jnc skip
        add [result],bl

    skip:
        shl bl,1

        dec cl
        jnz checkbit    

    mov ax,0x4c00
    int 0x21