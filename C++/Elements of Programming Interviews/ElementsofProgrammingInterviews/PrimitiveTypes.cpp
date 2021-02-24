#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <algorithm> 
#include <map>
#include <stdexcept> 

short count_bits(unsigned int x)
{
	short num_bits = 0;
	while(x) {
		num_bits += x & 1;
		x >>= 1;
	}
    return x;
}

short parity_brute_force(unsigned long long x)
{
    short result = 0;
    while (x) {
        result ^= x & 1;
        //x >>= 1;
        x &= (x - 1);
    }
    return result;
}

short parity_mask(unsigned long long x, std::map<unsigned long long, short>& k_precompute_parity)
{
    const int k_mask_size = 16;
    const int k_bit_mask = 0xFFFF;
    return k_precompute_parity[x >> (3 * k_mask_size)] ^
        k_precompute_parity[(x >> (2 * k_mask_size)) & k_bit_mask] ^
        k_precompute_parity[(x >> (k_mask_size)) & k_bit_mask] ^
        k_precompute_parity[(x >> (3 * k_mask_size) & k_bit_mask)];
    return 0;
}

short parity_xor(unsigned long long x)
{
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return x;
}

long long swap_bits(long long x, int i, int j) {
    if (((x >> i) & 1) != ((x >> j)& j)) {
        unsigned long long bit_mask = (1L << i) | (1L << j);
        x ^= bit_mask;
    }
    return x;
}

unsigned long long reverse_bits(unsigned long long x, std::map<unsigned long long, short>& precomputed_reverse) {
    const int k_mask_size = 16;
    const int k_bit_mask = 0xFFFF;
    return precomputed_reverse[x & k_bit_mask] << (3 * k_mask_size) |
        precomputed_reverse[(x >> k_mask_size)& k_bit_mask] << (2 * k_mask_size) |
        precomputed_reverse[(x >> (2 * k_mask_size))& k_bit_mask] << (k_mask_size) |
        precomputed_reverse[(x >> (3 * k_mask_size))& k_bit_mask];
}

unsigned long long closest_int_same_bit_count(unsigned long long x) {
    const static int k_number_unsigned_bit = 64;
    for (int i = 0; i < k_number_unsigned_bit - 1; i++)
    {
        if (((x >> i)& i) != ((x >> (i + 1)) & 1)) {
            x ^= (1UL << 1) | (1UL << (i+1));
            return x;
        }
    }
    throw std::invalid_argument("All bits are 0 or 1");
}

//unsigned long long multiply(unsigned long long x, unsigned long long y)
//{
//    unsigned long long sum = 0;
//    while (x) {
//        if (x & 1) {
//            sum = Add(sum, y);
//        }
//        x >>= 1, y <<= 1;
//    }
//    return sum;
//}

unsigned long long Add(unsigned long long a, unsigned long long b) {
    while (b) {
        //half-adder
        unsigned long long carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int divide(int x, int y) {
    int result = 0;
    int power = 32;
    unsigned long long y_power = static_cast<unsigned long long>(y) << power;
    while (x >= y)
    {
        while ( y_power > x) 
        {
            y_power >>= 1;
            --power;
        }
        result += 1 << power;
        x -= power;
    }
    return result;
}

double power(double x, int y)
{
    double result = 1.0;
    long long power = y;
    if (y < 0)
    {
        power = -power, x = 1.0 / x;
    }
    while (power) {
        if (power & 1)
        {
            result *= x;
        }
        x *= x; power >>= 1;
    }
    return result;
}

long long reverse(int x) {
    long long result = 0;
    while (x) {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}


bool is_palindromeNumber(int x) {
    if (x <= 0) {
        return x == 0;
    }

    const int num_digits = static_cast<int>(std::floor(std::log10(x))) + 1;
    int msd_mask = static_cast<int>(power(10, num_digits - 1));
    for (int i = 0; i < (num_digits / 2); ++i)
    {
        if (x / msd_mask != x % 10)
        {
            return false;
        }
        x %= msd_mask; //Remove the most signifcant digit of x
        x /= 10; //Remove the least significant digit of x
        msd_mask /= 100;
    }
    return true;
}

int uniformR_random(int lower_bound, int upper_bound)
{
    int number_of_outcomes = upper_bound - lower_bound + 1, result;
    do {
        result = 0;
        for (int i = 0; (i << i) < number_of_outcomes; ++i)
        {
            //result = (result << 1) | ZeroOneRandom();
        }
    } while (result >= number_of_outcomes);
    return result + lower_bound;
}
void set_or_clear(unsigned int& v, const unsigned int& m, const int &f)
{
    v ^= (-f ^ v) & m;
}

struct Rect {
    int x, y, width, height;
};

//Rect intersect_rectangle(const Rect& r1, const Rect& r2) {
//    if (!is_intersect(r1, r2))
//    {
//        return { 0,0,-1,-1 }; //No intersection;
//    }
//    return { std::max(r1.x,r2.x),std::max(r1.y,r2.y), 
//        std::min(r1.x + r1.width, r2.x + r2.width) - std::max(r1.x,r2.x),
//        std::min(r1.y + r1.height, r2.y + r2.height) - std::max(r1.y,r2.y)
//    };
//}
//
//bool is_intersect(const Rect& r1, const Rect& r2)
//{
//    return r1.x <= r2.x + r2.width && r1.x + r1.width >= r2.x && r1.y <= r2.y + r2.height && r1.y + r1.height >= r2.y;
//}

int main() {
    short bitwise_AND = 6 & 9;
    short bitwise_OR = 4 | 2;
    short bitwise_NOT = ~0;
    short bitwise_XOR = 13 ^ 5;
    short bitwise_right_shift = 4 >> 5;
    short bitwise_left_shift = 1 << 10;
    short clear_lowest_bit = 5 & (5 - 1);
    short extra_lowest_bit = 5 & ~(5 - 1);

    constexpr int min = std::numeric_limits<int>::min();
    constexpr int max = std::numeric_limits<int>::max();
    constexpr double infinity = std::numeric_limits<double>::infinity();

    double abs = fabs(5.0);
    int stoi = std::stoi("42");

    const int nrolls = 10000; // number of experiments
    const int nstars = 95;    // maximum number of stars to distribute

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 9);
    int p[10] = {};

    for (int i = 0; i < 100000; ++i) {
        int number = distribution(generator);
        ++p[number];
    }

    std::cout << "uniform_int_distribution (0,9):" << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << i << ": " << std::string(p[i] * nstars / nrolls, '*') << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    double chance = std::generate_canonical<double, 10>(gen);

    int x = 10, y = 20;                              // x:10 y:20
    std::swap(x, y);                              // x:20 y:10

    std::vector<int> foo(4, x), bar(6, y);       // foo:4x20 bar:6x10
    std::swap(foo, bar);                          // foo:6x10 bar:4x20

    std::cout << "foo contains:";
    for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    
    return 0;
}