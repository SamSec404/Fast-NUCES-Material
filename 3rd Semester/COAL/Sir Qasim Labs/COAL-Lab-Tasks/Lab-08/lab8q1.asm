[org 0x0100]

    jmp start

    ;data: db 010

    start:
        mov bl,10010101b
        mov al,0
        mov cl,8

        loopstart:
        shl bl,1
        rcr al,1
        dec cl
        jnz loopstart   


    mov ax, 0x4c00
    int 0x21

   