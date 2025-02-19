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
