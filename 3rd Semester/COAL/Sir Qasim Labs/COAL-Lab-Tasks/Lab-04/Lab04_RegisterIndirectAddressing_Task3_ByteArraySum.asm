[org 0x0100]

    mov bx, data           ; point bx to the first number
    mov al, [bx]            ; al = first number (7)

    add bx, 1                ; advance to second number
    add al, [bx]              ; al += second number (12)

    add bx, 1                  ; advance to third number
    add al, [bx]                ; al += third number (20)

    add bx, 1                     ; advance to the 4th location
    mov [bx], al                   ; store result (39) in the 4th byte

    mov ax, 0x4c00                ; terminate program
    int 0x21

; --- Data Declarations ---
data: db 7, 12, 20, 0
