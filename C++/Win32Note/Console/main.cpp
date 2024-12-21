#include "pch.h"

int _tmain(int argc, wchar_t* argv[])
{
    _tprintf(_T("Hello, World!\n"));
    wprintf(L"Hello, World!\n");

    std::wstring str = L"Hello, World!";
    std::wcout << str << std::endl;

    #ifdef _M_IX86
        std::cout << "32-bit x86 architecture" << std::endl;
    #elif defined(_M_X64)
        std::cout << "64-bit x64 architecture" << std::endl;
    #elif defined(_M_ARM)
        std::cout << "ARM architecture" << std::endl;
    #elif defined(_M_ARM64)
        std::cout << "ARM64 architecture" << std::endl;
    #else
        std::cout << "Unknown architecture" << std::endl;
    #endif

    return 0;
}