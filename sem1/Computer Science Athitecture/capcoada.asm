bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit,fopen,fprintf,scanf,printf,fclose,getchar,fscanf,fread  
import exit msvcrt.dll    
import scanf msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
import fprintf msvcrt.dll
import getchar msvcrt.dll
import fscanf msvcrt.dll   
import fread msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nume_fisier db 'date.txt',0
    sir times 50 db 0
    invers times 50 db 0
    descriptor dd -1
    acces db 'r',0
    format db '%s',0
    
; our code starts here
segment code use32 class=code
    start:
        deschidere:
            push dword acces
            push dword nume_fisier
            call [fopen]
            add esp,4*2
            cmp eax,0
            je final
            mov [descriptor],eax 
            
        citire:
            push dword sir
            push dword format
            push dword [descriptor]
            call [fscanf]
            add esp,4*3
        
        mov esi,sir
        mov bl,0
        mov edx,0
            sf_sir:
                cmp byte[esi],bl
                je cont
                inc esi
                inc edx
                jmp sf_sir
        cont:
        dec esi
        mov edi,invers
        mov bl,0
        inversare:
            cmp edx,0
            je gata
            std
            lodsb
            cld
            stosb
            dec edx
            jmp inversare
        gata:
            push dword invers
            push dword format
            call [printf]
            add esp,4*2
            
        inchidere:
            push dword [descriptor]
            call [fclose]
            add esp,4
        final:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
