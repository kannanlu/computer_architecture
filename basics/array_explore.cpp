#include "hexdump.hpp"
#include <iostream>
#include <iomanip>
#include <cstdint> // Standard integer representation

// Create a variety of variables and print their contents and locations

int main()
{
    int16_t a[10] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};
    int16_t b[10] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99};
    char c[] = {67, 83, 67, 73};
    char d[] = "hello";
    int8_t e[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    //  How big is everything?
    std::cout << "sizeof(a): " << sizeof(a) << std::endl;
    std::cout << "sizeof(b): " << sizeof(b) << std::endl;
    std::cout << "sizeof(c): " << sizeof(c) << std::endl;
    std::cout << "sizeof(d): " << sizeof(d) << std::endl;
    std::cout << "sizeof(e): " << sizeof(e) << std::endl;

    // What does it look like from CPU?
    std::cout << std::endl
              << "int16_t a[10]:" << std::endl;
    hexdump(a, sizeof(a));
    std::cout << std::endl
              << "int16_t b[10]:" << std::endl;
    hexdump(b, sizeof(b));

    std::cout << std::endl
              << "char c[]:" << std::endl;
    hexdump(c, sizeof(c));
    std::cout << std::endl
              << "char d[]:" << std::endl;
    hexdump(d, sizeof(d));

    std::cout << std::endl
              << "int8_t e[4][2]:" << std::endl;
    hexdump(e, sizeof(e));

    return 0;
}