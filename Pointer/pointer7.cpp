//Pointer dizisi
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    int *p = numbers;
    int n = sizeof(numbers) / sizeof(numbers[0]);

    for(int i = 0; i < n; i ++  ) {
        cout << setw(10) <<  "*(p + " << i << ") = " << *(p + i) << "\t";
        cout << setw(10) <<  "(p + " << i << ") = " <<  (p + i) << "\t";
        cout << setw(10) <<  "numbers[" << i << "] = " <<  numbers[i] << "\t";
        cout << setw(10) <<  "&numbers[" << i << "] = " <<  &numbers[i] << endl;
    }

    return 0;
}