#include <iostream>
#include <iomanip>
#include <cstdint> // Standard integer representation
#include <ostream>

void dump(int16_t s16,
          uint16_t u16,
          int32_t s32,
          uint32_t u32)
{
    std::cout << std::setfill('0');
    std::cout << "s16 = 0x" << std::hex << std::setw(4) << s16 << " (" << std::dec << s16 << ")" << std::endl;
    std::cout << "u16 = 0x" << std::hex << std::setw(4) << u16 << " (" << std::dec << u16 << ")" << std::endl;
    std::cout << "s32 = 0x" << std::hex << std::setw(8) << s32 << " (" << std::dec << s32 << ")" << std::endl;
    std::cout << "u32 = 0x" << std::hex << std::setw(8) << u32 << " (" << std::dec << u32 << ")" << std::endl;
}

int main()
{
    int16_t s16;
    uint16_t u16;
    int32_t s32;
    uint32_t u32;
    std::cout << "**************************************" << std::endl;
    std::cout << "**** Set all to 0. ****" << std::endl;
    s16 = 0;
    u16 = 0;
    s32 = 0;
    u32 = 0;
    dump(s16, u16, s32, u32);

    std::cout << "**************************************" << std::endl;
    std::cout << "**** Subtract 1. ****" << std::endl;
    --s16;
    --u16;
    --s32;
    --u32;
    dump(s16, u16, s32, u32);

    std::cout << "**************************************" << std::endl;
    std::cout << "**** Add 1. ****" << std::endl;
    ++s16;
    ++u16;
    ++s32;
    ++u32;
    dump(s16, u16, s32, u32);

    std::cout << "**************************************" << std::endl;
    std::cout << "**** Set all bits but the MSB to 1. ****" << std::endl;
    s16 = 0x7fff;
    u16 = 0x7fff;
    s32 = 0x7fffffff;
    u32 = 0x7fffffff;
    dump(s16, u16, s32, u32);

    std::cout << "**************************************" << std::endl;
    std::cout << "**** Add 1. ****" << std::endl;
    ++s16;
    ++u16;
    ++s32;
    ++u32;
    dump(s16, u16, s32, u32);

    std::cout << "**************************************" << std::endl;
    std::cout << "**** Subtract 1. ****" << std::endl;
    --s16;
    --u16;
    --s32;
    --u32;
    dump(s16, u16, s32, u32);

    return 0;
}