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
        fun(n-1);
        cout << n << " ";
    }
}

//Recurcise
// fun(3) ____
//   |
// fun(2) ___
//   |
// fun(1) ___
//   |
// fun(0) 

// BackTracking 
// fun(1) 1
//   |
// fun(2) 2
//   |
// fun(3) 3
