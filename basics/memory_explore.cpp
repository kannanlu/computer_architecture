#include "hexdump.hpp"
#include <iostream>
#include <iomanip>
#include <cstdint>

// Static storage class
// The following will be initialized to zero in the BSS region
int32_t a1;
int32_t a2 = 0;
int32_t a3[100];

// The following will be initialized and placed into the data region
int32_t x1 = 9;
int32_t x2[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

// Functions represent instructions that go into the text region
void func()
{
    static int i = 1; // Static and in data region

    std::cout << "i is " << i << std::endl;
    ++i;
}

int main()

{
    func();
    func();
    func();
    std::cout << std::endl
              << "int32_t a1:" << std::endl;
    hexdump(&a1, sizeof(a1));

    std::cout << std::endl
              << "int32_t x1:" << std::endl;
    hexdump(&x1, sizeof(x1));

    std::cout << std::endl;

    hexdump((void *)main, 0x100);

    return 0;
}