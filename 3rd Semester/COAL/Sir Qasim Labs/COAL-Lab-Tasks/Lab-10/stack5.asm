[org 0x0100]

    doublevalue:
        push bp
        mov bp,sp
        sub sp,2
        
        push ax
        push bx

        mov ax,[bp+4]
        mov bx,2
        mul bx

        mov [bp-2],ax
        
        pop bx
        pop ax
        
        mov sp,bp
        pop bp
        
        ret 2

    start:
        mov ax,5
        
        push ax
        call doublevalue
        
        mov ax,0x4c00
        int 0x21