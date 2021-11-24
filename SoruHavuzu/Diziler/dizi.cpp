#include <iostream>
#include <iomanip>
#include <vector> 
#include<limits.h> //INT_MIN ve INT_MAX kullanımı için

using namespace std;
const int COLS = 3;

void printArray(int arr[], int n); //Dizi içini ekrana yazdırır
void printArray(const int arr1[][COLS], int r); //İki boyutlu dizi ekrana yazdırılıyor
void printVector(vector<int> vect); //Vektör içerigini ekrana yazdırır
void printVector(vector<double> vect); //Vektör içerigini ekrana yazdırır
void printVector(vector<vector<int>> vect); //İki boyutlu vektör içerigini ekrana yazdırır
vector<int> arrayToVector(const int arr[], int n); //Vektörü diziye dönüştürür
int nthRepeatingElement(const int arr[], int n, int nCount); //n. tekrar eden dizi elemanını buluyor

int sum(const int arr[], int n); 
int largest(const int arr[], int n); 
int smallest(const int arr[], int n); 
double avg(const int arr[], int n);
bool findElement(const int arr[], int n, int num); 
int indexOf(const int arr[], int n, int num); 
int evenCount(const int arr[], int n); 
int oddCount(const int arr[], int n); 
void largestThree(const int arr[], int n); 
void smallestThree(const int arr[], int n); 
int secondLargest(const int arr[], int n); 
int secondSmallest(const int arr[], int n); 
void sortAsc(int arr[], int n); 
void sortDesc(int arr[], int n); 
void frequency(const int arr[], int n); 
int firstRepeatingElement(const int arr[], int n); 
int secondRepeatingElement(const int arr[], int n); 
int thirdRepeatingElement(const int arr[], int n); 
int findPairSum(const int arr[], int n, int sum); 
int findModSum(const int arr[], int n); 
int findDuplicate(const int arr[], int n); 
void reverse(const int arr[], int n); 
vector<int> reverseToVector(const int arr[], int n);
vector<int> sortAscToVector(const int arr[], int n); 
vector<int> sortDescToVector(const int arr[], int n);
void addMatrix(const int arr1[][COLS], const int arr2[][COLS], int r); 
vector<vector<int>> addMatrixToVector(const int arr1[][COLS], const int arr2[][COLS], int r);
void diffMatrix(const int arr1[][COLS], const int arr2[][COLS], int r);
vector<vector<int>> diffMatrixToVector(const int arr1[][COLS], const int arr2[][COLS], int r);
void extractRow(const int arr1[][COLS], int r, int rowNum);
vector<int> extractRowToVector(const int arr1[][COLS], int r, int rowNum);
void extractColumn(const int arr1[][COLS], int r, int colNum);
vector<int> extractColumnToVector(const int arr1[][COLS], int r, int colNum);
void mainDiagonal(const int arr1[][COLS], int r);
vector<int> mainDiagonalToVector(const int arr1[][COLS], int r);
void secondaryDiagonal(const int arr1[][COLS], int r);
vector<int> secondaryDiagonalToVector(const int arr1[][COLS], int r);
void print2DMatrix(const int arr1[][COLS], int r);
vector<int> convert2DToVector(const int arr1[][COLS], int r);
void printRowsSum(const int arr1[][COLS], int r);
vector<int> rowsSumToVector(const int arr1[][COLS], int r);
void printColumnsSum(const int arr1[][COLS], int r);
vector<int> columnsSumToVector(const int arr1[][COLS], int r);
vector<int> largestRowsElement(const int arr1[][COLS], int r);
vector<int> smallestRowsElement(const int arr1[][COLS], int r);
vector<int> largestColumnsElement(const int arr1[][COLS], int r);
vector<int> smallestColumnsElement(const int arr1[][COLS], int r);
vector<double> avgRowsElement(const int arr1[][COLS], int r);
vector<double> avgColumnsElement(const int arr1[][COLS], int r);
double avgMainDiagonal (const int arr1[][COLS], int r);
double avgSecondaryDiagonal (const int arr1[][COLS], int r);
int largestMainDiagonal (const int arr1[][COLS], int r);
int smallestMainDiagonal (const int arr1[][COLS], int r);
int largestSecondaryDiagonal (const int arr1[][COLS], int r);
int smallestSecondaryDiagonal (const int arr1[][COLS], int r);
int evenCount2DMatrix(const int arr1[][COLS], int r);
int oddCount2DMatrix(const int arr1[][COLS], int r);
int evenSum2DMatrix(const int arr1[][COLS], int r);
int oddSum2DMatrix(const int arr1[][COLS], int r);
vector<int> reverse2DMatrix(const int arr1[][COLS], int r);

int main()
{
     int test1[] = {7, 2, 4, 3, 5, 1, 7, 2, 4};
     int test2[][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
     int test3[][COLS] = {{7, 8, 9}, {1, 2, 3}, {4, 5, 6}};
     int test4[][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
     
     int n =  sizeof(test1)/sizeof(test1[0]); //Dizi boyutu bu şekilde bulunabilir
     int rows2 = sizeof(test2)/sizeof(test2[0]);
     int rows3 = sizeof(test3)/sizeof(test3[0]);
     int rows4 = sizeof(test4)/sizeof(test4[0]);

     int cols2 = sizeof(test2[0])/sizeof(test2[0][0]);
     int cols3 = sizeof(test3[0])/sizeof(test3[0][0]);
     int cols4 = sizeof(test4[0])/sizeof(test4[0][0]);
     
      //cout << sum(test1, n) << endl;
     //cout << largest(test1, n) << endl;
     //cout << smallest(test1, n) << endl;
     //cout << avg(test1, n) << endl;
     //cout << findElement(test1, n, 4) << endl;
     //cout << indexOf(test1, n, 4) << endl;
     //cout << evenCount(test1, n) << endl;
     //cout << oddCount(test1, n) << endl;
     //largestThree(test1, n);
     //smallestThree(test1, n);
     //sortAsc(test1, n);
     //sortDesc(test1, n);
     //frequency(test1, n);
     //cout << firstRepeatingElement(test1, n) << endl;
     //cout << secondRepeatingElement(test1, n) << endl;
     //cout << thirdRepeatingElement(test1, n) << endl;
     //cout << findModSum(test1, n) << endl;
     //cout << findDuplicate(test1, n) << endl;
     //reverse(test1, n);
     //printVector( reverseToVector(test1, n)  );
     //printVector( sortAscToVector(test1, n) );
     //printVector( sortDescToVector(test1, n) );
     //addMatrix(test2, test3, rows2);
     //printVector(addMatrixToVector(test2, test3, rows2));
     //diffMatrix(test2, test3, rows2);
     //printVector(diffMatrixToVector(test2, test3, rows2));
     //extractRow(test2, rows2, 3);
     //printVector(extractRowToVector(test2, rows2, 3));
     //extractColumn(test2, rows2, 1);
     //printVector(extractColumnToVector(test2, rows2, 1));
     //mainDiagonal(test2, rows2);
     //printVector(mainDiagonalToVector(test2, rows2));
     //secondaryDiagonal(test2, rows2);
     //printVector(secondaryDiagonalToVector(test2, rows2));
     //print2DMatrix(test2, rows2);
     //printVector(convert2DToVector(test2, rows2));
     //printRowsSum(test2, rows2);
     //printVector(rowsSumToVector(test2, rows2));
     //printColumnsSum(test2, rows2);
     //printVector(columnsSumToVector(test2, rows2));
     //printVector(largestRowsElement(test4, rows4));
     //printVector(smallestRowsElement(test4, rows4));
     //printVector(largestColumnsElement(test4, rows4));
     //printVector(smallestColumnsElement(test4, rows4));
     //printVector(avgRowsElement(test4, rows4));
     //printVector(avgColumnsElement(test4, rows4));
     //cout << showpoint << avgMainDiagonal(test3, rows3) << endl;
     //cout << showpoint << avgSecondaryDiagonal(test3, rows3) << endl;
     //cout << largestMainDiagonal(test3, rows3) << endl;
     //cout << smallestMainDiagonal(test3, rows3) << endl;
     //cout << largestSecondaryDiagonal(test3, rows3) << endl;
     //cout << smallestSecondaryDiagonal(test3, rows3) << endl;
     //cout << evenCount2DMatrix(test4, rows4) << endl;
     //cout << oddCount2DMatrix(test4, rows4) << endl;
     //cout << evenSum2DMatrix(test4, rows4) << endl;
     //cout << oddSum2DMatrix(test4, rows4) << endl;
     printVector(reverse2DMatrix(test4, rows4));
     return 0;
}

//Dizi içerigini ekrana yazdırır
void printArray(int arr[], int n) {
    cout << endl;
    cout << "Dizi icerigi:\n";
    for(int i = 0; i < n; i ++ ) {
        cout << "arr[" << i << "]=" << arr[i] << endl;
    }
}

//İki boyutlu dizi ekrana yazılıyor
void printArray(const int arr[][COLS], int rows) {
     cout << endl;
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < COLS; y++)
        {
             cout << setw(4) << arr[x][y] << " ";
        }
        cout << endl;
    }
}

//Vektör içerigini ekrana yazdırır
void printVector(vector<int> vect ) {
    cout << endl;
    cout << "Vector icerigi:\n";
    int indis = 0;
    for(int val : vect ) {
        cout << "vect[" << indis << "]=" << vect[indis] << endl;
        indis ++;
    }
}

//Vektör içerigini ekrana yazdırır
void printVector(vector<double> vect ) {
    cout << endl;
    cout << "Vector icerigi:\n";
    cout << showpoint;
    int indis = 0;
    for(int val : vect ) {
        cout << "vect[" << indis << "]=" << vect[indis] << endl;
        indis ++;
    }
}

//İki boyutlu vektör içerigini ekrana yazdırır
void printVector(vector<vector<int>> vect ) {
    cout << "Vector icerigi:\n";
    for(vector<int> tempVect : vect ) {
        for(int val : tempVect ) {
            cout << setw(4) << val << " ";
        }
        cout << endl;
    }
}

//Diziyi vektöre dönüştürüyor
vector<int> arrayToVector(const int arr[], int n) {
    vector<int> vect;
    for(int i = 0; i < n; i ++ ) {
        vect.push_back( arr[i] );
    }

    return vect;
}

//Verilen bir dizide elemanların toplamını bulan fonksiyon
int sum(const int arr[], int n) {
     int sum = 0;
     for(int i = 0; i < n; i ++ ) {
         sum += arr[i];
     }

     return sum;
}

//Verilen bir dizide elemanlardan en büyük olanını bulan fonksiyon
int largest(const int arr[], int n)
{
    //Dizinin ilk elemanı maksimum yapıldı
    int max = arr[0];
 
    //İlk elemanı dışında kalan tüm elemanlar diğerleri ile karışılaştırıldı
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

//Verilen bir dizide elemanlardan en küçük olanını bulan fonksiyon
int smallest(const int arr[], int n) {
    //Dizinin ilk elemanı min  yapıldı
    int min = arr[0];
 
    //İlk elemanı dışında kalan tüm elemanlar diğerleri ile karışılaştırıldı
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

//Verilen bir dizide elemanların ortalamasını bulan fonksiyon
double avg(const int arr[], int n) {
     int sum = 0;
     for(int i = 0; i < n; i ++ ) {
         sum += arr[i];
     }

     return static_cast<double>(sum) / n;
}

//Verilen bir dizi içinde bir tamsayı değeri arayan; sayı bulunduğunda true, bulunamadığında ise false döndüren fonksiyon
bool findElement(const int arr[], int n, int num)
{
     bool find = false;
     for(int i = 0; i < n; i ++ ) {
         if ( arr[i] == num ) {
             find = true;
             break;
         }
     }

     return find;
}

//Verilen bir dizi içinde bir tamsayı değeri arayan; sayı bulunduğunda indis numarasını, bulunamadığında ise -1 döndüren fonksiyon
int indexOf(const int arr[], int n, int num) {
    int index = -1;
    for(int i = 0; i < n; i ++ ) {
         if ( arr[i] == num ) {
             index =  i;
             break;
         }
     }

     return index; 
}

//Verilen bir dizide kaç tane çift sayı olduğunu bulan fonksiyon
int evenCount(const int arr[], int n) {
     int even = 0;
     for(int i = 0; i < n; i ++ ) {
         if ( arr[i] % 2 == 0 )
             even ++;
     }

     return even; 
}

//Verilen bir dizide kaç tane tek sayı olduğunu bulan fonksiyon
int oddCount(const int arr[], int n) {
    int odd = 0;
    for(int i = 0; i < n; i ++ ) {
         if ( arr[i] % 2 == 1 )
             odd ++;
    }

    return odd; 
}

//Verilen bir dizide en büyük üç elemanı tek for döngüsü ile bulup ekrana yazdıran C++ fonksiyonu
void largestThree(const int arr[], int n)
{
    int first, second, third;
    
    //Dizi boyutu 3'den küçükse hata ver
    if (n  < 3) {
        cout << "Dizi boyutu 3\'ten küçük olamaz";
        return;
    }
 
    third = first = second = INT_MIN; //En küçük integer değer
    for(int i = 0; i < n; i++)
    {
        if (arr[i] > first) { // Dizi elemanı birinciden büyükse
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second) { //Dizi elemanı birinci ile ikinci arasındaysa
            third = second;
            second = arr[i];
        }
        else if (arr[i] > third) { //Dizi elemanı üçünçüden büyükse
            third = arr[i];
        }   
    }
 
    cout << "En buyuk uc dizi elemani "
        << first << " " << second << " "
        << third << endl;
}

//Verilen bir dizide en küçük üç elemanı tek for döngüsü ile bulup ekrana yazdıran C++ fonksiyonu
void smallestThree(const int arr[], int n)  {
     int first, second, third;
    
    //Dizi boyutu 3'den küçükse hata ver
    if (n  < 3) {
        cout << "Dizi boyutu 3\'ten küçük olamaz";
        return;
    }
 
    third = first = second = INT_MAX; //En büyük integer değer
    for(int i = 0; i < n; i++)
    {
        if (arr[i] < first) { // Dizi elemanı birinciden küçükse
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] < second) { //Dizi elemanı birinci ile ikinci arasındaysa
            third = second;
            second = arr[i];
        }
        else if (arr[i] < third) { //Dizi elemanı üçünçüden küçükse
            third = arr[i];
        }   
    }
 
    cout << "En kucuk uc dizi elemani "
        << first << " " << second << " "
        << third << endl;   
}

//Verilen bir dizinin elemanlarını küçükten büyüğe sıralayıp ekranda yazdıran C++ fonksiyonu 
void sortAsc(int arr[], int n) {
    //Selection Sort algoritması kullanıldı
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++ ) {
            if (arr[j] < arr[i]) {
                 temp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = temp;
            }
        }
    }

    //Dizi içerigini yazdıran fonksiyona gönderildi
    printArray(arr, n);
}

//Verilen bir dizinin elemanlarını elemanlarını büyükten küçüğe sıralayıp ekranda yazdıran C++ fonksiyonu 
void sortDesc(int arr[], int n) {
    //Selection Sort algoritması kullanıldı
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++ ) {
            if (arr[j] > arr[i]) {
                 temp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = temp;
            }
        }
    }

    //Dizi içerigini yazdıran fonksiyona gönderildi
    printArray(arr, n);
}

//Verilen bir dizide eleman değerlerinin tekrar adetlerini ekrana yazdıran C++ fonksiyonu
void frequency(const int arr[], int n) {
    //Bütün dizi elemanlarını ziyaret edilmesi olarak işaretle
    vector<bool> visited(n, false);
 
    // Dizi elemanları arasında geçiş yapıp 
    //tekrar adetleri (frekansları) bulunur
    for (int i = 0; i < n; i++) {
 
        //Eğer eleman ziyaret edilmişse sayma
        if (visited[i] == true) {
            continue;
        }
            
        // Frekanslar sayılıyor
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true; //Eleman ziyaret edildi olarak sayılıyor
                count++;
            }
        }
        cout << arr[i] << " elemanindan " << count << " tane bulundu" << endl;
    }
}

//n kez tekrar eden dizi elemanı
int nthRepeatingElement(const int arr[], int n, int nthElement) {
    //Bütün dizi elemanlarını ziyaret edilmesi olarak işaretle
    vector<bool> visited(n, false);
    
    //Tekrar eden eleman
    int element = -1;
    
    //İkiden fazla tekrar eden eleman sayısı 
    int repeatCount = 0;

    // Dizi elemanları arasında geçiş yapıp 
    //tekrar adetleri (frekansları) bulunur
    for (int i = 0; i < n; i++) {
 
        //Eğer eleman ziyaret edilmişse sayma
        if (visited[i] == true) {
            continue;
        }
            
        // Frekanslar sayılıyor
        int frequency = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true; //Eleman ziyaret edildi olarak sayılıyor
                frequency++;
            }
        }
        
        //Birden çok tekrar ediyorsa tekrar eden n. elemandır
        if ( frequency > 1 ) {
            repeatCount ++;
        }

        if ( repeatCount == nthElement) {
            element = arr[i];
            break;
        }
    } 

    return element;   
}

//int arr[] = {3, 1, 5, 1, 5, 7, 9, 7, 9} dizisinde ilk tekrar eden elemanı bulan C++ fonksiyonunu
int firstRepeatingElement(const int arr[], int n) {
    return nthRepeatingElement( arr,  n, 1);
}

//int arr[] = {3, 1, 5, 1, 5, 7, 9, 7, 9} dizisinde ikinci tekrar eden elemanı bulan C++ fonksiyonunu
int secondRepeatingElement(const int arr[], int n) {
    return nthRepeatingElement( arr,  n, 2);
}

//int arr[] = {3, 1, 5, 1, 5, 7, 9, 7, 9} dizisinde üçüncü tekrar eden elemanı bulan C++ fonksiyonunu 
int thirdRepeatingElement(const int arr[], int n) {
    return nthRepeatingElement( arr,  n, 3);
}

//Verilen bir dizide toplamları belli bir değer olan ikili eleman sayısını bulan C++ fonksiyonunu
//(Örneğin toplam 5 olsun {1, 4, 3, 2, 3}  dizisinde toplamı 5 olan 3 tane ikili eleman vardır.
int findPairSum(const int arr[], int n, int sum) {
    int sumCount = 0;
    for (int i = 0; i <= n - 1; i++) {
       if (  arr[i] + arr[ i +1 ] == sum  ) {
           sumCount ++;
       }
    }
 
    return sumCount;
}

//Verilen bir dizide ikili eleman çiftlerinin mod toplamını bulan C++ fonksiyonu
//Örneğin {5, 4, 3, 6}  dizisinde sonuç 5 % 4 + 4 % 3 + 3 % 6 = 1 + 1 + 0 = 2’dir) 
int findModSum(const int arr[], int n) {
    int modSum = 0;
    for (int i = 0; i <= n - 1; i++) {
       modSum += arr[i] % arr[ i + 1 ];
    }

    return modSum;
}

//Verilen bir dizide iki kere tekrar eden eleman sayını bulan C++ fonksiyonu yazınız? 
//Söz konusu fonksiyon iki kere tekrar eden eleman olmadığı durumda -1 değerini döndürmelidir (Örneğin {0, 3, 1, 2}  dizisi -1 değer döndürür, {2, 3, 1, 2, 3} dizisi ise 2 değerini, {2, 3, 1, 2, 3, 3} dizisi ise 1 değerini döndürmelidir) 
int findDuplicate(const int arr[], int n) {
    //Bütün dizi elemanlarını ziyaret edilmesi olarak işaretle
    vector<bool> visited(n, false);

    //İkiden fazla tekrar eden eleman sayısı 
    int count = 0;

    // Dizi elemanları arasında geçiş yapıp 
    //tekrar adetleri (frekansları) bulunur
    for (int i = 0; i < n; i++) {
        //Eğer eleman ziyaret edilmişse sayma
        if (visited[i] == true) {
            continue;
        }
            
        // Frekanslar sayılıyor
        int frequency = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true; //Eleman ziyaret edildi olarak sayılıyor
                frequency++;
            }
        }
        
        //İki kere tekrar ediyorsa say
        if ( frequency == 2  ) {
            count ++;
        }
    } 

    return count;      
}

//Verilen bir dizi elemanlarını sondan başa doğru ekranda yazdıran C++ fonksiyonu 
void reverse(const int arr[], int n) {
    for (int i = n - 1; i >= 0; i --) {
        cout << "arr[" << i << "]=" << arr[i] << endl;
    }
}

//Verilen bir dizi elemanlarını ters çevirip (sondan başa doğru) vektör olarak döndüren C++ fonksiyonu
vector<int> reverseToVector(const int arr[], int n) {
    vector<int> vect;
    for (int i = n - 1; i >= 0; i --) {
        vect.push_back( arr[i] );
    }

    return vect;
}

//Verilen bir dizinin elemanlarını küçükten büyüğe sıralayıp vektör olarak döndüren C++ fonksiyonu 
vector<int> sortAscToVector(const int arr[], int n) {
    //Dizinin vektör olarak kopyası alındı
    vector<int> vect = arrayToVector( arr, n );
    
    //Selection Sort algoritması kullanıldı
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++ ) {
            if (vect[j] < vect[i]) {
                 temp = vect[i];
                 vect[i] = vect[j];
                 vect[j] = temp;
            }
        }
    }

    return vect;
}

//Verilen bir dizinin elemanlarını büyükten küçüğe sıralayıp vektör olarak döndüren C++ fonksiyonu
vector<int> sortDescToVector(const int arr[], int n) {
    //Dizinin vektör olarak kopyası alındı
    vector<int> vect = arrayToVector( arr, n );
    
    //Selection Sort algoritması kullanıldı
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++ ) {
            if (vect[j] > vect[i]) {
                 temp = vect[i];
                 vect[i] = vect[j];
                 vect[j] = temp;
            }
        }
    }

    return vect;
}

//3 x 3 (3 satır, 3 sütun) elemana sahip,  iki boyutlu, iki vektörün (aslında iki matrisin) toplamını bulan ve ekrana yazdıran C++ fonksiyonunu yazınız? 
//(Not: r satır sayısını, c sütun sayısını göstermektedir)
void addMatrix(const int arr1[][COLS], const int arr2[][COLS], int r) {
    for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            cout << setw(4) << (arr1[x][y] + arr2[x][y])  << " ";        
        }
        cout << endl;
    }
}

//3 x 3 (3 satır, 3 sütun) elemana sahip,  iki boyutlu, iki vektörün (aslında iki matrisin) toplamını bulan ve iki boyutlu vektör olarak döndüren C++ fonksiyonunu yazınız? 
//(Not: r satır sayısını, c sütun sayısını göstermektedir. Ayrıca iki boyutlu bir vektör vector<vector<int>> vect={{1,2,3},{4,5,6}, {7, 8, 9}}; örneğindeki gibi tanımlanabilir)
vector<vector<int>> addMatrixToVector(const int arr1[][COLS], const int arr2[][COLS], int r) {
    vector<vector<int>> vect(r, vector<int>(COLS)); //r satır ve COLS sütun sayısına sahip iki boyutlu vektör
    for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
           vect[x][y] = arr1[x][y] + arr2[x][y];   
        }
        cout << endl;
    }
    return vect;
}

//3 x 3 (3 satır, 3 sütun)  elemana sahip,  iki boyutlu, iki dizinin (aslında iki matrisin) farkını bulan ve ekrana yazdıran C++ fonksiyonunu yazınız? 
//(Not: r satır sayısını, c sütun sayısını göstermektedir)
void diffMatrix(const int arr1[][COLS], const int arr2[][COLS], int r) {
      for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            cout << setw(4) << (arr1[x][y] - arr2[x][y])  << " ";        
        }
        cout << endl;
    }  
}

//3 x 3 (3 satır, 3 sütun) elemana sahip,  iki boyutlu, iki dizinin (aslında iki matrisin) farkını bulan ve iki boyutlu vektör olarak döndüren C++ fonksiyonunu yazınız? 
//(Not: r satır sayısını, c sütun sayısını göstermektedir. Ayrıca iki boyutlu bir vektör vector<vector<int>> vect={{1,2,3},{4,5,6}, {7, 8, 9}}; örneğindeki gibi tanımlanabilir)
vector<vector<int>> diffMatrixToVector(const int arr1[][COLS], const int arr2[][COLS], int r) {
    vector<vector<int>> vect(r, vector<int>(COLS)); //r satır ve COLS sütun sayısına sahip iki boyutlu vektör
    for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
           vect[x][y] = arr1[x][y] - arr2[x][y];   
        }
        cout << endl;
    }
    return vect;
}

//3 x 3 (3 satır, 3 sütun) elemana sahip,  iki boyutlu dizinin (aslında matrisin) girilen satırını ekrana yazdıran C++ fonksiyonunu yazınız? (Not: r satır sayısını, c sütun sayısını, rowNum satır numarasını göstermektedir.)
void extractRow(const int arr1[][COLS], int r, int rowNum) {
    for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( x + 1 == rowNum ) {
                cout << setw(4) << arr1[x][y]  << " ";        
            } 
        }
    }    
}

//3 x 3 (3 satır, 3 sütun) elemana sahip,  iki boyutlu dizinin (aslında matrisin) girilen satırını vektör olarak döndüren C++ fonksiyonunu yazınız? (Not: r satır sayısını, c sütun sayısını, rowNum satır numarasını göstermektedir. Örneğin ilgili fonksiyon matris = {{1,2,3},{4,5,6}, {7, 8, 9}}; dizisinin 3. Satırı olarak{7, 8, 9}vektörünü döndürülmelidir. Vektörün tek boyutlu olduğuna dikkat edin lütfen.)
vector<int> extractRowToVector(const int arr1[][COLS], int r, int rowNum) {
     vector<int> vect;
     for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( x + 1 == rowNum ) {
                vect.push_back( arr1[x][y] );        
            } 
        }
    }  

    return vect;  
}

//3 x 3 (3 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) girilen sütununu ekrana yazdıran C++ fonksiyonunu yazınız? (Not: r satır sayısını, c sütun sayısını, colNum sütun numarasını göstermektedir.)
void extractColumn(const int arr1[][COLS], int r, int colNum) {
    for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( y + 1 == colNum ) {
                cout << setw(4) << arr1[x][y]  << endl;        
            } 
        }
    }      
}

// |x a a|
// |a x a|
// |a a x|
vector<int> extractColumnToVector(const int arr1[][COLS], int r, int colNum) {
     vector<int> vect;
     for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( y + 1 == colNum ) {
                vect.push_back( arr1[x][y] );        
            } 
        }
    }  

    return vect;  
}

// |x a a|
// |a x a|
// |a a x|
void mainDiagonal(const int arr1[][COLS], int r) {
     if ( r != COLS ) {
         cout << "Kare matrislerin kosegeni alinabilir";
         return;
     }
     
     for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( x == y ) {
                cout << setw(4) << arr1[x][y]  << " ";        
            } 
        }
    }    
}

// |x a a|
// |a x a|
// |a a x|
vector<int> mainDiagonalToVector(const int arr1[][COLS], int r) {
      vector<int> vect;
     if ( r != COLS ) {
         cout << "Kare matrislerin kosegeni alinabilir";
         return vect;
     }
     
     for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( x == y ) {
                 vect.push_back( arr1[x][y] );              
            } 
        }
    } 

     return vect;     
}

// |a a x|
// |a x a|
// |x a a|
void secondaryDiagonal(const int arr1[][COLS], int r) {
    if ( r != COLS ) {
         cout << "Kare matrislerin kosegeni alinabilir";
         return;
     }
      
     for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( x + y == r - 1 ) {
                cout << setw(4) << arr1[x][y]  << " ";        
            } 
        }
    }     
}

// |a a x|
// |a x a|
// |x a a|
vector<int> secondaryDiagonalToVector(const int arr1[][COLS], int r) {
     vector<int> vect;
     if ( r != COLS ) {
         cout << "Kare matrislerin kosegeni alinabilir";
         return vect;
     }

    for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( x + y == r - 1 ) {
                vect.push_back( arr1[x][y] );        
            } 
        }
    }

    return vect;     
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) tüm elemanlarını ekrana satır ve sütün sırasına göre yazdıran C++ fonksiyonunu
void print2DMatrix(const int arr1[][COLS], int r) {
    cout << endl;
    for (int x = 0; x < r; x++)
    {
        for (int y = 0; y < COLS; y++)
        {
             cout << setw(4) << arr1[x][y] << " ";
        }
        cout << endl;
    }
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) tüm elemanlarını satır ve sütün sırasına göre tek boyutlu vektöre dönüştüren C++ fonksiyonunu
vector<int> convert2DToVector(const int arr1[][COLS], int r) {
    vector<int> vect;
    for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            vect.push_back( arr1[x][y] );        
        }
    }

    return vect;
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) her bir satırındaki elemanların toplamını ekrana yazdıran C++ fonksiyonunu
void printRowsSum(const int arr1[][COLS], int r) {
    for (int x = 0; x < r; x++)  {
        int rowSum = 0;
        for (int y = 0; y < COLS; y++) {
            rowSum += arr1[x][y];
        }
        cout << setw(4) << rowSum << endl;
    }   
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) her bir satırındaki elemanların toplamını vektör olarak döndüren C++ fonksiyonunu 
vector<int> rowsSumToVector(const int arr1[][COLS], int r) {
    vector<int> vect;
    for (int x = 0; x < r; x++)  {
        int rowSum = 0;
        for (int y = 0; y < COLS; y++) {
            rowSum += arr1[x][y];
        }
        vect.push_back( rowSum ); 
    } 

    return vect;
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) her bir sütunundaki elemanların toplamını ekrana yazdıran C++ fonksiyonunu 
void printColumnsSum(const int arr1[][COLS], int r) {
    for (int y = 0; y < COLS; y++ )  {
        int colSum = 0;
        for ( int x = 0; x < r; x++ ) {
            colSum += arr1[x][y];
        }
        cout << setw(4) << colSum << endl;
    }     
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) her bir sütunundaki elemanların toplamını vektör olarak döndüren C++ fonksiyonunu 
vector<int> columnsSumToVector(const int arr1[][COLS], int r) {
     vector<int> vect;
     for (int y = 0; y < COLS; y++ )  {
        int colSum = 0;
        for ( int x = 0; x < r; x++ ) {
            colSum += arr1[x][y];
        }
        vect.push_back( colSum ); 
    }   

    return vect;  
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) her bir satırındaki en büyük değerleri vektör olarak döndüren C++ fonksiyonunu 
vector<int> largestRowsElement(const int arr1[][COLS], int r) {
    vector<int> vect;
    for (int x = 0; x < r; x++)  {
        int largest = arr1[x][0];
        for (int y = 1; y < COLS; y++) {
            if ( arr1[x][y] > largest ) {
                largest = arr1[x][y];
            }
            
        }
        vect.push_back( largest ); 
    } 

    return vect;   
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) her bir satırındaki en küçük değerleri vektör olarak döndüren C++ fonksiyonunu 
vector<int> smallestRowsElement(const int arr1[][COLS], int r) {
    vector<int> vect;
    for (int x = 0; x < r; x++)  {
        int smallest = arr1[x][0];
        for (int y = 1; y < COLS; y++) {
            if ( arr1[x][y] < smallest ) {
                smallest = arr1[x][y];
            }
            
        }
        vect.push_back( smallest ); 
    } 

    return vect;   
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) her bir sütunundaki en büyük değerleri vektör olarak döndüren C++ fonksiyonunu 
vector<int> largestColumnsElement(const int arr1[][COLS], int r) {
    vector<int> vect;
    for (int y = 0; y < COLS; y++ )  {
        int largest = arr1[0][y];
        for (int x = 1; x < r; x++) {
            if ( arr1[x][y] > largest ) {
                largest = arr1[x][y];
            }
            
        }
        vect.push_back( largest ); 
    } 

    return vect;    
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) her bir sütunundaki en küçük değerleri vektör olarak döndüren C++ fonksiyonunu 
vector<int> smallestColumnsElement(const int arr1[][COLS], int r) {
    vector<int> vect;
    for (int y = 0; y < COLS; y++ )  {
        int smallest = arr1[0][y];
        for (int x = 1; x < r; x++) {
            if ( arr1[x][y] < smallest ) {
                smallest = arr1[x][y];
            }
            
        }
        vect.push_back( smallest ); 
    } 

    return vect;    
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) her bir satırındaki elemanların ortalama değerleri vektör olarak döndüren C++ fonksiyonunu 
vector<double> avgRowsElement(const int arr1[][COLS], int r) {
    vector<double> vect;
    double avg = 0.0;

    for (int x = 0; x < r; x++)  {
        int rowSum = 0;
        for (int y = 0; y < COLS; y++) {
            rowSum += arr1[x][y];
        }
        avg = static_cast<double>(rowSum) / COLS;
        vect.push_back( avg ); 
    } 

    return vect;    
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) her bir sütunundaki elemanların ortalama değerleri vektör olarak döndüren C++ fonksiyonunu 
vector<double> avgColumnsElement(const int arr1[][COLS], int r) {
     vector<double> vect;
     double avg = 0.0;

     for (int y = 0; y < COLS; y++ )  {
        int colSum = 0;
        for ( int x = 0; x < r; x++ ) {
            colSum += arr1[x][y];
        }
        
        avg = static_cast<double>(colSum) / r;
        vect.push_back( avg ); 
    }   

    return vect;    
}

// |x a a|
// |a x a|
// |a a x|
double avgMainDiagonal (const int arr1[][COLS], int r) {
     if ( r != COLS ) {
         cout << "Kare matrislerin kosegeni alinabilir:";
         return -1;
     }
     
     int sum = 0;
     for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( x == y ) {
                sum += arr1[x][y];        
            } 
        }
    }

    return static_cast<double>(sum) / COLS;
}

// |a a x|
// |a x a|
// |x a a|
double avgSecondaryDiagonal (const int arr1[][COLS], int r) {
    if ( r != COLS ) {
         cout << "Kare matrislerin kosegeni alinabilir:";
         return -1;
     }
    
     int sum = 0;
     for(int x = 0; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( x + y == r - 1 ) {
               sum += arr1[x][y];            
            } 
        }
    } 

    return static_cast<double>(sum) / COLS;
}

// |x a a|
// |a x a|
// |a a x|
int largestMainDiagonal (const int arr1[][COLS], int r) {
     if ( r != COLS ) {
         cout << "Kare matrislerin kosegeni alinabilir:";
         return -1;
     }
     
     int largest = arr1[0][0];
     for(int x = 1; x < r; x ++) {
        for(int y = 1; y < COLS; y ++ ) {
            if ( x == y &&  arr1[x][y] > largest ) {
                largest = arr1[x][y];        
            } 
        }
    }

    return largest;
}

// |x a a|
// |a x a|
// |a a x|
int smallestMainDiagonal (const int arr1[][COLS], int r) {
     if ( r != COLS ) {
         cout << "Kare matrislerin kosegeni alinabilir:";
         return -1;
     }
     
     int smallest = arr1[0][0];
     for(int x = 1; x < r; x ++) {
        for(int y = 1; y < COLS; y ++ ) {
            if ( x == y &&  arr1[x][y] < smallest ) {
                smallest = arr1[x][y];        
            } 
        }
    }

    return smallest;
}

// |a a x|
// |a x a|
// |x a a|
int largestSecondaryDiagonal (const int arr1[][COLS], int r) {
    if ( r != COLS ) {
         cout << "Kare matrislerin kosegeni alinabilir: ";
         return -1;
     }
    
     int largest = arr1[0][COLS-1];
     for(int x = 1; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( x + y == r - 1 &&  arr1[x][y] > largest) {
                largest =arr1[x][y];       
            } 
        }
    }

    return largest;     
}

// |a a x|
// |a x a|
// |x a a|
int smallestSecondaryDiagonal (const int arr1[][COLS], int r) {
    if ( r != COLS ) {
         cout << "Kare matrislerin kosegeni alinabilir: ";
         return -1;
     }
    
     int smallest = arr1[0][COLS-1];
     for(int x = 1; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( x + y == r - 1 &&  arr1[x][y] < smallest ) {
                smallest =arr1[x][y];       
            } 
        }
    }

    return smallest;     
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) elemanlarından çift olanların sayısını bulan C++ fonksiyonunu 
int evenCount2DMatrix(const int arr1[][COLS], int r) {
     int count = 0;
     for(int x = 1; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( arr1[x][y] % 2 == 0 ) {
                count ++;    
            } 
        }
    }

    return count; 
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) elemanlarından tek olanların sayısını bulan C++ fonksiyonunu 
int oddCount2DMatrix(const int arr1[][COLS], int r) {
     int count = 0;
     for(int x = 1; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( arr1[x][y] % 2 == 1 ) {
                count ++;    
            } 
        }
    }

    return count; 
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) elemanlarından çift olanların toplamını bulan C++ fonksiyonunu 
int evenSum2DMatrix(const int arr1[][COLS], int r) {
    int sum = 0;
     for(int x = 1; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( arr1[x][y] % 2 == 0 ) {
                sum += arr1[x][y];   
            } 
        }
    }

    return sum;   
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) elemanlarından tek olanların toplamını bulan C++ fonksiyonunu 
int oddSum2DMatrix(const int arr1[][COLS], int r) {
    int sum = 0;
     for(int x = 1; x < r; x ++) {
        for(int y = 0; y < COLS; y ++ ) {
            if ( arr1[x][y] % 2 == 1 ) {
                sum += arr1[x][y];   
            } 
        }
    }

    return sum;   
}

//4 x 3 (4 satır, 3 sütun)  elemana sahip,  iki boyutlu dizinin (aslında matrisin) sondan başa doğru tek boyutlu vektör olarak döndüren C++ fonksiyonunu 
vector<int> reverse2DMatrix(const int arr1[][COLS], int r) {
    vector<int> vect;
    for(int x = r -1; x >= 0; x --) {
        for(int y = COLS - 1; y >= 0; y -- ) {
            vect.push_back(arr1[x][y]);
        }
    } 

    return vect;
}