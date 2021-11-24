#include <iostream>
using namespace std;

int f(int x, int *py, int **ppz);
int sum(int arr[], int n);
int sumRec(int arr[], int n);

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sumRec(arr, n) << endl;
    return 0;
}

int sumRec(const int arr[], int n) {
   if ( n <= 0 )
       return 0;
   else
       return sumRec(arr, n - 1 ) + arr[n - 1];
}