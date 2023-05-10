;Se citeste de la tastatura un sir de caractere (litere mici si litere mari, cifre, caractere speciale, etc).
;Sa se formeze un sir nou doar cu literele mici si un sir nou doar cu literele mari. Sa se afiseze cele 2 siruri rezultate pe ecran.
bits 32

;declarare functii externe si variabile

global _functia

extern _printf;facem cunoscuta functia din c in programul asm

extern _rez1;facem cunoscuta variabila din c in programul asm
extern _rez2;facem cunoscuta variabila din c in programul asm

;segmentele de date si cod trebuie sa fie publice


segment data public data use32
    sir1 dd 0
    sir2 dd 0

segment code public code use32

;functia .asm care pune in _rez1 literele mici din sir
_functia:
    ;Entry code: Crearea cadrului de stiva
    push ebp
    mov ebp,esp


    mov eax, [ebp+12]
    mov [sir1], eax

    mov eax, [ebp+16]
    mov [sir2], eax

    ;mov esi,[ebp+12];la [ebp+12] se afla adresa sirului de caractere citit de la tastatura
    mov edi,_rez1

    mov ecx,0
    mov al,byte[ebp+8];la [ebp+8] se afla numarul de elemente ale sirului de caractere
    mov bl, 2
    mul bl
    mov cx, ax

    repeta:
        mov esi, [sir1]
        lodsb
        stosb
        ;dec esi

        mov esi, [sir2]
        lodsb
        stosb
    loop repeta

    mov esp, ebp
    pop ebp
    ret