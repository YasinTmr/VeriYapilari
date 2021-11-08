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
    int x = 0;
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
// f(4) + 1       x = 1
//  |
// f(3) + 1       x = 1
//  |
// f(2) + 1       x = 1
//  |
// f(1) + 1       x = 1
//  |
// f(0) + 1       x = 1
//  |
// f(0)       

// Backtracking
// f(1) = 0 + 1 = 1
//  |
// f(2) = 1 + 1 = 2
//  |
// f(3) = 2 + 1 = 3
//  |
// f(4) = 3 + 1 = 4
//  |
// f(5) = 4 + 1 = 5
