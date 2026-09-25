    [org 0x0100]

    start:
        call fillscreen
        mov cx,0xFFFF


    delay1:
        loop delay1
        call scroll_down
        mov cx,0xFFFF


    delay2:
        loop delay2
        mov ax,0x4c00
        int 0x21

    scroll_down:
        pusha
        mov ax,0xB800
        mov es,ax
        mov ds,ax
        std
        mov si,3040+158
        mov di,3840+158
        mov cx,1600
        rep movsw
        cld
        mov di,0
        mov ax,0x0720
        mov cx,400
        rep stosw
        popa
        ret

    fillscreen:
        pusha
        mov ax,0xB800
        mov es,ax
        mov di,0
        mov si,text_data
        mov cx,2000
        cld

    fill_loop:
        mov al,[si]
        inc si
        mov ah,0x07
        stosw
        loop fill_loop
        popa
        ret

    text_data:
        times 200 db 'X'