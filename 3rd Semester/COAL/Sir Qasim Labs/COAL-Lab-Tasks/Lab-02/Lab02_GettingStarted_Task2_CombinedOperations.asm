[org 0x0100]

    mov ax, 15          ; load 15 into ax
    mov bx, 10          ; load 10 into bx
    add ax, bx          ; ax = 15 + 10 = 25

    mov bx, 5           ; load 5 into bx
    sub ax, bx          ; ax = 25 - 5 = 20

    mov ax, 0x4c00      ; terminate program
    int 0x21
