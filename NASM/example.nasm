section .data
    prompts db "Do you enjoy solving puzzles? (y/n)", 0
             db "Do you like helping others? (y/n)", 0
             db "Are you adventurous? (y/n)", 0
             db "Do you prefer working alone? (y/n)", 0
             db "Do you enjoy art and creativity? (y/n)", 0
             db "Do you enjoy reading? (y/n)", 0
             db "Do you get excited by technology? (y/n)", 0
             db "Do you like sports and physical activities? (y/n)", 0
             db "Are you a night owl? (y/n)", 0
             db "Do you enjoy making others laugh? (y/n)", 0
             db "Do you like solving mysteries? (y/n)", 0

    traits db "Logical Thinker", 0
           db "Empathetic", 0
           db "Risk Taker", 0
           db "Independent", 0
           db "Creative", 0
           db "Knowledge Seeker", 0
           db "Tech Enthusiast", 0
           db "Active", 0
           db "Nocturnal", 0
           db "Humorous", 0
           db "Detective Mind", 0

section .bss
    answers resb 11

section .text
    global _start

_start:
    ; Initialize registers
    lea rsi, [prompts]    ; Load prompts address
    lea rdi, [answers]    ; Load answers address
    mov rcx, 11           ; Number of questions

ask_loop:
    ; Print question
    mov rdx, rsi          ; Load address of current question
    call print_string
    ; Get user input (y/n)
    call get_input
    ; Store answer
    mov [rdi], al
    ; Advance pointers
    add rsi, 40           ; Move to the next question (adjust as needed)
    inc rdi
    loop ask_loop

    ; Interpret results
    lea rsi, [answers]
    lea rdi, [traits]
    mov rcx, 11

result_loop:
    ; Check answer and print trait if yes
    cmp byte [rsi], 'y'
    jne skip_trait
    mov rdx, rdi          ; Address of trait
    call print_string
skip_trait:
    ; Advance pointers
    inc rsi
    add rdi, 40
    loop result_loop

    ; Exit program
    call exit

; Helper routines for I/O
print_string:
    mov rax, 1            ; Syscall for write
    mov rdi, 1            ; File descriptor (stdout)
    syscall
    ret

get_input:
    mov rax, 0            ; Syscall for read
    mov rdi, 0            ; File descriptor (stdin)
    syscall
    ret

exit:
    mov rax, 60           ; Syscall for exit
    xor rdi, rdi          ; Exit code 0
    syscall
