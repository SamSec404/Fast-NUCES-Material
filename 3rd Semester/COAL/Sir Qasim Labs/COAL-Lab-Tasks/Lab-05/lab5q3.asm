[org 0x0100]

mov al, 0FFh     ; AL = 255 (max 8-bit value)
add al, 01h      ; CF = 1

mov al, 05h      ; AL = 5
add al, 02h      ; CF = 0

mov ax, 0x4c00
int 0x21
