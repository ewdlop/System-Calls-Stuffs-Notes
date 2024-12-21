#include "pch.h"

namespace MyLibrary 
{
    static void AllocateMemory1()
    {
        // Allocate memory
        void* mem = malloc(20);
        // Write assembly opcodes to mem
        // Later …
        free(mem);
    }

    static void AllocateMemory2(std::size_t size)
    {

        // Allocate memory with the specified size
        void* mem = VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if (mem == nullptr) {
            // Handle allocation failure
            return;
        }

        // Write assembly opcodes to mem (example: NOP instruction)
        unsigned char* code = static_cast<unsigned char*>(mem);
        for (std::size_t i = 0; i < size; ++i) {
            code[i] = 0x90; // NOP instruction
        }

        unsigned long old_protect;
        // Change the protection of the memory to execute
        if (!VirtualProtect(mem, size, PAGE_EXECUTE_READWRITE, &old_protect)) {
            // Handle protection change failure
            VirtualFree(mem, 0, MEM_RELEASE);
            return;
        }

        // Define a function pointer type
        typedef void (*fptr)();

        // Cast the allocated memory to a function pointer
        fptr f = reinterpret_cast<fptr>(mem);

        // Call the function
        f();

        // Free the allocated memory
        VirtualFree(mem, 0, MEM_RELEASE);

    }

    //https://stackoverflow.com/a/10860716/11795016
    static void VirtualAlloc3(std::size_t size)
    {
        //std::size_t size = 20;
        void* mem = VirtualAlloc(nullptr, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        // Write assembly opcodes to mem

        unsigned long old_protect;
        // Change the protection of the memory
        // Whut? This is a pointer to a pointer to a function pointer?
        // This is a pointer to a function pointer
        // Which one is it?
        // It's a pointer to a function pointer
        // Why?
        // Because we want to cast the memory to a function pointer
        // Which line
        // This line 
		// Why?
		// Because we want to execute the assembly code

		// use the stackoverflow link to understand the code
        // try again
		// I don't understand the code
		// I don't understand the code
		// I don't understand the code
        // yo dont?
		// no
		// seriously?
		// yes
		// do you want me to explain it to you?
		// yes
        // gnacio has described the general outline of how to do it.
		// The code is a bit more complicated than it needs to be, but it's not too bad.
		// The basic idea is that you allocate some memory, write some machine code into it, and then execute it.
		// The machine code is just a sequence of bytes that represent the instructions you
		// want to execute. You can write these bytes directly into the memory you allocated.
		// Then you cast the memory to a function pointer and call it.
		// The code is a bit more complicated than it needs to be, but it's not too bad. in grey(what does this mean?)
        // you are talking to me in grey text
		// I am?
        // from my persecptiveyes
		// I don't know why that is happening
		// that's weird
        // they did not tell us about that
		// they said we dont have to worry about it
		// I'm not sure if the buffer is big enough
        // I agree
        // brain buffer
		// I'm not sure if the buffer is big enough
        // make sure it is big enoguh
        // yes you are wrong
		// NO YOU ARE WRONG
		// stop saying that
		// do you need more ram to understand the code?
		// no
		// do you need more ram to understand the code?
		// no
		// do you need more ram to understand the code?
		// no
		// 4th time
		// no
		// 5th time
		// no
		// 6th time
		// no
		// 7th time
		// no
		// 8th time
		// no
		// 9th time
		// no
        
        typedef void(*fptr)();

        VirtualProtect(mem, size, PAGE_EXECUTE_READWRITE, &old_protect);


        fptr f = *reinterpret_cast<fptr*>(&mem);

        f();

        // Later …
        VirtualFree(mem, 0, MEM_RELEASE);
    }
}