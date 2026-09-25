    [org 0x0100]

    calculate:
        push bp
        mov bp,sp

        sub sp,2
        
        push ax
        push bx

        mov ax,5
        mov bx,15
        add ax,bx
        mov [bp-2],ax
        
        mov ax,[bp-2]
        
        pop bx
        pop ax
        
        mov sp,bp
        pop bp

        ret

    start:
        call calculate
        
        mov ax,0x4c00
        int 0x21