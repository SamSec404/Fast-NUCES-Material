[org 0x0100]

mov cx,10
mov si,array
mov al,[si]
inc si
dec cx

findingmax:
    mov ah,[si]
    cmp ah,al
    jbe notmax
    mov al,ah

notmax:
    inc si
    loop findingmax
    mov [max],al

mov ax,0x4c00
int 0x21


array: db 4,9,1,7,3,8,2,6,5,0
max: db 0
