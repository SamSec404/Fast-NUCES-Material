[org 0x0100]

mov ax, 5
mov bx, 5
cmp ax, bx
jne not_equal
mov al, 1
mov [num], al
jmp done

not_equal:
mov al, 0
mov [num], al

done:
mov ax, 0x4c00
int 0x21

num db 0
