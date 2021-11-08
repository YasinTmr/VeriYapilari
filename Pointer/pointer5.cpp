#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p;
    p = a;
    cout << setw(10) <<  "++*p : " << (++*p) << endl;  //Pointer'ın gösterdiği adresteki değer artırıldı
    cout << setw(10) << "p - a : " << p - a << endl; //Adres farkı 
    cout << setw(10) << "*p : " << *p << endl;       //Pointer adresinin işaret ettiği değer
    return 0;
}