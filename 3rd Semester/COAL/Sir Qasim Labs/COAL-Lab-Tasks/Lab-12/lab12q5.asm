    [org 0x0100]

    start:
        call clear_screen
        call compare_passwords
        call display_result

        mov ah,0x00
        int 0x16

        mov ax,0x4c00
        int 0x21

    compare_passwords:
        mov ax,cs
        mov ds,ax
        mov si,secret_password
        mov ax,cs
        mov es,ax
        mov di,input_password
        mov cx,6

        cld
        repe cmpsb
        pushf

        pop ax
        and ax,0x0040

        mov [result_flag],ax
        ret

    display_result:
        mov ax,0xB800
        mov es,ax
        cmp word [result_flag],0x0040
        je access_granted

        mov di,160*12+60
        mov si,denied_msg
        mov ah,0x04
        jmp print_message

    access_granted:
        mov di,160*12+60
        mov si,granted_msg
        mov ah,0x02

    print_message:
        mov cx,13

    print_loop:
        lodsb
        stosw

        loop print_loop

        ret

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

    secret_password: db 'secret',0
    input_password: db 'secrecy',0
    granted_msg: db 'Access Granted'
    denied_msg: db 'Access Denied'
    result_flag: dw 0