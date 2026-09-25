[org 0x100]

    jmp start

    stackcalling:
        push ax
        push bx
        push cx

        pop si
        pop di
        pop dx

        ret 


    start:
        mov ax,5
        mov bx,10
        mov cx,15

        call stackcalling

        mov ax,0x4c00
        int 0x21
