bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fclose, fprintf, fscanf, fread, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import fscanf msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    access db 'r',0;'a+',0
    file_name db 'numereexamen.txt',0
    descriptor dd -1
    sir times 50 db 0
    opt dd 8
    format db '%d',0
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
        push dword sir
        push dword format
        push dword [descriptor]
        call [fscanf]
        add esp, 4*3
        mov esi, sir
        mov ebx, 0
        inapoi:
            ;mov dl, ' '
            ;cmp byte[esi], dl
            ;je spatiu
            
            mov dl, 0
            cmp byte[esi], dl
            je gata
            mov dl, 8
            cmp byte[esi], dl
            jae maimare
            mov al, byte[esi]
            mov ah, 0
            cwde
            add ebx, eax
            maimare:
            ;spatiu:
            inc esi
        jmp inapoi
        gata:
        push ebx
        push dword format
        ;push dword [descriptor]
        call [printf]
        add esp, 4*2
        push dword file_name
        push dword [descriptor]
        call [fclose]
        add esp, 4*2
        final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
