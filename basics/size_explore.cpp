#include <iostream>
#include <iomanip>
#include <cstdint> // Standard integer representation

class tester
{
public:
    int32_t c[2]; // 8 Bytes
    int32_t a;    // 4 Bytes , 8bit is 1Byte
};

int main()
{
    char c;
    short s;
    int i;

    // sizeof is an operator (not a function)
    std::cout << "sizeof(c): " << sizeof(c) << std::endl;
    std::cout << "sizeof(s): " << sizeof(s) << std::endl;
    std::cout << "sizeof(i): " << sizeof(i) << std::endl;

    std::cout << "sizeof(float): " << sizeof(float) << std::endl;
    std::cout << "sizeof(double): " << sizeof(double) << std::endl;
    std::cout << "sizeof(long): " << sizeof(long) << std::endl;
    std::cout << "sizeof(long long): " << sizeof(long long) << std::endl;

    std::cout << "sizeof(int8_t): " << sizeof(int8_t) << std::endl;
    std::cout << "sizeof(int16_t): " << sizeof(int16_t) << std::endl;
    std::cout << "sizeof(int32_t): " << sizeof(int32_t) << std::endl;
    std::cout << "sizeof(int64_t): " << sizeof(int64_t) << std::endl;

    std::cout << "sizeof(int16_t[4]): " << sizeof(int16_t[4]) << std::endl;
    std::cout << "sizeof(tester): " << sizeof(tester) << std::endl;

    return 0;
}