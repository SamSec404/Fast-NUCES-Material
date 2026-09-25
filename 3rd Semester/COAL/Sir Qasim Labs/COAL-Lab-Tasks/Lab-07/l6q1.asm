[org 0x0100]

mov si,9

outer_loop:
    mov di,0
    mov bp,si

inner_loop:
    mov al,[data+di]
    mov bl,[data+di+1]
    cmp al,bl
    jbe no_swap

    mov [data+di],bl
    mov [data+di+1],al

no_swap:
    inc di
    dec bp
    jnz inner_loop

    dec si
    jnz outer_loop

mov ax,0x4c00
int 0x21


data: db 9,2,7,1,8,3,6,4,5,0
