
.global _syscall_printString
.global _syscall_readString
.global _syscall_readSector
; .extern _interrupt
; .extern _interrupt21ServiceRoutine
; .extern _handleInterrupt21


_syscall_printString:
    push bp
	mov bp, sp

    mov ax, #0x0
    mov bx, [bp + 4]

    int #0x21

    pop bp
	ret

_syscall_readString:
    push bp
	mov bp, sp

    mov ax, #0x1
    mov bx, [bp + 4]

    int #0x21    

    pop bp
	ret

_syscall_readSector:
    push bp
	mov bp, sp

    mov ax, #0x2
    mov bx, [bp + 4]
    mov cx, [bp + 6]
    int #0x21

    pop bp
	ret
