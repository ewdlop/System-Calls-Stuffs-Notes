#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int y = 7;

    int* p = &x;       // 指向 x
    int*& rp = p;      // 參考到指標
    int** pp = &p;     // 指向指標的指標

    // 加上 &x 到捕捉清單
    auto gremlin = [&rp, q = &rp, &y, &x](int**& rpp) mutable {
        cout << "[before] *p = " << *rp << " (p->" << *rp << ")\n";

        // 身份運算：*&*q 等價於 p
        *&*q = &y;  // 把 p 改為指向 y
        cout << "[mid]    *p = " << *rp << " (p->" << *rp << ")\n";

        // 用參數 rpp（int**&）把外面的 p 指回 x
        *rpp = &x;
        cout << "[after]  *p = " << *rp << " (p->" << *rp << ")\n";

        // 再玩一次 *&：*&*rp 等價於 *p
        int& alias = *&*rp; // 綁到「*p」
        alias += 1;         // 等於 (*p)++；此刻 p 指回 x，所以 x++
    };

    gremlin(pp);

    cout << "x = " << x << ", y = " << y << ", *p = " << *p << "\n";

    // 再示範：泛型 lambda + 指標參考 (auto*&)
    auto rebind = [](auto*& ptr, auto& target) {
        ptr = &target;
    };
    rebind(p, y); // p -> y
    cout << "after rebind: *p = " << *p << " (should be y)\n";
}
