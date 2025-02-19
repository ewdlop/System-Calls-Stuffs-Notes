# README

## 國際公制


### Base on MARCO in C++

define micro
nano 
picto

---

在 C++ 中，您可以使用 `<ratio>` 標頭檔案中定義的 `std::micro`、`std::nano` 和 `std::pico` 來表示對應的 SI 單位前綴。 citeturn0search0這些類型別名分別表示 10⁻⁶、10⁻⁹ 和 10⁻¹² 的比例。例如，`std::micro` 定義為 `std::ratio<1, 1000000>`，表示 10⁻⁶。這些類型可用於在編譯時進行精確的有理數運算。

需要注意的是，`std::micro`、`std::nano` 和 `std::pico` 是在 C++11 標準中引入的。 citeturn0search0

以下是如何在 C++ 中使用這些比例的範例：


```cpp
#include <iostream>
#include <ratio>

int main() {
    std::ratio<1, 1000000> micro = std::micro();
    std::ratio<1, 1000000000> nano = std::nano();
    std::ratio<1, 1000000000000> pico = std::pico();

    std::cout << "micro: " << micro.num << "/" << micro.den << "\n";
    std::cout << "nano: " << nano.num << "/" << nano.den << "\n";
    std::cout << "pico: " << pico.num << "/" << pico.den << "\n";

    return 0;
}
```


此程式將輸出：


```
micro: 1/1000000
nano: 1/1000000000
pico: 1/1000000000000
```


這些類型可用於需要精確定義比例的情境，例如計算時間間隔或物理單位轉換。

請注意，`std::ratio` 類模板提供了在編譯時進行有理數運算的支援，每個實例都精確地表示一個有限的有理數。 citeturn0search0

在使用這些類型時，請確保您的編譯器支援 C++11 或更新的標準。

有關更多詳細資訊，您可以參考 cppreference.com 上的 `std::ratio` 條目。 citeturn0search0

生成時間：2025-02-18 20:29:12。

由 ChatGPT 提供。 

## micro processor, nano preprocessor, and pico preprocessor

在 C++ 中，`std::micro`、`std::nano` 和 `std::pico` 是定義在 `<ratio>` 標頭檔案中的比例類型，分別表示 10⁻⁶、10⁻⁹ 和 10⁻¹²。這些類型可用於需要精確比例的計算，例如時間間隔或物理單位轉換。需要注意的是，這些類型是在 C++11 標準中引入的，因此請確保您的編譯器支援 C++11 或更新的標準。

以下是如何在 C++ 中使用這些比例的範例：


```cpp
#include <iostream>
#include <ratio>

int main() {
    std::ratio<1, 1000000> micro = std::micro();
    std::ratio<1, 1000000000> nano = std::nano();
    std::ratio<1, 1000000000000> pico = std::pico();

    std::cout << "micro: " << micro.num << "/" << micro.den << "\n";
    std::cout << "nano: " << nano.num << "/" << nano.den << "\n";
    std::cout << "pico: " << pico.num << "/" << pico.den << "\n";

    return 0;
}
```


此程式將輸出：


```
micro: 1/1000000
nano: 1/1000000000
pico: 1/1000000000000
```


這些類型可用於需要精確定義比例的情境，例如計算時間間隔或物理單位轉換。

請注意，`std::ratio` 類模板提供了在編譯時進行有理數運算的支援，每個實例都精確地表示一個有限的有理數。

在使用這些類型時，請確保您的編譯器支援 C++11 或更新的標準。

有關更多詳細資訊，您可以參考 cppreference.com 上的 `std::ratio` 條目。

生成時間：2025-02-18 20:29:12。

由 ChatGPT 提供。 

## The micro preprocessor, nano preprocessor, and pico preprocessor.

在 C++ 中，`std::micro`、`std::nano` 和 `std::pico` 是定义在 `<ratio>` 头文件中的比例类型，分别表示 10⁻⁶、10⁻⁹ 和 10⁻¹²。这些类型可用于需要精确比例的计算，例如时间间隔或物理单位转换。需要注意的是，这些类型是在 C++11 标准中引入的，因此请确保您的编译器支持 C++11 或更新的标准。

以下是如何在 C++ 中使用这些比例的示例：


```cpp
#include <iostream>
#include <ratio>

int main() {
    std::ratio<1, 1000000> micro = std::micro();
    std::ratio<1, 1000000000> nano = std::nano();
    std::ratio<1, 1000000000000> pico = std::pico();

    std::cout << "micro: " << micro.num << "/" << micro.den << "\n";
    std::cout << "nano: " << nano.num << "/" << nano.den << "\n";
    std::cout << "pico: " << pico.num << "/" << pico.den << "\n";

    return 0;
}
```


此程序将输出：


```
micro: 1/1000000
nano: 1/1000000000
pico: 1/1000000000000
```


这些类型可用于需要精确定义比例的场景，例如计算时间间隔或物理单位转换。

请注意，`std::ratio` 类模板提供了在编译时进行有理数运算的支持，每个实例都精确地表示一个有限的有理数。

在使用这些类型时，请确保您的编译器支持 C++11 或更新的标准。

有关更多详细信息，您可以参考 cppreference.com 上的 `std::ratio` 条目。

生成时间：2025-02-18 20:29:12。

由 ChatGPT 提供。 

## Come up with the kilo preprocessor micro preprocessor, nano preprocessor, and pico preprocessor, for C family languages.

To define **Kilo Preprocessor, Micro Preprocessor, Nano Preprocessor, and Pico Preprocessor** in C-family languages (C, C++, Objective-C), we can approach this by designing different levels of **preprocessor macros** that define various levels of code processing, optimization, and conditional compilation.

---

### **Preprocessor Tiers**
Each preprocessor level will enable different levels of macro expansion, optimization, and debugging aids:

1. **Kilo Preprocessor (Basic Macro Expansion, Debugging Support)**
2. **Micro Preprocessor (Optimized Code Reduction)**
3. **Nano Preprocessor (Minimalistic Compilation, Tiny Footprint)**
4. **Pico Preprocessor (Extreme Compression, No Debugging)**

---

### **Implementation in C/C++**
We define different levels of preprocessing using `#define` directives to control code expansion at different levels.

```c
#ifndef PREPROCESSOR_LEVEL
    #define PREPROCESSOR_LEVEL 1000  // Default to Kilo Preprocessor
#endif

#if PREPROCESSOR_LEVEL >= 1000
    #define KILO_PREPROCESSOR
    #define ENABLE_DEBUG
    #define ENABLE_LOGGING
    #define VERBOSE_MODE
    #define INLINE_EXPANSION  // Expand functions inline for performance
    #pragma message("Kilo Preprocessor Enabled: Full debug and logging support")
#endif

#if PREPROCESSOR_LEVEL >= 100
    #define MICRO_PREPROCESSOR
    #define OPTIMIZED_CODE
    #undef ENABLE_DEBUG   // No debug mode
    #undef ENABLE_LOGGING // No logging
    #define INLINE_FUNCTIONS
    #pragma message("Micro Preprocessor Enabled: Optimized code, no debugging")
#endif

#if PREPROCESSOR_LEVEL >= 10
    #define NANO_PREPROCESSOR
    #define MINIMAL_CODE
    #undef INLINE_FUNCTIONS
    #pragma message("Nano Preprocessor Enabled: Minimalistic code, no optimizations")
#endif

#if PREPROCESSOR_LEVEL >= 1
    #define PICO_PREPROCESSOR
    #define EXTREME_COMPRESSION
    #undef MINIMAL_CODE
    #pragma message("Pico Preprocessor Enabled: Extreme size reduction, no debugging")
#endif
```

---

### **How to Use It**
You can control the preprocessor level when compiling using `-D` flags.

#### **Example 1: Enabling Kilo Preprocessor**
```bash
gcc -DPREPROCESSOR_LEVEL=1000 main.c -o program
```
This enables debugging, logging, and function inlining.

#### **Example 2: Enabling Nano Preprocessor**
```bash
gcc -DPREPROCESSOR_LEVEL=10 main.c -o program
```
This removes debugging, reduces size, and prevents inline functions.

#### **Example 3: Enabling Pico Preprocessor**
```bash
gcc -DPREPROCESSOR_LEVEL=1 main.c -o program
```
This enables extreme compression by stripping out all unnecessary features.

---

### **Summary of Preprocessor Tiers**
| Preprocessor Level | Features Enabled                          | Features Removed |
|--------------------|------------------------------------------|-----------------|
| **Kilo (1000)**   | Debugging, Logging, Verbose, Inline      | None |
| **Micro (100)**   | Optimized Code, No Debugging/Logging     | Debugging, Logging |
| **Nano (10)**     | Minimal Code, No Inline                  | Optimizations |
| **Pico (1)**      | Extreme Compression                      | Everything Extra |

This setup provides flexibility, allowing different builds of the same source code by toggling preprocessor levels.

Would you like further refinements or additional feature toggles? 🚀
