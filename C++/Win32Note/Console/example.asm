; example.asm
.data
; (Declare any data here if needed)

.code
; Declare the symbol to be available for linking
PUBLIC add_numbers

add_numbers PROC
    ; Function to add two numbers
    ; Parameters:
    ;   - a: in ECX
    ;   - b: in EDX
    ; Returns:
    ;   - sum: in EAX
    mov eax, ecx
    add eax, edx
    ret
add_numbers ENDP

END