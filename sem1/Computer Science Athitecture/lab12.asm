bits 32
global start
import printf msvcrt.dll
import exit msvcrt.dll
import scanf msvcrt.dll
extern printf, exit, scanf

extern transformare
; 2. Se cere sa se citeasca de la tastatura un sir de numere, date in baza 10 ca numere cu semn (se citeste de la tastatura un sir de caractere si in memorie trebuie afisat un sir de numere).

segment data use32 
    mesaj db "sirul este : ", 0
    formatCitire db "%s", 0
    formatAfisare db "%c", 0
    formatDecimal db "%d ", 0
    a db 's' ; caracter de delimitare a segmentului de memorie in care se afla sirul s 
    sir db 0
    b db 't' ; caracter de delimitare a segmentului de memorie in care se afla sirul s 
    numar times 10 db 0
    car db ' '
    ;sirNou db '
segment code use32 class = code public
start:
    
    push dword mesaj
    call [printf]
    add esp, 4
    mov ebx, 0
    
    
    re:
        ; citirea sirului
        push dword sir
        push dword formatCitire
        call [scanf]
        add esp, 4*2
        
        ; intalnirea caracterului de final
        cmp byte[sir + 0], '/'
        JE final
        
        ;apel functie 
        push dword sir
        call transformare
        
        ;afisare numar
        push dword ebx
        push dword formatDecimal
        call [printf]
        add esp, 4*2
        
        ;afisare spatiu
        ;push dword car
        ;push dword formatAfisare
        ;call [printf]
        ;add esp, 4*2
        
    JMP re
    
    final:        
    push dword 0
	call [exit]