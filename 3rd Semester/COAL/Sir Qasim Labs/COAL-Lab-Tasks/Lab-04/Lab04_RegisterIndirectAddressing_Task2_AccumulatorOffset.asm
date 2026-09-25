[org 0x0100]

    mov bx, 0                 ; offset = 0
    mov ax, [num1+bx]         ; ax = first number

    add bx, 2                 ; offset = 2
    add ax, [num1+bx]         ; ax += second number

    add bx, 2                 ; offset = 4
    add ax, [num1+bx]         ; ax += third number

    mov [num1+6], ax          ; store result in the 4th word (offset 6)

    mov ax, 0x4c00            ; terminate program
    int 0x21

; --- Data Declarations ---
num1: dw 5, 10, 15, 0
