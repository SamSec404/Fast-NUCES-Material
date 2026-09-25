[org 0x0100]

    mov ax, [X]         ; load X into ax
    add ax, [Y]         ; ax = X + Y
    sub ax, [Z]         ; ax = (X + Y) - Z

    mov [W], ax         ; store final result into W

    mov ax, 0x4c00      ; terminate program
    int 0x21

; --- Data Declarations ---
X: dw 500
Y: dw 300
Z: dw 150
W: dw 0
