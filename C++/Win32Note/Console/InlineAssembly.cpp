#include "InlineAssembly.h"

namespace MyLibrary {
#ifdef _M_IX86

    static void InlineAssembly()
    {
        const char* str = "Hello from Inline Assembly!";
        __asm
        {
            mov eax, str; Load the address of 'str' (a string) into the EAX register
            mov ecx, 0; Initialize ECX register to 0, this will be the index(or offset) for iteration

            loop_start :
            mov al, [eax + ecx]; Load the byte at the address(EAX + ECX) into the AL register (AL is the lower byte of EAX)
                inc ecx; Increment ECX by 1 (move to the next character in the string)
                cmp al, 0; Compare AL with 0 (this checks if the current character is NULL, i.e., end of string)
                jne loop_start; Jump back to loop_start if AL != 0 (i.e., continue looping if the character is not NULL)
        }

        // Output the string
        printf("%s\n", str);
    }

    static void InlineAssembly(int a, int b)
    {
        const char* str = "Hello from Inline Assembly!";

        int result = 0;

        __asm {
            mov eax, a; Load a into EAX
            add eax, b; Add b
            mov result, eax; Store result
        }

        // Output the string
        printf("%s\n", str);
    }

#endif
}