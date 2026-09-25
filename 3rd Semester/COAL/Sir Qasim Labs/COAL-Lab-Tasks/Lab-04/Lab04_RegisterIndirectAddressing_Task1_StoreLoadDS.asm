[org 0x0100]

    mov bx, 0x1200          ; point bx to address 1200h
    mov word [bx], 0x1234   ; store a word value at DS:1200h

    mov bx, 0x1202          ; point bx to address 1202h
    mov word [bx], 0x5678   ; store a word value at DS:1202h

    mov bx, 0x1200          ; point bx back to 1200h
    mov ax, [bx]            ; load value at DS:1200h into ax

    mov bx, 0x1202          ; point bx to 1202h
    mov cx, [bx]            ; load value at DS:1202h into cx

    mov ax, 0x4c00          ; terminate program (check ax/cx in debugger before this line)
    int 0x21
