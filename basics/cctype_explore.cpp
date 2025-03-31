#include <iostream>
#include <cctype> // this is the same as <ctype.h>

using namespace std;

void whatis(char ch)
{
    cout << "ch='" << ch << "', isalnum(ch)=" << isalnum(ch) << endl;
    cout << "ch='" << ch << "', isalpha(ch)=" << isalpha(ch) << endl;
    cout << "ch='" << ch << "', iscntrl(ch)=" << iscntrl(ch) << endl;
    cout << "ch='" << ch << "', isdigit(ch)=" << isdigit(ch) << endl;
    cout << "ch='" << ch << "', isgraph(ch)=" << isgraph(ch) << endl;
    cout << "ch='" << ch << "', islower(ch)=" << islower(ch) << endl;
    cout << "ch='" << ch << "', isprint(ch)=" << isprint(ch) << endl;
    cout << "ch='" << ch << "', ispunct(ch)=" << ispunct(ch) << endl;
    cout << "ch='" << ch << "', isspace(ch)=" << isspace(ch) << endl;
    cout << "ch='" << ch << "', isupper(ch)=" << isupper(ch) << endl;
    cout << "ch='" << ch << "', isxdigit(ch)=" << isxdigit(ch) << endl;
}

int main()
{
    char ch = 'B';
    cout << "ch='" << ch << "', ch=" << static_cast<int>(ch) << ", sizeof(ch)=" << sizeof(ch) << endl;

    // To make an integer into a printable character, cast it to a char
    cout << "ch='" << ch << "', tolower(ch)='" << static_cast<char>(tolower(ch)) << "'" << endl;
    cout << "ch='" << ch << "', toupper(ch)='" << (char)toupper(ch) << "'" << endl;

    cout << endl;
    whatis(ch);

    return 0;
}
