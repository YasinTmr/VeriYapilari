#include <iostream>
using namespace std;

void funA(int n);
void funB(int n);

int main() {
    funA( 20 );
    return 0;
}

void funA(int n)
{
    if( n > 0 )
    {
        cout << n << " ";
        funB( n-1 );
    }
}

void funB(int n)
{
    if( n > 1 )
    {
        cout << n << " ";
        funA( n/2 );
    }
}

// Recursive
// funA(20) 20
//   |
// funB(19) 19
//   |
// funA(9)  9
//   |
// funB(8)  8
//   |
// funA(4)  4
//   |
// funB(3)  3
//   |
// funA(1)  1
//   |
// funB(0)  ___

// BackTracking
// funA(1)  ___
//   |
// funB(3)  ___
//   |
// funA(4)  ___
//   |
// funB(8)  ___
//   |
// funA(9)  ___
//   |
// funB(19) ___
//   |
// funA(20) ___





