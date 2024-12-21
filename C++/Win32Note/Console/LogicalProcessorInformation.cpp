#include "LogicalProcessorInformation.h"

namespace MyLibrary
{
    typedef BOOL(WINAPI* LPFN_GLPI)(
        PSYSTEM_LOGICAL_PROCESSOR_INFORMATION,
        PDWORD);

    // Helper function to count set bits in the processor mask.
    static DWORD CountSetBits(ULONG_PTR bitMask)
    {
        DWORD LSHIFT = sizeof(ULONG_PTR) * 8 - 1;
        DWORD bitSetCount = 0;
        ULONG_PTR bitTest = (ULONG_PTR)1 << LSHIFT;
        DWORD i;

        for (i = 0; i <= LSHIFT; ++i)
        {
            bitSetCount += ((bitMask & bitTest) ? 1 : 0);
            bitTest /= 2; //shift right
        }
        
        return bitSetCount;
    }

	// Query the processor relationship and cache information.
	// https://learn.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformation
    static int LogicalProcessorInformation()
    {
        LPFN_GLPI glpi;
        BOOL done = 0;
        PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buffer = nullptr;
        PSYSTEM_LOGICAL_PROCESSOR_INFORMATION ptr = nullptr;
        DWORD returnLength = 0;
        DWORD logicalProcessorCount = 0;
        DWORD numaNodeCount = 0;
        DWORD processorCoreCount = 0;
        DWORD processorL1CacheCount = 0;
        DWORD processorL2CacheCount = 0;
        DWORD processorL3CacheCount = 0;
        DWORD processorPackageCount = 0;
        DWORD byteOffset = 0;
        PCACHE_DESCRIPTOR Cache;


        //GetLogicalProcessorInformation is not present on all systems, this example uses the GetProcAddress function instead of calling GetLogicalProcessorInformation directly.
        glpi = (LPFN_GLPI)GetProcAddress(
            GetModuleHandle(L"kernel32"),
            "GetLogicalProcessorInformation");

        if (glpi == nullptr)
        {
            wprintf(L"\nGetLogicalProcessorInformation is not supported.\n");
            return (1);
        }

        while (!done)
        {
            //BOOL result = GetLogicalProcessorInformation(buffer, &returnLength);
            DWORD rc = glpi(buffer, &returnLength);

            if (FALSE == rc)
            {
                if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
                {
                    if (buffer)
                        free(buffer);

                    buffer = (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION)malloc(
                        returnLength);

                    if (nullptr == buffer)
                    {
                        wprintf(L"\nError: Allocation failure\n");
                        return (2);
                    }
                }
                else
                {
                    wprintf(L"\nError %d\n", GetLastError());
                    return (3);
                }
            }
            else
            {
                done = TRUE;
            }
        }

        ptr = buffer;

        while (byteOffset + sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION) <= returnLength)
        {
            if (ptr != nullptr)
            {
                switch (ptr->Relationship)
                {
                case RelationNumaNode:
                    // Non-NUMA systems report a single record of this type.
                    numaNodeCount++;
                    break;

                case RelationProcessorCore:
                    processorCoreCount++;

                    // A hyperthreaded core supplies more than one logical processor.
                    logicalProcessorCount += CountSetBits(ptr->ProcessorMask);
                    break;

                case RelationCache:
                    // Cache data is in ptr->Cache, one CACHE_DESCRIPTOR structure for each cache. 
                    Cache = &ptr->Cache;
                    if (Cache->Level == 1)
                    {
                        processorL1CacheCount++;
                        wprintf(L"L1 Cache Line Size: %d bytes\n", Cache->LineSize);
                        wprintf(L"L1 Cache Block Size: %d bytes\n", Cache->Size);
                    }
                    else if (Cache->Level == 2)
                    {
                        processorL2CacheCount++;
                        wprintf(L"L2 Cache Line Size: %d bytes\n", Cache->LineSize);
                        wprintf(L"L2 Cache Block Size: %d bytes\n", Cache->Size);
                    }
                    else if (Cache->Level == 3)
                    {
                        processorL3CacheCount++;
                        wprintf(L"L3 Cache Line Size: %d bytes\n", Cache->LineSize);
                        wprintf(L"L3 Cache Block Size: %d bytes\n", Cache->Size);
                    }
                    wprintf(L"==========================\n");
                    break;

                case RelationProcessorPackage:
                    // Logical processors share a physical package.
                    processorPackageCount++;
                    break;

                default:
                    wprintf(L"\nError: Unsupported LOGICAL_PROCESSOR_RELATIONSHIP value.\n");
                    break;
                }
                byteOffset += sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
                ptr++;
            }
        }

        wprintf(L"Number of NUMA nodes: %d\n",
            numaNodeCount);
        wprintf(L"Number of physical processor packages: %d\n",
            processorPackageCount);
        wprintf(L"Number of processor cores: %d\n",
            processorCoreCount);
        wprintf(L"Number of logical processors: %d\n",
            logicalProcessorCount);
        wprintf(L"Number of processor L1/L2/L3 caches: %d/%d/%d\n",
            processorL1CacheCount,
            processorL2CacheCount,
            processorL3CacheCount);

        free(buffer);
    }
}