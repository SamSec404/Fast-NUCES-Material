 [org 0x0100]

    jmp start

    data: db 0FFH,0FFH,0FFH,0FFH,0FFH, 000h, 000h,000h
    dat: db 0FFH,0FFH,0FFH,0FFH,0FFH, 000h, 000h,000h
    da: db 0FFH,0FFH,0FFH,0FFH,0FFH,000h,000h,000h
    datas: db 0FFH,0FFH,0FFH,0FFH,0FFH,000h,000h,000h

    start:

    and byte[dat+2],000h
    and byte[da+1],000h
    and byte[da+2],000h
    and byte[da+3],000h
    and byte[datas+0],000h
    and byte[datas+1],000h
    and byte[datas+2],000h
    and byte[datas+3],000h
    and byte[datas+4],000h

    mov ax, 0x4c00
    int 0x21