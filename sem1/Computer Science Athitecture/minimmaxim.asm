bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fscanf, printf, fopen, fclose               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    format db '%d',0
    format_out db '%d ',0
    descriptor dd -1
    file_name db 'mimx.txt',0
    nr dd 0
    access db 'r',0
    min dd 0
    max dd 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push dword access
        push dword file_name
        call [fopen]
        add esp, 4*2
        mov [descriptor], eax
        cmp eax, 0
        je final
        push dword nr
        push dword format
        push dword [descriptor]
        call [fscanf]
        add esp, 4*3
        mov ebx, [nr]
        mov edx, [nr]
        mov [min], ebx
        mov [max], edx
        sus:
        push dword nr
        push dword format
        push dword [descriptor]
        call [fscanf]
        add esp, 4*3
        mov eax, [nr]
        cmp eax, -1
        je afara
        cmp eax, [min]
        jge maimarecaminim
        mov [min], eax
        maimarecaminim:
        cmp eax, [max]
        jle maimiccamaxim
        mov [max], eax
        maimiccamaxim:
        jmp sus
        afara:
        final:
        push dword [min]
        push dword format_out
        call [printf]
        add esp, 4*2
        push dword [max]
        push dword format_out
        call [printf]
        add esp, 4*2
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
