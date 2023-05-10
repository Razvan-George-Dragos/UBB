bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fprintf, fclose, scanf, printf 
import printf msvcrt.dll             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name db '33.txt',0
    descriptor dd -1
    access db 'w',0
    mesaj db 'm=',0
    format_m db '%d',0
    nesaj db 'n=',0
    m dd 0
    n dd 0
    format db '%s',0
    format_out db '%s ',0
    cuv dd '',0
    
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
        push dword mesaj
        push dword format
        call [printf]
        add esp, 4*2
        push dword m
        push dword format_m
        call [scanf]
        add esp, 4*2
        push dword nesaj
        push dword format
        call [printf]
        add esp, 4*2
        push dword n
        push dword format_m
        call [scanf]
        add esp, 4*2
        mov ecx, [m]
        jecxz gol
        repeta:
            push ecx
            push dword cuv
            push dword format
            call [scanf]
            add esp, 4*2
            mov esi, cuv
            mov ebx, 0
            incuvant:
     
                mov dl, 0
                cmp byte[esi], dl
                je gata_cuv
                mov dl, 'a'
                cmp byte[esi], dl
                je voca
                mov dl, 'e'
                cmp byte[esi], dl
                je voce
                mov dl, 'i'
                cmp byte[esi], dl
                je voci
                mov dl, 'o'
                cmp byte[esi], dl
                je voco
                mov dl, 'u'
                cmp byte[esi], dl
                je vocu
                add ebx, 1
                vocu:
                voco:
                voci:
                voce:
                voca:
                inc esi
            loop incuvant
            gata_cuv:
            cmp ebx, [n]
            jb nu_destule
                push dword cuv
                push dword format_out
                push dword [descriptor]
                call [fprintf]
                add esp, 4*3
            nu_destule:
            pop ecx
        loop repeta
        
        
        gol:
        
        final:
        push dword [descriptor]
        call [fclose]
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
