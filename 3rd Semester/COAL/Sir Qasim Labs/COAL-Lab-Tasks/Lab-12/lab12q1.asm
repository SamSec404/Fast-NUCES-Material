[org 0x0100]

    start:
        mov ax,0xB800
        mov es,ax
        mov di,0
        mov ax,0x1720
        mov cx,2000
        
        cld
        rep stosw

        mov ah,0x00
        int 0x16

        mov ax,0x4c00
        int 0x21