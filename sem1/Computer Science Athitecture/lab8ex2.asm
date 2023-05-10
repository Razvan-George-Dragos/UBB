;A text file is given. Read the content of the file, count the number of odd digits and display the result on the screen. The name of text file is defined in the data segment.
bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, fopen, fscanf, fclose
import exit msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import fscanf msvcrt.dll
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data

    max_num equ 100                 ; the maximum number of integers
        
    desc_file dd -1                 
    access_mode db "r", 0             
    file_name db "date.txt", 0   
    
    n dd 0                          
    format db '%d', 0               
    message db 'The number of odd digits is:', 0
    format_out db ' %d', 0      

; our code starts here
segment code use32 class=code
    start:
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp,4*2
        mov [desc_file], eax
        cmp eax,0
        je final
        
        mov ecx, max_num
        jecxz final
        mov ebx,0
        citire:
            push dword n
            push dword format
            push dword [desc_file]
            call [fscanf]
            add esp,4*3
            
            cmp eax,1
            jne printing
            
            mov eax,[n]
            and eax,1
            jz evennr
            add ebx,1
           
            
            evennr:
        loop citire
        
        printing:
            push dword message
            call [printf]
            add esp,4*1
            
            push dword ebx
            push dword format_out
            call [printf]
            add esp,4*2
        
        final:
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program