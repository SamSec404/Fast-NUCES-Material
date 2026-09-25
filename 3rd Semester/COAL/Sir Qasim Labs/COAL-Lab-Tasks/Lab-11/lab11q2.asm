    [org 0x0100]
    jmp start

    video_segment equ 0xB800

    start:
        mov ax,video_segment
        mov es,ax
        mov di,0

        mov cx,25

        nextrow:
            push cx
            mov cx,80

        nextcol:
            mov ax,cx
            mov bx,81
            sub bx,ax

            cmp bx,27
            jl blue
            
            cmp bx,54
            jl white

        red:
            mov ah,0x40
            jmp print

        blue:
            mov ah,0x10
            jmp print

        white:
            mov ah,0x70

        print:
            mov al,' '
            mov [es:di],ax
            add di,2

            loop nextcol

            pop cx
            loop nextrow

            mov ax,0x4c00
            int 0x21