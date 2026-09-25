[org 0x0100]


mov ax, 5
sub ax, 5       ; ZF = 1


mov bx, 5
sub bx, 10      ; SF = 1


mov al, 0FFh
add al, 1       ; CF = 1


mov al, 7Fh     
add al, 1       ; OF = 1


mov al, 2       ; PF = 0
inc al          ; PF = 1


mov al, 0Fh   
add al, 1       ; AF = 1


mov ax, 0x4c00
int 0x21