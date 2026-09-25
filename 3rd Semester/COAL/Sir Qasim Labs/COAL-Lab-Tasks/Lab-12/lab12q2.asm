[org 0x0100]

    start:
        call clear_screen

        mov ax,0xB800
        mov es,ax
        mov di,1980
        mov ax,cs
        mov ds,ax
        mov si,my_string
        mov cx,20

        cld
        mov ah,0x07

    print_loop:
        lodsb
        stosw

        dec cx
        jnz print_loop

        mov ah,0x00
        int 0x16

        mov ax,0x4c00
        int 0x21

    clear_screen:
        pusha
        mov ax,0xB800
        mov es,ax
        mov di,0
        mov ax,0x0720
        mov cx,2000
        
        cld
        rep stosw
        popa
        ret

    my_string:
        db 'Sanaullah - P24-0554'