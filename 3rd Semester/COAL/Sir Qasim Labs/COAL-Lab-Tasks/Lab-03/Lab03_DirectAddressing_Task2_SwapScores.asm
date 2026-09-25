[org 0x0100]

    mov al, [score1]        ; al = score1 (byte access)
    mov [tempStorage], al   ; tempStorage (low byte) = score1

    mov al, [score2]        ; al = score2
    mov [score1], al        ; score1 = score2

    mov al, [tempStorage]   ; al = original score1 (from tempStorage)
    mov [score2], al        ; score2 = original score1

    mov ax, 0x4c00          ; terminate program
    int 0x21

; --- Data Declarations ---
studentId   dw 101
score1      db 95
score2      db 88
tempStorage dw 0
