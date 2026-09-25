[org 0x0100]
    jmp start

    video_segment equ 0xB800

start:
    mov ax, video_segment
    mov es, ax                  ; Point ES to video memory
    
    mov cx, 25                  ; 25 rows

nextposition:
    push cx
    dec cx                      ; Current row (0-24)
    
    mov ax, cx                  ; Row number
    mov bx, 162                 ; (80 + 1) * 2 = 162
    mul bx                      ; AX = row * 162
    mov di, ax                  ; DI = screen offset
    
    mov al, '*'                 ; Asterisk character
    mov ah, 0x02                ; Green on Black
    mov [es:di], ax
    
    pop cx
    loop nextposition

    mov ax, 0x4c00              ; Exit to DOS
    int 0x21