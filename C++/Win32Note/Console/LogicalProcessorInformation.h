#ifndef LOGICALPROCESSOR_INFORMATION_H
#define LOGICALPROCESSOR_INFORMATION_H

#include "pch.h"

namespace MyLibrary {
    DWORD CountSetBits(ULONG_PTR bitMask);
	int LogicalProcessorInformation();
}

#endif