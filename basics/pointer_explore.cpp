#include "hexdump.hpp"
#include <iostream>
#include <iomanip>
#include <cstdint>

// array is always passed by pointer
// void func_a(int a[], int i)
// {
//     std::cout << "sizeof(a)=" << sizeof(a) << std::endl; // this would be the size of the pointer
//     std::cout << "a=" << a << std::endl;
//     std::cout << "&a=" << &a << std::endl;

//     std::cout << "func_a() a[0]=" << a[0] << ", a[1]=" << a[1] << std::endl;
//     a[1] = 0x12345678;
//     std::cout << "func_a() a[0]=" << a[0] << ", a[1]=" << a[1] << std::endl;

//     std::cout << "i=" << i << std::endl;
//     i = 1234;
//     std::cout << "i=" << i << std::endl;
// }

// we can pass the pointer explicitly
void func_a(int *a, int i)
{
    std::cout << "sizeof(a)=" << sizeof(a) << std::endl; // this would be the size of the pointer
    std::cout << "a=" << a << std::endl;
    std::cout << "&a=" << &a << std::endl;

    std::cout << "func_a() a[0]=" << a[0] << ", a[1]=" << a[1] << std::endl;
    a[1] = 0x12345678;
    std::cout << "func_a() a[0]=" << a[0] << ", a[1]=" << a[1] << std::endl;

    std::cout << "i=" << i << std::endl;
    i = 1234;
    std::cout << "i=" << i << std::endl;
}

void pointer_initialization()
{
    float f1 = -1.111;
    float f2 = 123.456;
    float f3 = 789.012;

    std::cout << "f1=" << f1 << ", f2=" << f2 << ", f3=" << f3 << std::endl;
    std::cout << "&f1=" << &f1 << std::endl;
    std::cout << "&f2=" << &f2 << std::endl;
    std::cout << "&f3=" << &f3 << std::endl;

    std::cout << std::endl
              << "******** float *pf1 = &f1; ********" << std::endl;
    float *pf1 = &f1; // pf1 -> f1
    std::cout << "f1=" << f1 << ", f2=" << f2 << ", f3=" << f3 << std::endl;
    std::cout << "pf1=" << pf1 << ", *pf1=" << *pf1 << std::endl;

    std::cout << std::endl
              << "******** float *pf2 = pf1; ********" << std::endl;
    float *pf2 = pf1; // pf1 -> f1
    std::cout << "f1=" << f1 << ", f2=" << f2 << ", f3=" << f3 << std::endl;
    std::cout << "pf1=" << pf1 << ", *pf1=" << *pf1 << std::endl;
    std::cout << "pf2=" << pf2 << ", *pf2=" << *pf2 << std::endl;

    std::cout << std::endl
              << "******** float *pf2 = &f2; ********" << std::endl;
    pf2 = &f2; // pf2 -> f2
    std::cout << "f1=" << f1 << ", f2=" << f2 << ", f3=" << f3 << std::endl;
    std::cout << "pf1=" << pf1 << ", *pf1=" << *pf1 << std::endl;
    std::cout << "pf2=" << pf2 << ", *pf2=" << *pf2 << std::endl;

    std::cout << std::endl
              << "******** float **ppf = &pf2; ********" << std::endl;
    float **ppf = &pf2; // ppf -> pf2 -> f2
    std::cout << "f1=" << f1 << ", f2=" << f2 << ", f3=" << f3 << std::endl;
    std::cout << "pf1=" << pf1 << ", *pf1=" << *pf1 << std::endl;
    std::cout << "pf2=" << pf2 << ", *pf2=" << *pf2 << std::endl;
    std::cout << "ppf=" << ppf << ", *ppf=" << *ppf << ", **ppf=" << **ppf << std::endl;

    std::cout << std::endl
              << "******** **ppf = 3.141; ********" << std::endl;
    **ppf = 3.141; // change the value of f2 to 3.141
    std::cout << "f1=" << f1 << ", f2=" << f2 << ", f3=" << f3 << std::endl;
    std::cout << "pf1=" << pf1 << ", *pf1=" << *pf1 << std::endl;
    std::cout << "pf2=" << pf2 << ", *pf2=" << *pf2 << std::endl;
    std::cout << "ppf=" << ppf << ", *ppf=" << *ppf << ", **ppf=" << **ppf << std::endl;

    std::cout << std::endl
              << "******** pf2 = &f3; ********" << std::endl;
    pf2 = &f3; // ppf -> pf2 -> f3
    std::cout << "f1=" << f1 << ", f2=" << f2 << ", f3=" << f3 << std::endl;
    std::cout << "pf1=" << pf1 << ", *pf1=" << *pf1 << std::endl;
    std::cout << "pf2=" << pf2 << ", *pf2=" << *pf2 << std::endl;
    std::cout << "ppf=" << ppf << ", *ppf=" << *ppf << ", **ppf=" << **ppf << std::endl;

    std::cout << std::endl
              << "******** *ppf = &f1; ********" << std::endl;
    *ppf = &f1; // ppf-> pf2 -> f1
    std::cout << "f1=" << f1 << ", f2=" << f2 << ", f3=" << f3 << std::endl;
    std::cout << "pf1=" << pf1 << ", *pf1=" << *pf1 << std::endl;
    std::cout << "pf2=" << pf2 << ", *pf2=" << *pf2 << std::endl;
    std::cout << "ppf=" << ppf << ", *ppf=" << *ppf << ", **ppf=" << **ppf << std::endl;
}

void pointer_comparison()
{
    std::cout << std::endl
              << "**** comparisons ****" << std::endl;
    constexpr size_t ai_size = 100;
    int ai[ai_size];
    std::cout << "ai=" << ai << std::endl;
    for (size_t i = 0; i < ai_size; ++i)
    {
        ai[i] = 100 + i;
    }
    // we can use > < != == <= >= to compare pointers
    int *p1 = ai;
    int *p2 = &ai[10];
    std::cout << std::endl
              << "**** p1 = ai; p2 = &ai[10]; ****" << std::endl;
    std::cout << "p1=" << p1 << ", p2=" << p2 << std::endl;
    while (p1 < p2) // comparing the address in p1 and the address in p2
    {
        std::cout << "    p1=" << p1 << ", *p1=" << *p1 << std::endl;
        ++p1; // this is pointer arithmetic, add the size of int to p1, which is 4 bit
    }
}

int *pointer_passing(int *p)
{
    // change the thing that p is pointing at
    *p = 99999;
    // return a pointer to an int
    return p + 2;
}

int main()
{
#if 0
    int32_t i = 5; // i is a 32-bit signed integer
    int32_t *p;    // p is a pointer-to-int32_t variable

    p = &i; // the value of p = the address of i's value is stored,
            // we say "p points to i"
            // we say &i is "the address of i"

    int array[3] = {1, 6, 3};
    int xyz = 2;

    std::cout << "i=" << i << ", sizeof(i)=" << sizeof(i) << ", &i=" << &i << std::endl;
    std::cout << "p=" << p << ", sizeof(p)=" << sizeof(p) << ", &p=" << &p << std::endl;
    std::cout << std::endl;
    hexdump(&i, 100);

    std::cout << std::endl;
    // for an array, without indexing, it will return the address of first element
    std::cout << "sizeof(array)=" << sizeof(array) << ", array=" << array << std::endl;
    std::cout << "xyz=" << xyz << std::endl;

    std::cout << std::endl;
    int *pp = nullptr; // points to nothing
    std::cout << "pp=" << pp << std::endl;

    pp = array;                                                     // pp now points to the first element of array
    std::cout << "pp=array=" << pp << ", *pp=" << *pp << std::endl; // we say "*p dereferences"
    ++pp;                                                           // pointer arithmetic, point to the next element
    std::cout << "++pp=" << pp << ", *(++pp)=" << *pp << std::endl;
    pp = &xyz; // pp now points to the value of xyz
    std::cout << "pp=&xyz=" << pp << ", *pp=" << *pp << std::endl;
    pp = &array[2]; // pp now points to the value of array[2]
    std::cout << "pp=&array[2]=" << pp << ", *pp=" << *pp << std::endl;
    *pp = 0x775522;
    std::cout << "pp=" << pp << ", *pp=" << *pp << std::endl;

    std::cout << std::endl;
    func_a(array, xyz); // array is passed by address !
    std::cout << "xyz=" << xyz << std::endl;

    std::cout << std::endl;
    hexdump(array, sizeof(array));
#endif

#if 0
    pointer_initialization();
#endif

#if 0
    pointer_comparison();
#endif

#if 1
    int i = 22;
    int *pi = nullptr;
    std::cout << std::endl
              << "**** i = 22; pi=nullptr; &i=" << &i << " ****" << std::endl;
    std::cout << "   i=" << i << ", pi=" << pi << std::endl;
    pi = pointer_passing(&i);
    std::cout << "   after pi=pointer_passing(p): i=" << i << ", pi=" << pi << std::endl;
#endif

    return 0;
}