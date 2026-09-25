    [org 0x0100]

    start:
        mov ah,0x01
        mov cx,0x2607
        int 0x10

    blink_loop:
        call display_warning
        call delay
        call clear_message
        call delay

        mov ah,0x01
        int 0x16
        jz blink_loop

        mov ah,0x00
        int 0x16

        mov ah,0x01
        mov cx,0x0607
        int 0x10

        mov ax,0x4c00
        int 0x21

    display_warning:
        pusha

        mov ax,0xB800
        mov es,ax
        mov di,(12*80+36)*2
        mov si,warning_text
        mov ah,0x8F
        mov cx,8

    display_loop:
        lodsb
        stosw
        loop display_loop

        popa
        ret

    clear_message:
        pusha

        mov ax,0xB800
        mov es,ax
        mov di,(12*80+36)*2
        mov ax,0x0720
        mov cx,8

    clear_loop:
        stosw
        loop clear_loop

        popa
        ret

    delay:
        push cx
        push bx

        mov cx,50

    delay_outer:
        mov bx,5000

    delay_middle:
        push cx
        mov cx,100

    delay_inner:
        nop
        nop
        loop delay_inner

        pop cx
        dec bx
        jnz delay_middle

        dec cx
        jnz delay_outer

        pop bx
        pop cx

        ret

    warning_text: db 'WARNING'