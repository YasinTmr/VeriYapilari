#include <iostream>
using namespace std;

int main()
{
    int a = 50, b;
    int *p;
    p = &a;
    b = *p;
    cout << "Value of a = " << a << endl;
    cout << "Address of a =" << &a << endl;
    cout << "Value of p =" << p << endl;
    cout << "Value of *p =" << *p << endl;
    cout << "Value of b =" << b << endl;
    cout << "Address of b =" << &b << endl;
    cout << "Address of p =" << &p << endl;
    return 0;
}