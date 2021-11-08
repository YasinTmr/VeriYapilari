#include <iostream>
using namespace std;

int power(int m,int n);
int power1(int m,int n);

int main() {
    int r1 = power( 9, 3 );
    int r2 = power1(3, 4 );
    cout << r1 << endl;
    cout << r2 << endl;
    return 0;
}

//Recursive üs alma
int power(int m, int n)
{
    if(n==0)
        return 1;
    
    return power(m, n-1) * m;
}

int power1(int m, int n)
{
    if( n == 0 )
        return 1;

    if( n % 2 == 0 )
        return power1( m*m, n/2 );

    return m * power1( m*m,(n-1)/2);
}

//Recursive power1 fonksiyonu
// power1(3,4) =  power1(9, 2)
//   |
// power1(9, 2) =  power1(81, 1)
//   |
// power1(81, 1) = 81 * power1(81 * 81, 0)
//   |
// power(81*81, 0) = 1

// Backtrack
// power1(81, 1) = 81 * 1 = 81
// power(9,2) = 81
// power(3,4) = 81



// Recursive power fonksiyonu
// power(9,3) = power(9, 2) * 9
//    |
// power(9,2) = power(9, 1) * 9
//    |
// power(9,1) = power(9, 0) * 9
//    |
// power(9, 0) = 1

// BackTrack
// power(9,1) = 1 * 9 = 9
// power(9,2) = 9 * 9 = 81
// power(9,2) = 81 * 9 = 729












