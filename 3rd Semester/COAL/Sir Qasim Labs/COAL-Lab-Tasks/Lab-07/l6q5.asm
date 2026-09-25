[org 0x0100]


mov cx,9

outer:
    mov bx,0
    mov dx,cx

inner:
    mov al,[array+bx]
    mov ah,[array+bx+1]
    cmp al,ah
    jle skip

    mov [array+bx],ah
    mov [array+bx+1],al

skip:
    inc bx
    dec dx
    jnz inner

    loop outer

mov ax,0x4c00
int 0x21


array: db -7,5,-2,9,-8,3,6,-1,4,0
