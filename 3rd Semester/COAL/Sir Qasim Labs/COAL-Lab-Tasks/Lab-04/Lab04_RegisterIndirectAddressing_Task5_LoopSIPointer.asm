[org 0x0100]

    mov si, nums        ; point si to the first word
    mov cx, 3            ; number of values to add
    mov ax, 0             ; initialize sum to zero

l1:
    add ax, [si]           ; add the number pointed to by si
    add si, 2                ; advance si to the next word
    sub cx, 1                 ; decrement counter
    jnz l1                     ; loop while cx != 0

    mov [result], ax            ; store the final sum

    mov ax, 0x4c00                ; terminate program
    int 0x21

; --- Data Declarations ---
nums:   dw 7, 12, 20
result: dw 0
