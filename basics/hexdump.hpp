#ifndef HEXDUMP_HPP
#define HEXDUMP_HPP

#include <iostream>
#include <iomanip>
#include <cstddef>

void hexdump(const void *data, size_t size)
{
    const unsigned char *p = static_cast<const unsigned char *>(data);

    for (size_t i = 0; i < size; ++i)
    {
        // Print the address at the start of each row
        if (i % 16 == 0)
        {
            std::cout << "0x" << std::hex << std::setw(8) << std::setfill('0')
                      << reinterpret_cast<uintptr_t>(p + i) << ": ";
        }

        // Print each byte in hex format
        std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<int>(p[i]) << " ";

        // Add a newline every 16 bytes for readability
        if ((i + 1) % 16 == 0 || i == size - 1)
        {
            std::cout << std::endl;
        }
    }
}

#endif // HEXDUMP_HPP