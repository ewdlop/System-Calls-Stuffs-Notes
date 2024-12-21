#include "BufferOverflow.h"

namespace MyLibrary
{
    static void RemoteAddFeature(const char* str)
    {
        //https://www.youtube.com/watch?v=NttUBB98zg4

        //Alien: we need to add a feature to the system
        //But you don't have to worry about it
        //We will just write the feature name to the buffer
        //or will we?
        //Me: I'm not sure if the buffer is big enough
        //Alien: Don't worry about it
        //Me: Ok, I trust you
        //Me: (later) Oh no, the buffer is too small
        //Alien: I told you not to worry about it
        //Me: I should have listened
        //Alien: I'm sorry, I can't help you with that
        //Me: I'm doomed
        //Me: they are going to fire me
        //Alien: I'm sorry, I can't help you with that
        //Me: I'm doomed
        //Me: They are't going to upgrade the system so we can't add the feature
        //Alien: I'm sorry, I can't help you with that
        //Me: I'm doomed
        //Me: I'm going to lose my job
        //Alien: I'm sorry, I can't help you with that
        //Me: I'm doomed
        //Alien: They are not helping us out with building a communication system?
        //Me: I'm doomed
        //4chan: My brain have more than 2 neurons
        //Me: I'm doomed
        //Alien: I'm sorry, I can't help you with that
        //Me: I'm doomed
        //Alien: I'm sorry, I can't help you with that
        //Me: I'm doomed


        char buffer[10]{}; // Buffer size is 10 bytes
		wchar_t wbuffer[10]{}; // Buffer size is 10 wide characters

        //C6386 warning: Buffer overrun while writing to 'buffer'
        //Copilot: the writable size is '10' bytes, but '25' bytes might be written.
		//Built error C4996: 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
        //strcpy(buffer, "This string is too long!"); // Writing more than 10 bytes


        // Use strncpy_s to safely copy to the buffer
        strncpy_s(buffer, str, sizeof(buffer) - 1); // Ensure null-termination
        std::cout << buffer << std::endl;

        
        // Use wcsncpy_s to safely copy to the wide buffer
        wcsncpy_s(wbuffer, L"This string is too long!", sizeof(wbuffer) / sizeof(wchar_t) - 1); // Ensure null-termination
        std::wcout << wbuffer << std::endl;
    }
}
