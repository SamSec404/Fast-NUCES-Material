[org 0x0100]

mov ax, 0FFFBh     ; -5 in hex (65531 unsigned)
cmp ax, 0
jg positive
jl negative
mov al, 0
mov [result], al
jmp done

positive:
mov al, 1
mov [result], al
jmp done

negative:
mov al, 2
mov [result], al

done:
mov ax, 0x4c00
int 0x21

result db 0
