    [org 0x0100]

    jmp start

    add_two:
        push bp
        mov bp,sp

        push ax
        push bx
        
        mov ax,[bp+4]
        mov bx,[bp+6]
        add ax,bx
        
        pop bx
        pop ax
        pop bp
        
        ret 4

    start:
        mov ax,5
        mov bx,10
        
        push ax
        push bx

        call add_two
        
        mov ax,0x4c00
        int 0x21