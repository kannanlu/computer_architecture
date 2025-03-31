#include <iomanip>
#include <iostream>

using namespace std;

struct foo
{
    int a;
    int b;
}; // notice that in a C struct, the data are public

class foo2
{
private:
    int a;
    int b;

public:
    void func()
    {
        cout << "a=" << a << ", b=" << b << endl
             << endl;
    }
}; // notice that in a C++ class, the data are by default private

int main()
{
    foo x;
    foo *p;
    foo &ref = x; // alias of x

    p = &x; // p points to x

    foo *&refp = p; // refp is an alias of a pointer to foo

    x.a = 1;
    x.b = 2;
    cout << "a=" << x.a << ", b=" << x.b << endl
         << endl;

    p->a = 23;
    p->b = 99;
    cout << "a=" << p->a << ", b=" << p->b << endl
         << endl;

    cout << "a=" << ref.a << ", b=" << ref.b << endl
         << endl;

    cout << "a=" << refp->a << ", b=" << refp->b << endl
         << endl;

    foo2 y;
    y.a = 3;
    y.b = 4;
    y.func();

    return 0;
}
