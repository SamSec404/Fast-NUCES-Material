org 0x100

    modify_regs:
        push ax
        push bx

        mov ax,5
        mov bx,10

        pop bx
        pop ax

        ret
    start:
        mov ax,5
        mov bx,10

        call modify_regs

        mov ah, 0x4C
        int 0x21

   