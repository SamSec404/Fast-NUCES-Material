    [org 0x0100]
    jmp start

    video_segment equ 0xB800

    drawrect:
        push bp
        mov bp,sp

        push es
        push ax
        push bx
        push cx
        push dx
        push di

        mov ax,video_segment
        mov es,ax

        mov cx,[bp+10]
        mov dx,[bp+4]

        nextrow_rect:
            cmp cx,dx
            jg end_rect

            mov ax,[bp+8]
            mov bx,[bp+6]

        nextcol_rect:
            cmp ax,bx
            jg next_row

            push ax

            mov ax,cx
            mov di,80
            mul di

            pop di
            add ax,di
            shl ax,1
            mov di,ax

            mov si,cx
            cmp si,[bp+10]
            je top_border

            cmp si,[bp+4]
            je bottom_border

            mov si,ax
            shr si,1
            cmp si,[bp+8]
            je side_border

            cmp si,[bp+6]
            je side_border

            mov al,' '
            jmp print_char

        top_border:
        bottom_border:
            mov al,'-'
            jmp print_char

        side_border:
            mov al,'|'

        print_char:
            mov ah,0x07
            mov [es:di],ax

            inc ax
            jmp nextcol_rect

        next_row:
            inc cx
            jmp nextrow_rect

        end_rect:
            pop di
            pop dx
            pop cx
            pop bx
            pop ax
            pop es
            pop bp
            ret 8

        start:
            mov ax,30
            push ax
            mov ax,10
            push ax
            mov ax,15
            push ax
            mov ax,5
            push ax
            
            call drawrect

            mov ax,0x4c00
            int 0x21