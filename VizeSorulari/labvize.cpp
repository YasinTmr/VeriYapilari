#include <iostream>
#include <iomanip>
#include <limits.h>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    int value;
    int x; //Satır
    int y; //Sütun
    struct Node *left;
    struct Node *right;
    struct Node *top;
    struct Node *down;
};

void createGridList(Node **head, int n);
Node *getCell(Node *head, int row, int column);
void printGridList(Node *head, bool showCoordinate = false);
int rowSum(Node *head,  int rowNum);
int rowSumRec(Node *head,  int rowNum);
int colSum(Node *head,  int colNum);
int colSumRec(Node *head,  int colNum);
int colLength(Node *head,  int colNum);
int colLengthRec(Node *head,  int colNum);
int rowLegth(Node *head,  int rowNum);
int rowLegthRec(Node *nodePtr,  int rowNum);
int rowLargest(Node *head,  int rowNum);
int rowLargestRec(Node *head,  int rowNum);
int rowSmallest(Node *head,  int rowNum);
int rowSmallestRec(Node *head,  int rowNum);
int colLargest(Node *head,  int colNum);
int colLargestRec(Node *head,  int colNum);
int colSmallest(Node *head,  int colNum);
int colSmallestRec(Node *head,  int colNum);
double rowAvg(Node *head,  int rowNum);
double rowAvgRec(Node *head,  int rowNum);
double colAvg(Node *head,  int colNum );
double colAvgRec(Node *head,  int colNum );
int rowFirstColumValue(Node *head,  int rowNum);
int colFirstRowValue(Node *head,  int colNum);
Node * rowFirstColumNode(Node *head,  int rowNum);
Node * colFirstRowNode(Node *head,  int colNum);
int rowLastColumValue(Node *head,  int rowNum);
int colLastRowValue(Node *head,  int colNum);
Node * rowLastColumNode(Node *head,  int rowNum);
Node * colLastRowNode(Node *head,  int colNum);
void printRowSum(Node *head);
void printColSum(Node *head);
void printRowLargest(Node *head);
void printColLargest(Node *head);
void printRowSmallest(Node *head);
void printColSmallest(Node *head);
int sum(Node *head);
double avg(Node *head);
int largest(Node *head);
int smallest(Node *head);
vector<int> rowSumToVector(Node *head);
vector<int> colSumToVector(Node *head);
vector<int> rowLargestToVector(Node *head);
vector<int> colLargestToVector(Node *head);
vector<int> rowSmallestToVector(Node *head);
vector<int> colSmallestToVector(Node *head);
void printRow(Node *head, int rowNum) ;
void printCol(Node *head, int colNum);
vector<int> rowToVector(Node *head,  int rowNum);
vector<int> colToVector(Node *head, int colNum);
void reverseRow(Node *head, int rowNum);
void reverseCol(Node *head, int colNum);
vector<int> reverseRowToVector(Node *head, int rowNum);
vector<int> reverseColToVector(Node *head, int colNum);
void printRowTwoLargest(Node *head, int rowNum);
void printRowTwoSmallest(Node *head, int rowNum);
void printColTwoLargest(Node *head, int colNum);
void printColTwoSmallest(Node *head, int colNum);
void printTwoLargest(Node *head);
void printTwoSmallest(Node *head);

int main() {
    //Grid boyutu
    int n =  8;

    Node *head = nullptr;
    createGridList(&head, n);
    printGridList( head, true );


    return 0;
}

//GridList ilk defa oluşturuluyor
void createGridList(Node **head, int n) {
    Node *prev = nullptr;
    Node *above = nullptr;
    
    int value = 0;
    for(int x = 0; x < n; x ++ ) {
        for(int y = 0; y < n; y ++ ) {
            Node *newNode = new Node;
            newNode->value = value;
            newNode->x = x;
            newNode->y = y;
            
            newNode->top = nullptr;
            newNode->left = nullptr;
            newNode->down = nullptr;
            newNode->right = nullptr;

            if ( x == 0 && y == 0 ) {
                *head = newNode;
                prev = *head;
            }
            else if ( x == 0 && y > 0 ) { //İlk satırsa ve 2. ve sonraki sütunsa
                newNode->left = prev;
                prev->right = newNode;
                prev = newNode;
            }
            else if ( x > 0 && y == 0 ) //İlk satır degilse ve ilk sütunsa
            {
                above = getCell(*head, x - 1, y);
                newNode->top = above;
                above->down = newNode;
                prev = newNode;
            }
            else if ( x > 0 && y > 0 ) //İlk satır degilse ve 2. ve sonraki sütunsa
            {
                above = getCell(*head, x - 1, y);
                newNode->top = above;
                above->down = newNode;
                newNode->left = prev;
                prev->right = newNode;
                prev = newNode;
            }

            value ++;
        }
    }
}

//İlgili satır ve sütundaki hücreyi döndürür
Node *getCell(Node *head, int row, int column) {
    Node *rowPtr = head;
    Node *colPtr = nullptr; 

    //İlgili satıra gelince kadar aşağıya ilerle
    while( rowPtr != nullptr &&  rowPtr->x != row  ) {
        rowPtr = rowPtr->down;
    }

    //Sütun pointeri ilk sütundaki değeri gösterdi
    colPtr =rowPtr; 
    
    //İlgili sütuna gelince kadar sağa ilerle
    while( colPtr != nullptr &&  colPtr->y != column ) {
        colPtr = colPtr->right;
    }

    return colPtr;
}

void printGridList(Node *head, bool showCoordinate) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri

    cout << "Grid İçeriği: " << endl;
    while( rowPtr != nullptr ) {
        colPtr = rowPtr; //İlk sütunu gösterdi
        while( colPtr != nullptr ) {
            if ( showCoordinate ) {
                //Koordinatlı göster seçilmişse 
                cout << setw(4) <<  "(" << colPtr->x << "," << colPtr->y << ") " << setw(2) << colPtr->value;
            }
            else 
            {
                //Koordinatlı göster seçilmemişse 
                cout << setw(3) <<   colPtr->value;
            }
                
            colPtr = colPtr->right;//Bir sonraki sütuna geç
        }
        cout << endl; //Bir alt satıra geç

        rowPtr = rowPtr->down;//Bir sonraki satıra geç
    }
}

//Örnek çözümlü soru 1
//Girilen bir satırdaki değerlerin toplamını bulan program
int rowSum(Node *head,  int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    int sum = 0;

    //İlgili satıra git
    while( rowPtr != nullptr && rowPtr->x != rowNum ) {
         rowPtr = rowPtr->down;//Bir sonraki satıra geç
    } 

    //Satır bulunmuşsa 
    if ( rowPtr != nullptr ) {
        colPtr = rowPtr;  //İlk sütunu gösterdi
        while( colPtr != nullptr ) {
            sum += colPtr->value;
            colPtr = colPtr->right;
        }
    }
    
    return sum;
}

//Girilen bir satırdaki değerlerin toplamını recursive bulan fonksiyon
int rowSumRec(Node *nodePtr,  int rowNum) {
    if ( nodePtr == nullptr ) {
        //Sütun sonuna gelindiyse
        return 0;
    }
    else if ( nodePtr->x != rowNum ) 
    {
        //İlgili satıra gelinmediyse bir satır ilerle
        return rowSumRec(nodePtr->down, rowNum);    
    }
    else if ( nodePtr->x == rowNum ) {
        //İlgili sütuna gelindiyse topla ve saga ilerle
        return nodePtr->value + rowSumRec(nodePtr->right, rowNum);
    }
}

//Soru 1
//Girilen bir sütundaki değerlerin toplamını bulan fonksiyon
int colSum(Node *head,  int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
    int sum = 0;

    
    
    return sum;
}

//Soru 2
//Girilen bir sütundaki değerlerin toplamını recursive bulan fonksiyon
int colSumRec(Node *head,  int colNum) {
    return 0;
}

//Soru 3
//Girilen bir sütundaki eleman sayısını bulan fonksiyon
int colLength(Node *head,  int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
    int length = 0;

    
    
    return length;
}

//Soru 4
//Girilen bir sütundaki eleman sayısını recursive bulan fonksiyon
int colLengthRec(Node *head,  int colNum) {
    return 0;
}

//Soru 5
//Girilen bir satırdaki eleman sayısını bulan fonksiyon
int rowLegth(Node *head,  int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    int length = 0;
    
    return length;
}

//Soru 6
//Girilen bir satırdaki eleman sayısını recursive bulan fonksiyon
int rowLegthRec(Node *nodePtr,  int rowNum) {
    return 0;
}

//Soru 7
//Bir satırdaki en büyük elemanı bulan fonksiyon
int rowLargest(Node *head,  int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    int largest = INT_MIN;

    
    return largest;
}

//Soru 8
//Bir satırdaki en büyük elemanı recursive bulan fonksiyon
int rowLargestRec(Node *head,  int rowNum) {   
    return 0;
}

//Soru 9
//Bir satırdaki en küçük elemanı bulan fonksiyon
int rowSmallest(Node *head,  int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    int smallest = INT_MAX;

    
    return smallest;
}

//Soru 10
//Bir satırdaki en küçük elemanı recursive bulan fonksiyon
int rowSmallestRec(Node *head,  int rowNum) {   
    return 0;
}

//Soru 11
//Bir sütundaki en büyük elemanı bulan fonksiyon
int colLargest(Node *head,  int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
    int largest = INT_MIN;

    
    return largest;
}

//Soru 11
//Bir sütundaki en büyük elemanı recursive bulan fonksiyon
int colLargestRec(Node *head,  int colNum) {   
    return 0;
}

//Soru 12
//Bir sütundaki en küçük elemanı bulan fonksiyon
int colSmallest(Node *head,  int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
    int smallest = INT_MAX;

    
    return smallest;
}

//Soru 13
//Bir satırdaki en küçük elemanı recursive bulan fonksiyon
int colSmallestRec(Node *head,  int colNum) {   
    return 0;
}

//Soru 14
//Girilen bir satırdaki elemanların ortalamasını bulan fonksiyon
double rowAvg(Node *head,  int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    double sum = 0;
    int length = 0;


    return 0;
}

//Soru 15
//Girilen bir satırdaki elemanların ortalamasını recursive bulan fonksiyon
double rowAvgRec(Node *head,  int rowNum) {
    return 0;
}

//Soru 16
//Girilen bir sütundaki elemanların ortalamasını bulan fonksiyon
double colAvg(Node *head,  int colNum ) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
    double sum = 0;
    int length = 0;


    return 0;
}

//Soru 17
//Girilen bir sütundaki elemanların ortalamasını bulan fonksiyon
double colAvgRec(Node *head,  int colNum ) {
    return 0;
}

//Soru 18
//Girilen bir satırın ilk sütundaki düğümün değerini döndüren fonksiyon
int rowFirstColumValue(Node *head,  int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri


    return 0;
}

//Soru 19
//Girilen bir sütunun ilk satırındaki düğümün değerini döndüren fonksiyon
int colFirstRowValue(Node *head,  int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri


    return 0;
}

//Soru 20
//Girilen bir satırın ilk sütundaki düğümünü döndüren fonksiyon
Node * rowFirstColumNode(Node *head,  int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri


    return nullptr;
}

//Soru 21
//Girilen bir sütunun ilk satırındaki düğümünü döndüren fonksiyon
Node * colFirstRowNode(Node *head,  int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri


    return nullptr;
}

//Soru 22
//Girilen bir satırın son sütundaki düğümün değerini döndüren fonksiyon
int rowLastColumValue(Node *head,  int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri


    return 0;
}

//Soru 23
//Girilen bir sütunun son satırındaki düğümün değerini döndüren fonksiyon
int colLastRowValue(Node *head,  int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri


    return 0;
}

//Soru 24
//Girilen bir satırın son sütunundaki düğümünü döndüren fonksiyon
Node * rowLastColumNode(Node *head,  int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri


    return nullptr;
}

//Soru 25
//Girilen bir sütunun son satırındaki düğümünü döndüren fonksiyon
Node * colLastRowNode(Node *head,  int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri


    return nullptr;
}

//Soru 26
//GridList'te her bir satırın toplamını ekrana yazan fonksiyon
void printRowSum(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri

}

//Soru 27
//GridList'te her bir sütunun toplamını ekrana yazan fonksiyon
void printColSum(Node *head) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
}

//Soru 28
//GridList'te her bir satırdaki en büyük değerleri ekrana yazan fonksiyon
void printRowLargest(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri

}

//Soru 29
//GridList'te her bir sütundaki en büyük değerleri ekrana yazan fonksiyon
void printColLargest(Node *head) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
}

//Soru 30
//GridList'te her bir satırdaki en küçük değerleri ekrana yazan fonksiyon
void printRowSmallest(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri

}

//Soru 31
//GridList'te her bir sütundaki en küçük değerleri ekrana yazan fonksiyon
void printColSmallest(Node *head) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
}

//Soru 32
//GridList'te tüm düğümlerin toplamını bulan fonksiyon
int sum(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    int sum = 0;

    return sum;
}

//Soru 33
//GridList'te tüm düğümlerin ortalamasını bulan fonksiyon
double avg(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    double sum = 0;
    int length = 0;

    return 0;
}

//Soru 34
//GridList'te tüm düğümlerin içinden en büyük değeri döndüren fonksiyon
int largest(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    int largest = INT_MIN;

    return largest;
}

//Soru 35
//GridList'te tüm düğümlerin içinden en küçük değeri döndüren fonksiyon
int smallest(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    int smallest = INT_MAX;

    return smallest;
}

//Soru 36
//GridList'te her bir satırın toplamını vektör olarak döndüren fonksiyon
vector<int> rowSumToVector(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    vector<int> vect;

    return vect;
}

//Soru 37
//GridList'te her bir sütunun toplamını vektör olarak döndüren fonksiyon
vector<int> colSumToVector(Node *head) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
    vector<int> vect;

    return vect;
}

//Soru 38
//GridList'te her bir satırdaki en büyük değerleri vektör olarak döndüren fonksiyon
vector<int> rowLargestToVector(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    vector<int> vect;

    return vect;
}

//Soru 39
//GridList'te her bir sütundaki en büyük değerleri vektör olarak döndüren fonksiyon
vector<int> colLargestToVector(Node *head) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
    vector<int> vect;

    return vect;
}

//Soru 40
//GridList'te her bir satırdaki en küçük değerleri vektör olarak döndüren fonksiyon
vector<int> rowSmallestToVector(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    vector<int> vect;
    
    return vect;
}

//Soru 41
//GridList'te her bir sütundaki en küçük değerleri vektör olarak döndüren fonksiyon
vector<int> colSmallestToVector(Node *head) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
    vector<int> vect;
    
    return vect;
}

//Soru 42
//GridList'te girilen bir satırdaki değerleri alt alta ekrana yazan fonksiyon
void printRow(Node *head, int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri

}

//Soru 43
//GridList'te girilen bir sütundaki değerleri alt alta ekrana yazan fonksiyon
void printCol(Node *head, int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
}

//Soru 44
//GridList'te girilen bir satırdaki değerleri vektör olarak döndüren fonksiyon
vector<int> rowToVector(Node *head,  int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    vector<int> vect;
    
    return vect;
}

//Soru 45
//GridList'te girilen bir sütundaki değerleri vektör olarak döndüren fonksiyon
vector<int> colToVector(Node *head, int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
    vector<int> vect;
    
    return vect;
}

//Soru 46
//GridList'te girilen bir satırdaki değerleri sondan başa doğru ekrana yazan fonksiyon
void reverseRow(Node *head, int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri

}

//Soru 47
//GridList'te girilen bir sütundaki değerleri sondan başa doğru ekrana yazan fonksiyon
void reverseCol(Node *head, int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
}

//Soru 48
//GridList'te girilen bir satırdaki değerleri sondan başa doğru vektör olarak döndüren fonksiyon
vector<int> reverseRowToVector(Node *head, int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri
    vector<int> vect;
    
    return vect;
}

//Soru 49
//GridList'te girilen bir sütundaki değerleri sondan başa doğru vektör olarak döndüren fonksiyon
vector<int> reverseColToVector(Node *head, int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri
    vector<int> vect;
    
    return vect;
}

//Soru 50
//GridList'te girilen bir satırdaki en büyük iki değeri ekrana yazdıran fonksiyon
void printRowTwoLargest(Node *head, int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri

}

//Soru 51
//GridList'te girilen bir satırdaki en küçük iki değeri ekrana yazdıran fonksiyon
void printRowTwoSmallest(Node *head, int rowNum) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri

}

//Soru 52
//GridList'te girilen bir sütundaki en büyük iki değeri ekrana yazdıran fonksiyon
void printColTwoLargest(Node *head, int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri

}

//Soru 53
//GridList'te girilen bir sütundaki en büyük iki değeri ekrana yazdıran fonksiyon
void printColTwoSmallest(Node *head, int colNum) {
    Node *rowPtr = nullptr;//Satır pointeri
    Node *colPtr = head;//Sütun pointeri

}

//Soru 54
//GridList'teki en büyük iki değeri ekrana yazdıran fonksiyon
void printTwoLargest(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri

}

//Soru 55
//GridList'teki en küçük iki değeri ekrana yazdıran fonksiyon
void printTwoSmallest(Node *head) {
    Node *rowPtr = head;//Satır pointeri
    Node *colPtr = nullptr;//Sütun pointeri

}