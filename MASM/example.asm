.data
    prompts BYTE "Do you enjoy solving puzzles? (y/n)", 0
           BYTE "Do you like helping others? (y/n)", 0
           BYTE "Are you adventurous? (y/n)", 0
           BYTE "Do you prefer working alone? (y/n)", 0
           BYTE "Do you enjoy art and creativity? (y/n)", 0
           BYTE "Do you enjoy reading? (y/n)", 0
           BYTE "Do you get excited by technology? (y/n)", 0
           BYTE "Do you like sports and physical activities? (y/n)", 0
           BYTE "Are you a night owl? (y/n)", 0
           BYTE "Do you enjoy making others laugh? (y/n)", 0
           BYTE "Do you like solving mysteries? (y/n)", 0

    traits BYTE "Logical Thinker", 0
           BYTE "Empathetic", 0
           BYTE "Risk Taker", 0
           BYTE "Independent", 0
           BYTE "Creative", 0
           BYTE "Knowledge Seeker", 0
           BYTE "Tech Enthusiast", 0
           BYTE "Active", 0
           BYTE "Nocturnal", 0
           BYTE "Humorous", 0
           BYTE "Detective Mind", 0

    answers BYTE 11 DUP(?)

.code
main PROC
    ; Initialize registers
    lea esi, prompts      ; Load prompts address
    lea edi, answers      ; Load answers address
    mov ecx, 11           ; Number of questions

ask_loop:
    ; Print question
    mov edx, esi          ; Address of prompt
    call print_string
    ; Get user input (y/n)
    call get_input
    ; Store answer
    mov BYTE PTR [edi], al
    ; Advance pointers
    add esi, 8
    inc edi
    loop ask_loop

    ; Interpret results
    lea esi, answers
    lea edi, traits
    mov ecx, 11

result_loop:
    ; Check answer and print trait if yes
    cmp BYTE PTR [esi], 'y'
    jne skip_trait
    mov edx, edi          ; Address of trait
    call print_string
skip_trait:
    ; Advance pointers
    inc esi
    add edi, 8
    loop result_loop

    ; Exit program
    call exit
    ret

print_string PROC
    ; Call Windows API to print string
    ret
print_string ENDP

get_input PROC
    ; Call Windows API to get input
    ret
get_input ENDP

exit PROC
    ; Exit program
    ret
exit ENDP

main ENDP
END main
