[org 0x0100]


mov cx,10
mov si,array
mov al,[si]
inc si
dec cx

findingmin:
    mov ah,[si]
    cmp ah,al
    jae notmin
    mov al,ah

notmin:
    inc si
    loop findingmin
    mov [min],al

mov ax,0x4c00
int 0x21

array: db 5,8,3,9,2,7,1,6,4,0
min: db 0
