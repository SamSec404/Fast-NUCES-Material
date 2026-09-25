[org 0x0100]
    jmp start

    video_segment equ 0xB800

; Subroutine to print number at specific location
printnum_loc:
    push bp
    mov bp, sp
    push es
    push ax
    push bx
    push cx
    push dx
    push di
    
    mov ax, video_segment
    mov es, ax
    
    ; Calculate position: (row * 80 + col) * 2
    mov ax, [bp+8]      ; row = 5
    mov bx, 80
    mul bx              ; ax = 5 * 80 = 400
    add ax, [bp+6]      ; ax = 400 + 10 = 410
    shl ax, 1           ; ax = 410 * 2 = 820
    mov di, ax
    
    ; TEST: First print 'X' at calculated position
    mov ax, 0x4E58      ; Bright Yellow 'X'
    mov [es:di], ax
    
    ; Now print the number
    mov ax, [bp+4]      ; number = 554
    mov bx, 10
    mov cx, 0

    ; Check if number is zero
    cmp ax, 0
    jne nextdigit
    mov dx, '0'
    push dx
    inc cx
    jmp nextpos

nextdigit:
    xor dx, dx
    div bx              ; ax=55, dx=4
    add dl, '0'         ; dl='4'
    push dx             ; push '4'
    inc cx              ; cx=1
    cmp ax, 0
    jne nextdigit       ; repeat

nextpos:
    pop dx              ; dl='5' (first digit)
    mov dh, 0x4E        ; Bright Yellow
    mov [es:di], dx
    add di, 2
    loop nextpos
    
    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    pop es
    pop bp
    ret 6

start:
    ; Clear screen
    mov ax, 0xb800
    mov es, ax
    xor di, di
    mov ax, 0x0720
    mov cx, 2000
    cld
    rep stosw

    ; Print 554 at row 5, column 10
    mov ax, 554
    push ax
    mov ax, 10
    push ax  
    mov ax, 5
    push ax
    call printnum_loc
    
    ; Print 2025 at row 20, column 70
    mov ax, 2025
    push ax
    mov ax, 70
    push ax
    mov ax, 20
    push ax
    call printnum_loc

    ; Wait for key
    mov ah, 0
    int 0x16

    mov ax, 0x4c00
    int 0x21