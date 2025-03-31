#include <ios>
#include <iostream>
#include <iomanip> // Add this for std::setw and std::setfill

using namespace std;

size_t getlength(const char *p)
{
    const char *p0 = p;
    while (*p)
    {
        ++p;
    }

    return p - p0;
}

void printStringArray(char *p, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        cout << "p[" << i << "] = " << p[i] << " (" << "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(p[i]) << ","
             << std::noshowbase << std::dec << static_cast<int>(p[i]) << ")" << endl;
    }
}

int main()
{

    char ay[10] = "123456789";
    printStringArray(ay, sizeof(ay));
    cout << "sizeof(ay)=" << sizeof(ay) << ", getlength(ay)=" << getlength(ay) << endl;

    return 0;
}