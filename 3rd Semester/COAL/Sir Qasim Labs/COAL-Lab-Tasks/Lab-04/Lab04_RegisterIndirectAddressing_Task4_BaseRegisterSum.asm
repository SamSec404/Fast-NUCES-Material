[org 0x0100]

    mov bx, nums        ; point bx to the first word
    mov ax, [bx]         ; ax = first number (7)

    add bx, 2             ; advance to second number
    add ax, [bx]            ; ax += second number (12)

    add bx, 2                ; advance to third number
    add ax, [bx]               ; ax += third number (20)

    mov [result], ax            ; store the total in 'result'

    mov ax, 0x4c00               ; terminate program
    int 0x21

; --- Data Declarations ---
nums:   dw 7, 12, 20
result: dw 0
