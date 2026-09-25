[org 0x0100]

mov cx,9

outer2:
    mov bx,0
    mov dx,cx

inner2:
    mov al,[array+bx]
    mov ah,[array+bx+1]
    cmp al,ah
    jae skip2
    mov [array+bx],ah
    mov [array+bx+1],al

skip2:
    inc bx
    dec dx
    jnz inner2
    loop outer2

mov ax,0x4c00
int 0x21
array: db 5,1,9,3,7,2,8,4,6,0
