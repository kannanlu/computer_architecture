// this is to explore the reference variables
#include <iostream>

using namespace std;

void add_to_int(int &numRef)
{
    cout << "add_to_int(): numRef = " << numRef << endl;
    cout << "add_to_int(): &numRef = " << &numRef << endl;
    numRef += 10;
    cout << "add_to_int(): after adding, numRef = " << numRef << endl
         << endl;
}

int main()
{
    int num = 5;
    int &rnum = num; // rnum is another name for num
    int *p = &num;   // p is a pointer to num

    cout << "main(): num = " << num << endl;
    cout << "main(): &num = " << &num << endl
         << endl;

    cout << "main(): rnum = " << rnum << endl;
    cout << "main(): &rnum = " << &rnum << endl
         << endl;

    add_to_int(num); // notice that one cannot know by appearance that the num is passed by value or by reference
    // this is only a feature in c++, and can cause confusions;
    // also notice that the reference is not dynamic
    cout << "main(): after add_to_int(), num = " << num << ", rnum = " << rnum << endl
         << endl;
    add_to_int(rnum);
    cout << "main(): after add_to_int(), num = " << num << ", rnum = " << rnum << endl;

    return 0;
}