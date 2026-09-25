[org 0x0100]

mov cx, 5

countdown:
mov al, cl
mov [num], al
dec cx
jnz countdown

mov ax, 0x4c00
int 0x21

num db 0
