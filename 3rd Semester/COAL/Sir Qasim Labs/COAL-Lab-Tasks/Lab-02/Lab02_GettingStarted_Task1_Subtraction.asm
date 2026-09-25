[org 0x0100]

    mov ax, 50          ; load 50 into ax
    mov bx, 25          ; load 25 into bx
    sub ax, bx          ; ax = ax - bx = 50 - 25 = 25

    mov ax, 0x4c00      ; terminate program
    int 0x21
