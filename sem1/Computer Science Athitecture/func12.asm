bits 32 
segment code use32 class=code public 

global transformare ; export transformare 

transformare:
    mov eax, [esp+4] ;eax <- sirul care reprezinta un numar
    mov esi, eax
    mov ebx, 0 ; rezultatul
    mov edi, 0
    cld
    repeta:
        mov eax, 0
        lodsb ; al <- caracter
        cmp al, '-'
        JE negativ
        cmp al, 0
        JE final

        ;mov al, al-'0'
        sub al, '0'
        mov ecx, eax
        mov eax, ebx
        mov edx, 10
        imul edx ; edx:eax = ebx*10
                 ; conventie > numerele încap toate în dw, deci se poate ignora edx
        mov ebx, eax
        
        add ebx, ecx
        
        
        JMP over
        negativ:
            mov edi, 1 
        over:
    JMP repeta
    final:
        cmp edi, 1
        JE negativ1
        JNE finalTrue
        negativ1:
            mov eax, -1
            imul ebx  ; edx:eax = ebx * (-1)  
            mov ebx, eax
            
finalTrue: 
ret 4*1