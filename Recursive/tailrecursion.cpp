#include <iostream>
using namespace std;

void fun(int n);

int main() {
    int x = 3;
    fun( x );
    return 0;
}

void fun(int n)
{
    //Recursive sonlandırma şartı
    if( n > 0 )
    {
        cout << n << " ";
        fun(n-1);
    }
}

//Recurcise
// fun(3) 3
//   |
// fun(2) 2
//   |
// fun(1) 1
//   |
// fun(0) 

// BackTracking 
// fun(1) ___
//   |
// fun(2) ___
//   |
// fun(3) ___