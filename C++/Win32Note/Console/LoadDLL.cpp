#include "pch.h"

namespace MyLibrary
{
    typedef int(__cdecl* MYPROC)(LPCWSTR);


    //https://learn.microsoft.com/en-us/windows/win32/dlls/using-run-time-dynamic-linking
    static int ExecuteAFunction()
    {
        HINSTANCE hinstLib;
        MYPROC ProcAdd;
        BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;

        // Get a handle to the DLL module.

        hinstLib = LoadLibrary(TEXT("MyPuts.dll"));

        // If the handle is valid, try to get the function address.

        if (hinstLib != NULL)
        {
            ProcAdd = (MYPROC)GetProcAddress(hinstLib, "myPuts");

            // If the function address is valid, call the function.

            if (NULL != ProcAdd)
            {
                fRunTimeLinkSuccess = TRUE;
                (ProcAdd)(L"Message sent to the DLL function\n");
            }
            // Free the DLL module.

            fFreeResult = FreeLibrary(hinstLib);
        }

        // If unable to call the DLL function, use an alternative.
        if (!fRunTimeLinkSuccess)
            printf("Message printed from executable\n");

        return 0;
    }
}