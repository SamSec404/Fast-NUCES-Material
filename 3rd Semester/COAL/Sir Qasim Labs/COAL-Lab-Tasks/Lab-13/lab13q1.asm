[org 0x0100]

    start:
        mov si, msg_start
        call print_string
        
        call delay_5_seconds
        
        mov si, msg_end
        call print_string
        
        mov ax, 0x4c00
        int 0x21

   delay_5_seconds:
        push cx
        push bx
        push dx
        
        mov cx, 250
        
    outer_loop:
        mov bx, 500
        
    middle_loop:
        mov dx, 83
        
      inner_loop:
        dec dx
        jnz inner_loop
        
        dec bx
        jnz middle_loop
        
        dec cx
        jnz outer_loop
        
        pop dx
        pop bx
        pop cx
        ret
        

    print_string:
        pusha
        mov ah, 0x0E
        
    .print_char:

        lodsb
        cmp al, 0
        je .done

        int 0x10
        jmp .print_char

    .done:
        popa
        ret

    msg_start: db 'Delay for 5 seconds', 13, 10, 0
    msg_end: db 'Printed after 5 seconds', 13, 10, 0