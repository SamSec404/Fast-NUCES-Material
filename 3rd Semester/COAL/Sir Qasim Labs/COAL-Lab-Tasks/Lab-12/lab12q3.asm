    [org 0x0100]

    start:
        call clear_screen
        mov si,msg_length

        call print_string

        push cs
        push my_string

        call strlen
        call display_number

        mov ah,0x00
        int 0x16

        mov ax,0x4c00
        int 0x21

    strlen:
        push bp
        mov bp,sp
        push es
        push di
        push cx

        les di,[bp+4]
        xor al,al

        mov cx,0xFFFF

        cld
        repne scasb

        mov ax,0xFFFF

        sub ax,cx

        dec ax
        pop cx
        pop di
        pop es
        pop bp
        ret 4

    display_number:
        pusha
        cmp ax,0
        jne convert

        mov ah,0x0E
        mov al,'0'

        int 0x10

        jmp done_display

    convert:
        mov bx,10
        mov cx,0

    digit_loop:
        xor dx,dx
        div bx

        push dx

        inc cx

        test ax,ax
        jnz digit_loop

        mov ah,0x0E

    display_loop:
        pop dx

        add dl,'0'

        mov al,dl
        int 0x10

        loop display_loop

    done_display:
        popa
        ret

    clear_screen:
        pusha
        mov ax,0xB800
        mov es,ax

        xor di,di

        mov ax,0x0720
        mov cx,2000

        cld
        rep stosw
        popa
        ret

    print_string:
        pusha
        mov ah,0x0E

    .next_char:
        lodsb
        cmp al,0
        
        je .done
        int 0x10
        jmp .next_char

    .done:
        popa
        ret

    msg_length: db 'String Length ',0
    my_string: db 'Hello Assembly',0