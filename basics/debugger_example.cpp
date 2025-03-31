#include <iostream>

void foo(int i)
{
    int j = i * 2;
    std::cout << "i=" << i << ", j=" << j << std::endl;
}

int main()
{
    foo(1);
    foo(2);
    foo(3);
    return 0;
}