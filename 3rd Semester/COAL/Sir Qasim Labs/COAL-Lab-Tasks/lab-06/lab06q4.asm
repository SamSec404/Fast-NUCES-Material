[org 0x0100]

mov cx, 10
mov ax, 0
mov bx, 1

start_loop:
add ax, bx
inc bx
loop start_loop

mov [sum], ax

mov ax, 0x4c00
int 0x21

sum dw 0
