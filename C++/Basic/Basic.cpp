#include <iostream>
template <class T>

concept integral = std::is_integral_v<T>;

template <typename T> 
    requires std::integral<T> || std::floating_point<T>
constexpr double Average(std::vector<T> const& vec) {
    const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    return sum / vec.size();
}

template<typename T>
concept ILabel = requires(T v)
{
    {v.buildHtml()} -> std::convertible_to<std::string>;
};

int main()
{
    std::cout << "Hello World!\n";
}