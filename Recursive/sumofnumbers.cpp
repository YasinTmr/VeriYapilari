#include <iostream>
using namespace std;

int sum(int n);
int Isum(int n);

int main() {
    int r = sum( 5 );
    cout << r << endl;
    return 0;
}

//Recursive Toplama
int sum(int n)
{
    if(n==0)
        return 0;
    
    return sum(n-1)+n;
}

//Normal toplama
int Isum(int n)
{
    int sum = 0;
    for(int i = 1; i<=n; i++)
       sum =sum + i;

    return sum;
}

//Recursive
// sum(5) = sum(4) + 5
//   |
// sum(4) = sum(3) + 4
//   |
// sum(3) = sum(2) + 3
//   |
// sum(2) = sum(1) + 2
//   |
// sum(1) = sum(0) + 1
//   |
// sum(0) = 0

//Backtrack
// sum(1) = 0 + 1 = 1
// sum(2) = 1 + 2 = 3
// sum(3) = 3 + 3 = 6
// sum(4) = 6 + 4 = 10
// sum(5) = 10 + 5 = 15









