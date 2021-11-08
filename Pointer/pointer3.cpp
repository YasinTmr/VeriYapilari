#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p;
    p = a;
    cout << setw(10) <<  "*p++ : " << *p++ << endl;  //Önce değer alındı sonra adres artırıldı
    cout << setw(10) << "p - a : " << p - a << endl; //Adres farkı alındı sonuç birim olarak döndü
    cout << setw(10) << "*p : " << *p << endl;       //Kalınan adresteki değer ekrana yazdırıldı
    return 0;
}
