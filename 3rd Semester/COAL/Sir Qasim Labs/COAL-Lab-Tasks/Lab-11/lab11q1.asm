[org 0x0100]
    jmp start

    video_segment equ 0xB800

start:
    mov ax, video_segment
    mov es, ax                  ; Point ES to video memory
    
    mov ax, 12                  ; Row 12
    mov bx, 80                  
    mul bx                      ; AX = row * 80
    add ax, 35                  ; Add column 35
    shl ax, 1                   ; Multiply by 2 (each char = 2 bytes)
    mov di, ax                  ; DI = screen offset
    
    mov ah, 0xFC                ; Attribute: Blinking White on Red
    
    mov al, 'D'                 ; Print 'D'
    mov [es:di], ax
    add di, 2
    
    mov al, 'A'                 ; Print 'A'
    mov [es:di], ax
    add di, 2
    
    mov al, 'N'                 ; Print 'N'
    mov [es:di], ax
    add di, 2
    
    mov al, 'G'                 ; Print 'G'
    mov [es:di], ax
    add di, 2
    
    mov al, 'E'                 ; Print 'E'
    mov [es:di], ax
    add di, 2
    
    mov al, 'R'                 ; Print 'R'
    mov [es:di], ax

    mov ax, 0x4c00              ; Exit to DOS
    int 0x21