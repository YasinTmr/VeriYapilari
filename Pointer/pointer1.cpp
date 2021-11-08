#include <iostream>
using namespace std;

int main()
{
    char c = 'C';
    int a = 50;
    float f = 3.45;
    cout << "Address of c =" << &c << " Value of c =" << c << endl;
    cout << "Address of a =" << &a << " Value of a =" << a << endl;
    cout << "Address of f =" << &f << " Value of f =" << f << endl;
    return 0;
}