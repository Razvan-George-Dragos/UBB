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
    m dd 0
    n dd 0
    nr dd 0
    file_name db 'aaa.txt', 0
    access db 'w', 0
    descriptor dd -1
    format_msj db '%s',0
    mesaj db 'm=',0
    nr_form db '%d',0
    nesaj db 'n=',0
    form_out db '%d ',0
    ten dd 10
; our code starts here
segment code use32 class=code
    start:
        ; ...
        push dword access
        push dword file_name
        call [fopen]
        add esp, 4*2
        mov [descriptor],eax
        cmp eax, 0
        je afara
        push dword mesaj
        push dword format_msj
        call [printf]
        add esp, 4*2
        push dword m
        push dword nr_form
        call [scanf]
        add esp, 4*2
        push dword nesaj
        push dword format_msj
        call [printf]
        add esp, 4*2
        push dword n
        push dword nr_form
        call [scanf]
        add esp, 4*2
        mov ecx, [m]
        jecxz final
        repeta:
            push ecx
            push dword nr
            push dword nr_form
            call [scanf]
            add esp,4*2
            mov eax, [nr]
            push eax
            mov ebx,0
            descompune:
                cmp eax, 0
                je gatanr
                mov edx,0
                div dword [ten]
                test edx, 1
                jnz impar
                    add ebx, 1 ; 1110 0001 = 0000-par
            impar:
            loop descompune
            gatanr:
            pop eax
            cmp ebx, [n]
            jb nusuntdestule
                push eax
                push dword form_out
                push dword [descriptor]
                call [fprintf]
                add esp, 4*3
            nusuntdestule:
            pop ecx
            loop repeta
        
        final:
        afara:
        push dword [descriptor]
        call [fclose]
        add esp, 4
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
