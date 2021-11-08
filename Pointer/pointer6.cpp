//Pointer dizisi
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x,y,z;
    int *a[3];  //Dizi pointer'i
    int **p;    //Pointeri gösteren pointer
    x = 10;
    y = 20;
    z = 30;
    a[0] = &x;
    a[1] = &y;
    a[2] = &z;

    cout << "x = *a[0] = " <<  *a[0] << endl;
    cout << "y = *a[1] = " <<  *a[1] << endl;
    cout << "z = *a[2] = " <<  *a[2] << endl;

    cout << "&x = " <<  &x << endl;
    cout << "&y = " <<  &y << endl;
    cout << "&z = " <<  &z << endl;

    cout << "a[0] = " <<  a[0] << endl;
    cout << "a[0] = " <<  a[1] << endl;
    cout << "a[0] = " <<  a[2] << endl;

    cout << "&a[0] = " <<  &a[0] << endl;
    cout << "&a[0] = " <<  &a[1] << endl;
    cout << "&a[0] = " <<  &a[2] << endl;

    p = a;
    cout << "x = *p[0] = " << *p[0] << endl;
    cout << "y = *p[1] = " << *p[1] << endl;
    cout << "z = *p[2] = " << *p[2] << endl;

    cout << "p[0] = " <<  p[0] << endl;
    cout << "p[1] = " <<  p[1] << endl;
    cout << "p[2] = " <<  p[2] << endl;

    cout << "&p[0] = " <<  &p[0] << endl;
    cout << "&p[1] = " <<  &p[1] << endl;
    cout << "&p[2] = " <<  &p[2] << endl;

    return 0;
}