#include <iostream>
using namespace std;

int fun(int n);

int main() {
    int r;
    r= fun( 5 );
    cout <<  r << endl;
    r= fun( 5 );
    cout << r << endl;
    return 0;
}

int fun(int n)
{
    static int x = 0;
    if( n > 0 )
    {
        x ++;
        return fun(n-1) + x;
    }

    return 0;
}

// Recursive
// f(5)           
//  |
// f(4) + ___     x = 1
//  |
// f(3) + ___     x = 2
//  |
// f(2) + ___     x = 3
//  |
// f(1) + ___     x = 4
//  |
// f(0) + ___     x = 5
//  |
// f(0) = 0      

// Backtracking
// f(1) = 0 + 5 = 5
//  |
// f(2) = 5 + 5 = 10
//  |
// f(3) = 10 + 5 = 15
//  |
// f(4) = 15 + 5 = 20
//  |
// f(5) = 20 + 5 = 25
