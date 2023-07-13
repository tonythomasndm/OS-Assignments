        section .data
msg1 : db "Enter a number" , 0x0a, 0
msg2 : db "Enter a string" , 0x0a, 0
s1 : times 64 db 0
fmt1 : db "%s",0
fmt2 : db "Number Value : %s", 0x0a, 0
fmt3 : db "String Value : %s", 0x0a, 0
        
        section .bss
str1: resb 16
number1: resb 4

        section .text
        global main
        extern printf
        extern scanf

main :
        push rbp
        mov rbp , rsp
        lea rdi , [msg1] 
        xor eax , eax
        call printf
        xor eax , eax

        lea rdi, [fmt1]
        lea rsi, [number1]
        lea rdx, [s1]
        xor eax, eax
        call scanf
        xor eax, eax

        lea rdi, [fmt2]
        lea rsi, [number1]
        xor eax, eax
        call printf
        xor eax, eax

        lea rdi , [msg2] 
        xor eax , eax
        call printf
        xor eax , eax

        lea rdi, [fmt1]
        lea rsi, [str1]
        lea rdx, [s1]
        xor eax, eax
        call scanf
        xor eax, eax

        lea rdi, [fmt3]
        lea rsi, [str1]
        xor eax, eax
        call printf
        xor eax, eax
        pop rbp
        ret