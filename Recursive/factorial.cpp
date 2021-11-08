#include <iostream>
using namespace std;

int fact(int n);
int Ifact(int n);

int main() {
    int r=  fact( 5 );
    cout << r << endl;
    return 0;
}

//Recursive faktöriyel
int fact(int n)
{
    if(n==0)
        return 1;
    
    return fact(n-1)*n;
}

//İteratif faktöriyel
int Ifact(int n)
{
    int fact = 1;
    for(int i = 1; i<=n; i++)
        fact = fact * i;

    return fact;
}

// Recursive
// fact(5) = fact(4) * 5
//   |
// fact(4) = fact(3) * 4
//   |
// fact(3) = fact(2) * 3
//   |
// fact(2) = fact(1) * 2
//   |
// fact(1) = fact(0) * 1
//   |
// fact(0)

// Backtrack
// fact(1) = 1 * 1 = 1
// fact(2) = 1 * 2 = 2
// fact(3) = 2 * 3 = 6
// fact(4) = 6 * 4 = 24
// fact(5) = 24 * 5 = 120







