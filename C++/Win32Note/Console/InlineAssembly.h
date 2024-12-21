#ifndef INLINEASSEMBLY_H
#define INLINEASSEMBLY_H

#include "pch.h"

namespace MyLibrary {

#ifdef _M_IX86
    static void InlineAssembly();
    static void InlineAssembly(int a, int b);
#endif // _M_IX86
}

#endif