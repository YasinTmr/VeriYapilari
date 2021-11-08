#include <iostream>
using namespace std;

int rfib( int n );

int main() {
    int r = rfib( 5 );
    cout << r << endl;
    return 0;
}

//Recursive fibonnaci
int rfib( int n )
{
    if( n <= 1 )
        return n;
    
    return rfib(n-2)+ rfib(n-1);
}

// Recursive
// rfib(5) = rfib(3) + rfib(4)
//   |
// rfib(3) = rfib(1) + rfib(2)
//   |
// rfib(1) = 1

// rfib(2) = rfib(0) +rfib(1) 
//    |
// rfib(0) = 0
//    |
// rfib(1) = 1

//BackTrack
// rfib(1) = 1
// rfib(2) = 0 + 1 = 1
// rfib(3) = 1 + 1 = 2
// rfib(4) = 2 + 1 = 3
// rfib(5) = 2 + 3 = 5






 











