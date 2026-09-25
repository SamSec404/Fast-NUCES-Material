[org 0x0100]

mov bx, 05h      ; BX = 5
sub bx, 10h      ; 5 - 16 = -11 SF = 1 (negative result)

mov bx, 20h      ; BX = 32  Positive number  SF = 0

mov ax, 0x4c00
int 0x21