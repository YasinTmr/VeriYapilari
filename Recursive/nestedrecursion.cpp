#include <iostream>
using namespace std;

int fun(int n);

int main() {
    int r;
    r=fun( 95 );
    cout << r << endl;
    return 0;
}

int fun(int n)
{
    if( n > 100 )
        return n-10;
    
    return fun(fun(n+11));
}

//Recursion
// fun(95) = fun(fun(106))
// fun(95) = fun(96)
// fun(96) = fun(fun(107))
// fun(96) = fun(97)
// fun(97) = fun(fun(108))
// fun(97) = fun(98)
// fun(98) = fun(fun(109))
// fun(99) = fun(fun(110))
// fun(99) = fun(100)
// fun(100) = fun(fun(111))
// f(100) = f(101)
// f(101) = 91









