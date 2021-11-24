#include <iostream>
#include <limits.h>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    int value;//Değer
    int row;//Satır
    int column;//Sütun
    int frequency;//Tekrar adedi
    bool visited;//Ziyaret edildi mi?
    struct Node *next;
};

struct Node* head = nullptr;
struct Node* head1 = nullptr;
struct Node* head2 = nullptr;
const int COLS = 4;

//Ortak fonksiyonlar
void swap(int *a, int *b);
void push( int data );//Liste başına dügüm ekler
void push(Node **head,  int data );
void printList();//Listeyi ekrana yazdırır
void printList(Node * head);
void append( int data );//Liste sonuna dügüm ekliyor
void append(Node **head, int data );
void append(Node **head, int data, int row, int column );

//Soru başlangıcı
int indexOf( int key );
int indexOfRec(Node *ptr, int key );
int sum();
int sumRec(Node *ptr);
int largest();
int largestRec(Node *ptr);
int smallest();
int smallestRec(Node *ptr);
int length();
int lengthRec(Node *ptr);
int evenCount();
int evenCountRec(Node *ptr);
int oddCount();
int oddCountRec(Node *ptr);
double avg();
void largestThree();
void smallestThree();
void sortInsertionAsc();
void sortInsertionDesc();
void sortBubleAsc();
void sortBubleDesc();
void reverse();
int findPairSum( int sum);
int findModSum();
Node * concateList(Node *head1, Node *head2);
void append( Node **ptr, int * data, int n );
void push(Node **ptr, int * data, int n );
void append( Node **ptr, vector<int> data );
void push(Node **ptr, vector<int> data );
void rotateRight();
void rotateLeft();
bool areIdentical(Node *a, Node *b);
void pairWiseSwap();
vector<int> toVector( Node *head );
void frequency();

//İki boyutlu diziyi LinkList'e yükleme
void append( Node **head, const int arr[][COLS], int r);
void push( Node **head, const int arr[][COLS], int r);
int getValue(Node *head, int row, int column);
int rowCount(Node *head);
int rowCountRec(Node *ptr);
int columnCount(Node *head);
int rowSum(Node *head, int rowNum);
int rowSumRec(Node *ptr, int rowNum);
int columnSum(Node *head, int rowNum);
int columnSumRec(Node *ptr, int colNum);
int rowLargest(Node *head, int rowNum);
int rowLargestRec(Node *ptr, int rowNum);
int rowSmallest(Node *head, int rowNum);
int rowSmallestRec(Node *ptr, int rowNum);
int columnLargest(Node *head, int colNum);
int columnLargestRec(Node *ptr, int colNum);
int columnSmallest(Node *head, int colNum);
int columnSmallestRec(Node *ptr, int colNum);
double rowAvg(Node *head, int rowNum);
double columnAvg(Node *head, int colNum);
void reversePrint (Node *head);
void printRow(Node *head, int rowNum);
void printColumn(Node *head, int colNum);
void printRowReverse(Node *head, int rowNum);
void printColumnReverse(Node *head, int colNum);
bool searchRow(Node *head, int rowNum, int search);
bool searchColumn(Node *head, int colNum, int search);
Node * search(Node *head, int value);
Node * copy(Node *head);

int main()
{
    //Değerler ekleniyor
    append( 12 );
    append( 21 );
    append( 4 );
    append( 27 );
    append( 32 );
    append( 15 );
    append( 5 );
    append( 1 );
    append( 4 );  
    append( 3 );   
    append( 2 );  
    append( 3 );  

    printList();
    


    // cout << indexOf( 4 ) << endl;
    // cout << indexOf( 45 ) << endl;
    // cout << indexOfRec(head, 4) << endl;
    // cout << indexOfRec(head, 45) << endl;
    // cout << sum() << endl;
    // cout << sumRec(head) << endl;
    // cout << largest() << endl;
    // cout << largestRec(head) << endl;
    // cout << smallest() << endl;
    // cout << smallestRec(head) << endl;
    // cout << length() << endl;
    // cout << lengthRec(head) << endl;
    // cout << evenCount() << endl;
    // cout << evenCountRec( head ) << endl;
    // cout << oddCount() << endl;
    // cout << oddCountRec( head ) << endl;
    //cout << avg() << endl;
    //largestThree();
    //smallestThree();

    //sortInsertionAsc();
    //sortInsertionDesc();
    //sortBubleAsc();
    //sortBubleDesc();
    //reverse();
    //printList();
    
    // pairWiseSwap();
    // printList();
    frequency();

    // cout << findPairSum( 5 ) << endl;
    // cout << findPairSum( 25 ) << endl;
    // cout << findModSum() << endl;

    //Yeni Listeler oluşturuluyor
    // append(&head1, 3);*12+
    
    // push(&head1, 6);
    // append(&head1, 4);

    // append(&head2, 1);
    // append(&head2, 4);
    // push(&head2, 5);

    // Node *newList = concateList(head1, head2);
    // printList( newList );

    // int testArr[] = {8, 25, 4, 3, 2};
    // int n = sizeof(testArr)/sizeof(testArr[0]);
    // push( &head, testArr, n );
    // printList();

    // rotateLeft();
    // printList();

    //    İki tane liste oluşturuluyor
    //    int testArr1[] = {1, 2, 3};
    //    int testArr2[] = {1, 2, 3, 4};
    //    vector<int> testVect1 = {1, 2, 3};
    //    vector<int> testVect2 = {1, 2, 3, 4};
    //    Node *testHead1 = nullptr;
    //    Node *testHead2 = nullptr;
    //    push(&testHead1, testArr1, sizeof(testArr2)/sizeof(testArr2[0]) );
    //    push(&testHead2, testArr2, sizeof(testArr2)/sizeof(testArr2[0]) );
    //    push(&testHead1, testVect1 );
    //    push(&testHead2, testVect2 );
    //    cout << "İki Liste eşit mi? : " << areIdentical(testHead1, testHead2) << endl;

    //********************** İki boyutlu dizi testleri  *********************
    Node *headMulti = nullptr;
    int multiArr1[][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20} };

    append( &headMulti, multiArr1,sizeof(multiArr1) / sizeof(multiArr1[0])  ); //4 satır, 4 sütün
    printList( headMulti );
    // cout << getValue(headMulti, 0, 3) << endl;
    // cout << rowCount(headMulti) << endl;
    // cout << rowCountRec(headMulti) << endl;
    // cout << columnCount(headMulti) << endl;
    // cout << rowSum(headMulti, 0) << endl;
    // cout << rowSumRec(headMulti, 0) << endl;
    // cout << columnSum(headMulti, 0) << endl;
    // cout << columnSumRec(headMulti, 0) << endl;
    // cout << rowLargest(headMulti, 1) << endl;
    // cout << rowLargestRec(headMulti, 1) << endl;
    // cout << rowSmallest(headMulti, 1) << endl;
    // cout << rowSmallestRec(headMulti, 1) << endl;
    // cout << columnLargest(headMulti, 1) << endl;
    // cout << columnLargestRec(headMulti, 1) << endl;
    // cout << columnSmallest(headMulti, 1) << endl;
    // cout << columnSmallestRec(headMulti, 1) << endl;
    // cout << rowAvg(headMulti, 1) << endl;
    // cout << columnAvg(headMulti, 1) << endl;
    // reversePrint(headMulti);
    //  printRow(headMulti, 1);
    // printColumn(headMulti, 1);
    // printRowReverse(headMulti, 1);
    // printColumnReverse(headMulti, 1);
    // cout << searchRow(headMulti, 1, 7) << endl;
    // cout << searchColumn(headMulti, 1, 10) << endl;
    
    // Node * resultPtr1 = search(headMulti, 5);
    // if ( resultPtr1 == nullptr )
    //     cout << "Aranılan düğüm bulunamadı" << endl;
    // else
    //     cout << "row: " << resultPtr1->row << ", column=" << resultPtr1->column  << endl;

    Node *copyPtr = copy(headMulti);
    printList(copyPtr);
    
    
    cout << endl << "END"<<endl;

    return 0;
}

//İki int değişkenin değerlerini karşılıklı değiştiriyor
void swap(int *a, int *b){
	int x = *a;
	*a = *b;
	*b = x;
}

//Liste başına dügüm ekler
void push( int data ) { 
    Node * newNode = new Node;
    newNode->value = data;
    newNode->next = head;

    head = newNode;
}

//Liste başına dügüm ekler
void push(Node **head,  int data ) { 
    Node * newNode = new Node;
    newNode->value = data;
    newNode->next = *head;

    *head = newNode;
}

//Liste sonuna dügüm ekler
void append( int data ) { 
    Node *newNode; //Yeni dügüm
    Node *temp;//Liste içinde dolaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;
    newNode->next = nullptr;

    if ( head == nullptr ) {
        //Liste boşsa
        head = newNode;
    }
    else {
        //İşaretçi liste başını gösterir
        temp = head;

        while ( temp->next ) {
            temp = temp->next;
        }

        //En son dügüm yeni ekleneni gösterdi
        temp->next = newNode;
    }
}

//Liste sonuna dügüm ekler
void append(Node **head, int data, int row, int column ) { 
    Node *newNode; //Yeni dügüm
    Node *temp;//Liste içinde dolaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;
    newNode->row = row;
    newNode->column = column;
    newNode->next = nullptr;

    if ( *head == nullptr ) {
        //Liste boşsa
        *head = newNode;
    }
    else {
        //İşaretçi liste başını gösterir
        temp = *head;

        while ( temp->next ) {
            temp = temp->next;
        }

        //En son dügüm yeni ekleneni gösterdi
        temp->next = newNode;
    }
}

void append(Node **head, int data ) { 
    Node *newNode; //Yeni dügüm
    Node *temp;//Liste içinde dolaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;
    newNode->next = nullptr;

    if ( *head == nullptr ) {
        //Liste boşsa
        *head = newNode;
    }
    else {
        //İşaretçi liste başını gösterir
        temp = *head;

        while ( temp->next ) {
            temp = temp->next;
        }

        //En son dügüm yeni ekleneni gösterdi
        temp->next = newNode;
    }
}


//Listeyi ekrana yazdırır
void printList()
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;

    cout << "LinkList icerigi:" << endl;
    while ( temp ) {
        cout << temp->value << endl;
        temp = temp->next;
    } 
    cout << endl;
}

//Listeyi ekrana yazdırır
void printList(Node * head)
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;

    cout << "LinkList icerigi:" << endl;
    while ( temp ) {
        cout << "row:" <<  temp->row << ", column:" << temp->column << ",value:" << temp->value << endl;
        temp = temp->next;
    } 
    cout << endl;
}

//Soru 1: Listede bir değeri arayıp bulursa indisini bulamazsa 
//-1 döndüren fonksiyon. (İpucu: indis sıfırdan başlamalıdır, tek while döngüsünde iki şartla yapabilirsiniz ) 
int indexOf( int key )
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;

    int indis = 0;
    while ( temp != nullptr &&  temp->value != key) {
        temp = temp->next;
        indis ++;
    } 
    
    if ( temp != nullptr ) {
        return indis;
    }

    return -1;
}

//Soru 2: Birinci soruyu recursive olarak gerçekleştiren fonksiyonu
//yazınız.İpucu: fonksiyon içinde static bir değişken kullabilirsiniz
int indexOfRec(Node *ptr, int key )
{
    static int indis = 0;

    //Recursive sonlandırma şartı
    if (ptr == nullptr)
        return -1;

    //Değer bulunduysa true döndür
    if ( ptr->value == key )
        return indis;
 
    //Her sorgulamada indis 1 artırıldı
    indis++;

    //liste içinde recursive ilerle
    return indexOfRec(ptr->next, key);
}

//Soru 3: Listede yer alan elemanların toplamını bulan fonksiyon
int sum()
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;

    int sum = 0;
    while ( temp != nullptr ) {
        sum += temp->value;
        temp = temp->next;
    } 


    return sum;
}


//Soru 4: Üçüncü soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
int sumRec(Node *ptr)
{
    if ( ptr != nullptr ) {
        return ptr->value + sumRec(ptr->next);
    }
    else {
        return 0;
    }
}

//Soru 5: Listede yer alan elemanların en büyüğünü bulan fonksiyon
int largest()
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;
   
    //İlk eleman largest yapılır, sonraki elemana geçilir
    int largest = temp->value;
    temp = temp->next;
    
    while ( temp != nullptr ) {
        if ( temp->value > largest ) {
            largest = temp->value;
        }
        
        temp = temp->next;
    } 

    return largest;
}

//Soru 6: Beşinci soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
//İpucu: Head recursion ve ternary operatör (koşul operatörü) ile çözebilirsiniz. INT_MIN kullanırsanız soru kolaylaşacaktır.
int largestRec(Node *ptr)
{
    if ( ptr != nullptr ) {
        int largest = largestRec(ptr->next);
        return (  ptr->value > largest ) ? ptr->value: largest;
    } 
    else 
    {
        return INT_MIN;
    }
}

//Soru 7: Listede yer alan elemanların en küçüğünü bulan fonksiyon
int smallest()
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;
   
    //İlk eleman largest yapılır, sonraki elemana geçilir
    int smallest = temp->value;
    temp = temp->next;
    
    while ( temp != nullptr ) {
        if ( temp->value < smallest ) {
            smallest = temp->value;
        }
        
        temp = temp->next;
    } 

    return smallest;
}

//Soru 8: Yedinci soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
//İpucu: Head recursion ve ternary operatör (koşul operatörü) ile çözebilirsiniz. INT_MAX kullanırsanız soru kolaylaşacaktır.
int smallestRec(Node *ptr)
{
    if ( ptr != nullptr ) {
        int smallest = smallestRec(ptr->next);
        return (  ptr->value < smallest ) ? ptr->value: smallest;
    } 
    else 
    {
        return INT_MAX;
    }
}

//Soru 9: Listedeki eleman sayısını döndüren fonksiyon
int length()
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;
   
    int length = 0;
    while ( temp != nullptr ) {
        length ++;
        temp = temp->next;
    } 

    return length;
}

//Soru 10: Dokuzuncu soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
int lengthRec(Node *ptr)
{
    if ( ptr != nullptr ) {
        return 1 + lengthRec(ptr->next);
    } 
    else 
    {
        return 0;
    }
}

//Soru 11: Listedeki çift eleman sayısını döndüren fonksiyon
int evenCount()
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;
   
    int count = 0;
    while ( temp != nullptr ) {
        if ( temp->value % 2 == 0 ) {
            count ++;
        }
        temp = temp->next;
    } 

    return count;
}

//Soru 12: On birinci soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
int evenCountRec(Node *ptr)
{
    if ( ptr != nullptr ) {
        return (ptr->value % 2 == 0 ? 1 : 0) + evenCountRec(ptr->next);
    } 
    else 
    {
        return 0;
    }
}

//Soru 13: Listedeki tek eleman sayısını döndüren fonksiyon
int oddCount()
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;
   
    int count = 0;
    while ( temp != nullptr ) {
        if ( temp->value % 2 == 1 ) {
            count ++;
        }
        temp = temp->next;
    } 

    return count;
}

//Soru 14: On üçüncü soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
int oddCountRec(Node *ptr)
{
    if ( ptr != nullptr ) {
        return (ptr->value % 2 == 1 ? 1 : 0) + oddCountRec(ptr->next);
    } 
    else 
    {
        return 0;
    }
}

//Soru 15: Listedeki elemanların ortalamasını bulan fonksiyon
double avg()
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;
   
    double sum = 0.0;
    int count = 0;
    while ( temp != nullptr ) {
        sum += temp->value;
        count ++;
        temp = temp->next;
    } 

    return sum / count;
}

//Soru 16: En büyük üç elemanı ekrana yazdıran fonksiyon
void largestThree()
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;

    int first, second, third;
    
    //Dizi boyutu 3'den küçükse hata ver
    if (lengthRec(head)  < 3) {
        cout << "Liste boyutu 3\'ten küçük olamaz" << endl;
        return;
    }
 
    third = first = second = INT_MIN; //En küçük integer değer
    while ( temp != nullptr ) {
        if (temp->value > first) { // Liste elemanı birinciden büyükse
            third = second;
            second = first;
            first = temp->value;
        }
        else if (temp->value > second) { //Liste elemanı birinci ile ikinci arasındaysa
            third = second;
            second = temp->value;
        }
        else if (temp->value > third) { //Liste elemanı üçünçüden büyükse
            third = temp->value;
        }
        temp = temp->next;
    } 
 
    cout << "En buyuk uc liste elemani "
        << first << " " << second << " "
        << third << endl;
}

//Soru 17: En küçük üç elemanı ekrana yazdıran fonksiyon
void smallestThree()  {
     //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;
     
     int first, second, third;
    
    //Dizi boyutu 3'den küçükse hata ver
    if (lengthRec(head)  < 3) {
        cout << "Dizi boyutu 3\'ten küçük olamaz";
        return;
    }
 
    third = first = second = INT_MAX; //En büyük integer değer
    while ( temp != nullptr ) {
        if (temp->value < first) { // Liste elemanı birinciden küçükse
            third = second;
            second = first;
            first = temp->value;
        }
        else if (temp->value < second) { //Liste elemanı birinci ile ikinci arasındaysa
            third = second;
            second = temp->value;
        }
        else if (temp->value < third) { //Liste elemanı üçünçüden küçükse
            third = temp->value;
        }
        temp = temp->next;
    } 
 
    cout << "En kucuk uc dizi elemani "
        << first << " " << second << " "
        << third << endl;   
}

//Soru 18: Listeyi alfabetik olarak küçükten büyüge Insertion Sort algoritmasını kullanarak sıralayan fonksiyon
void sortInsertionAsc() {
   Node *current = head, *index = NULL;
  int temp;

  if ( head == nullptr ) {
    return;
  } 
  else 
  {
        //Bir dügüm kendisinden sonraki düğümlerle karşılaştırılıyor
        while (current != nullptr) {
            //Index şu anki düğümden sonrakini gösteriyor
            index = current->next;

            while (index != NULL) {
                //Burada değişiklik yapılıyor
                //Insertion sort kullanıldı
                if (current->value > index->value) {
                    //İki değişken yer değiştirdi
                    swap(&current->value, &index->value);
                }
                index = index->next;
            }
            current = current->next;
        }
  }
}

//Soru 19: Listeyi alfabetik olarak büyükten küçüge Insertion Sort algoritmasını kullanarak sıralayan fonksiyon
void sortInsertionDesc() {
   Node *current = head, *index = NULL;
  int temp;

  if ( head == nullptr ) {
    return;
  } 
  else 
  {
        //Bir dügüm kendisinden sonraki düğümlerle karşılaştırılıyor
        while (current != nullptr) {
            //Index şu anki düğümden sonrakini gösteriyor
            index = current->next;

            while (index != NULL) {
                //Burada değişiklik yapılıyor
                if (current->value < index->value) {
                    //İki değişken yer değiştirdi
                    swap(&current->value, &index->value);
                }
                index = index->next;
            }
            current = current->next;
        }
  }
}

//Soru 20: Listeyi alfabetik olarak küçükten büyüge Buble Sort algoritmasını kullanarak sıralayan fonksiyon
void sortBubleAsc() {
	int swapped;
    int temp;

	Node *leftPtr; //sol pointer hep liste başını gösterdi
	Node *rightPrt = NULL; //sag pointer liste sağını gösterdi
	do
	{	
		swapped = 0;
		leftPtr = head;
		while(leftPtr->next != rightPrt)
		{
			if (leftPtr->value > leftPtr->next->value) 
			{
                //İki değişken yer değiştirdi
                swap(&leftPtr->value, &leftPtr->next->value);
                swapped = 1; 
			}
			leftPtr = leftPtr->next;
		}

        //liste sonu en büyük eleman olduğu için, bu sag pointera atanır
        //Sıralanmış listeyi tekrar kontrol etmeye gerek yok
		rightPrt = leftPtr;

	}while(swapped);
}

//Soru 21: Listeyi alfabetik olarak büyükten küçüğe  Buble Sort algoritmasını kullanarak sıralayan fonksiyon
void sortBubleDesc() {
	int swapped;
    int temp;

	Node *leftPtr; //sol pointer hep liste başını gösterdi
	Node *rightPrt = NULL; //sag pointer liste sağını gösterdi
	do
	{	
		swapped = 0;
		leftPtr = head;
		while(leftPtr->next != rightPrt)
		{
			if (leftPtr->value < leftPtr->next->value) 
			{
                //İki değişken yer değiştirdi
                swap(&leftPtr->value, &leftPtr->next->value);
                swapped = 1; 
			}
			leftPtr = leftPtr->next;
		}

        //liste sonu en büyük eleman olduğu için, bu sag pointera atanır
        //Sıralanmış listeyi tekrar kontrol etmeye gerek yok
		rightPrt = leftPtr;

	}while(swapped);
}

//Soru 22: Listeyi ters çeviren fonksiyon
void reverse() {
    Node *temp = nullptr;
    Node *prev = nullptr;
    Node *current = head;

    while(current != nullptr) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    head = prev;
}

//Soru 23: Verilen bir listede toplamları belli bir değer olan ikili eleman sayısını bulan C++ fonksiyonunu yazınız? 
//(Örneğin toplam 5 olsun {1, 4, 3, 2, 3}  listesinde toplamı 5 olan 3 tane ikili eleman vardır.
int findPairSum( int sum) {
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;
    
    int sumCount = 0;
    while ( temp->next != nullptr ) {
        if ( temp->value + temp->next->value == sum ) {
            sumCount ++;
        }
        temp = temp->next;
    } 

    return sumCount;
}

//Soru 24: Verilen bir listede ikili eleman çiftlerinin mod toplamını bulan C++ fonksiyonu yazınız?
// (Örneğin {5, 4, 3, 6}  listesinde sonuç 5 % 4 + 4 % 3 + 3 % 6 = 4 + 1 + 0 = 5’dir) 
int findModSum() {
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;

    int modSum = 0;
    while ( temp->next != nullptr ) {
        modSum += temp->value % temp->next->value;
        temp = temp->next;
    } 

    return modSum;
}

//Soru 25: Bir listeyi diğerinin arkasına ekleyen  fonksiyon
Node * concateList(Node *head1, Node *head2) {
    Node *result = head1;
    
    //Birinci listede dolaşmak için
    Node *last = head1;
    while ( last->next != nullptr ) {
        last = last->next;
    } 

    last->next = head2;

    return result;
}

//Soru 26: Bir diziyi listeye sonuna ekleyen fonksiyon (pointer kullanarak) *ptr parametresi liste başını gösteriyor
void append( Node **ptr, int * data, int n ) { 
    for ( int i = 0; i < n; i ++ ) {
        int value = *(data + i);
        append( ptr, value );
    }
}

//Soru 27: Bir diziyi liste başına ekleyen fonksiyon  *ptr parametresi liste başını gösteriyor
void push( Node **ptr, int * data, int n ) { 
    for ( int i = 0; i < n; i ++ ) {
        int value = *(data + i);
        push( ptr, value );
    }
}

//Soru 28: Bir vektörü elemanlarını liste sonuna ekleyen fonksiyon  *ptr parametresi liste başını gösteriyor
void append( Node **ptr, vector<int> data ) { 
    for ( int value : data ) {
        append( ptr, value );
    }
}

//Soru 29: Bir vektör elemanlaını liste başına ekleyen fonksiyon  *ptr parametresi liste başını gösteriyor
void push( Node **ptr,  vector<int> data ) { 
    for ( int value : data ) {
        push( ptr, value );
    }
}

//Soru 30: Bir listeyi sondakini başa alarak bir birim döndüren fonksiyon
void rotateRight() { 
    Node* last = head;
    Node* prev = nullptr; //Sondan bir önceki düğüm

    while (last->next != nullptr) {
        prev = last;
        last = last->next;
    }
           
    last->next = head;
    head = last;
    prev->next = nullptr;
}

//Soru 31: Bir listeyi baştakini sona alarak bir birim döndüren fonksiyon
void rotateLeft() { 
    Node* last = head;
    Node* nextHead = nullptr; //Head'den sonraki düğüm

    while (last->next != nullptr) {
        last = last->next;
    }

    nextHead = head->next; //head'den sonraki düğüm bir değişkene alındı
    last->next = head; //son düğümün next'i head yapıldı
    head->next = nullptr; //head düğümün next'i nullptr yapılarak son düğüm oldu
    head = nextHead; //head değiştirildi
}

//Soru 32: İki listenin eşit olup olmadığını döndüren fonksiyon
bool areIdentical(Node *a, Node *b)
{
    while (a != nullptr && b != nullptr)
    {
        if (a->value != b->value)
            return false;
 
        //Her iki listede de birer ilerlenir
        a = a->next;
        b = b->next;
    }
 
    //Her iki liste eşitse bu noktada her ikisinin de sonuna gelinmiş olması gerekir
    //Bir tanesin de bile sonuna gelinmediyse alttaki ifade false döndürür
    return (a == nullptr && b == nullptr);
}

//Soru 33: İkili guruplanan liste elemanlarını kendi aralarında yerdeğiştiren fonksiyon
//Giriş : 1->2->3->4->5->6->nullptr 
//Çıkış : 2->1->4->3->6->5->nullptr
//Giriş : 1->NULL 
//Çıkış : 1->NULL 
void pairWiseSwap()
{
    Node* temp = head;
  
    /* Düğüm ve sonraki düğüm nullptr degilse ilerle */
    while (temp != NULL && temp->next != NULL) {
        /* Düğüm ve sonraki dügüm değerlerini yer değiştir*/
        swap(temp->value, temp->next->value);
  
        /* İki dügüm ilerle */
        temp = temp->next->next;
    }
}

//Soru 34: Listeyi vektöre döndüren fonksiyon
vector<int> toVector( Node *head ) { 
    Node* temp = head;
    vector<int> vect;

    while (temp != nullptr) {
        vect.push_back( temp->value );
        temp = temp->next;
    }
           
    return vect;
}

//Soru 35: Verilen bir listede eleman değerlerinin tekrar adetlerini ekrana yazdıran
void frequency() { 
    Node *temp1 = head;
    
    //Bütün liste elemanlarını ziyaret edilmesi olarak işaretle
    while (temp1 != nullptr) {
        temp1->visited = false;
        temp1 = temp1->next;
    }
 
     temp1 = head;
     Node *temp2 = nullptr;

    while (temp1 != nullptr) {
        
         //Eğer eleman ziyaret edilmişse sayma
        if ( temp1->visited )
        {
            temp1 = temp1->next;
            continue;
        }
    
        // Frekanslar sayılıyor
        int count = 1;
        //Bi sonraki düğüm başla
        temp2 = temp1->next;

        while (temp2 != nullptr) {
            if ( temp1->value == temp2->value ) {
                count ++;
                temp2->frequency = 0;
                temp2->visited = true;
            }

            temp2 = temp2->next;
        }

        temp1->frequency = count;
        temp1->visited = true;
        cout << temp1->value << " -> " << temp1->frequency << endl;
        temp1 = temp1->next;
    }
}

//*************** İki boyutlu dizi fonskyionları *************************/
//Soru 36: İki boyutlu r x 4'lük (r satır, 4 sütun) diziyi liste sonuna ekleyen fonksiyon  *head parametresi liste başını gösteriyor
void append( Node **head, const int arr[][COLS], int r) { 
    Node *newNode; //Yeni dügüm
    Node *temp;//Liste içinde dolaşmak için


        for(int x = 0; x < r; x ++) {
            for(int y = 0; y < COLS; y ++ ) {
                //Yeni dügüm yaratıldı
                newNode = new Node;
                newNode->value = arr[x][y];
                newNode->row = x;
                newNode->column = y;
                newNode->next = nullptr;
                
                if ( x == 0 && y == 0 ) {
                    //İlk dizi elemanı head yapıldı
                     *head = newNode;

                    //İşaretçi liste başını gösterir
                    temp = *head;
                }
                else {
                    //En son dügüm yeni ekleneni gösterdi
                    temp->next = newNode;
                    
                    //Bir düğüm ilerlendi
                    temp = newNode;
                }

            }
        }
}

//Soru 37: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen belli satır ve sütundaki eleman değeri, bulamazda -1 döndürsün
int getValue(Node *head, int row, int column) { 
    Node *temp = head; 

    while (temp != nullptr) {
        if ( temp->row == row && temp->column == column  ) {
            return temp->value;
        }

        temp = temp->next;
    }

    return -1;
}

//Soru 38: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'in satır sayısı
int rowCount(Node *head) { 
    Node *temp = head; 

    int rowNum = -1;
    int rowCount = 0;
    while (temp != nullptr) {
        //Satırda değişim var mı?
        if ( temp->row != rowNum  ) {
            rowCount ++;
            rowNum = temp->row;
        }

        temp = temp->next;
    }

    return rowCount;
}

//Soru 39: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'in satır sayısı recursive
int rowCountRec(Node *ptr ) { 
    static int rowNum = -1;
    if ( ptr == nullptr ) {
        return 0;
    }
    
    if ( ptr->row != rowNum ) {
        rowNum = ptr->row; 
        return  1 + rowCountRec(ptr->next);
    }  
    else 
    {
            return rowCountRec(ptr->next);
    }
}

//Soru 40: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'in sütun sayısı
int columnCount(Node *head) { 
    Node *temp = head; 

    int rowNum = -1;
    int rowCount = 0;
    int count = 0;
    
    while (temp != nullptr) {
        //Sütunda değişim var mı?
        if ( temp->row != rowNum  ) {
            rowCount ++;
            rowNum = temp->row;
        }

        count ++;
        temp = temp->next;
    }

    //Toplam eleman sayısı satır sayısına bölünerek sütun sayısı bulunur
    return count / rowCount; 
}

//Soru 41: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki değerlerin toplamı
int rowSum(Node *head, int rowNum) { 
    Node *temp = head; 

    int sum = 0;    
    while (temp != nullptr) {
        //Sütunda değişim var mı?
        if ( temp->row == rowNum  ) {
            sum += temp->value;
        }

        temp = temp->next;
    }

    return sum; 
}

//Soru 42: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki değerlerin toplamı recursive
int rowSumRec(Node *ptr, int rowNum) { 
    if ( ptr == nullptr ) {
        return 0;
    }

    if ( ptr->row == rowNum )  
    {
        return ptr->value + rowSum(ptr->next, rowNum);
    }
    else  
    {
        return rowSum(ptr->next, rowNum);
    }
}

//Soru 43: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki değerlerin toplamı
int columnSum(Node *head, int colNum) { 
    Node *temp = head; 

    int sum = 0;    
    while (temp != nullptr) {
        //Sütunda değişim var mı?
        if ( temp->column == colNum  ) {
            sum += temp->value;
        }

        temp = temp->next;
    }

    return sum; 
}

//Soru 44: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki değerlerin toplamı recursive
int columnSumRec(Node *ptr, int colNum) { 
    if ( ptr == nullptr ) {
        return 0;
    }

    if ( ptr->column == colNum )  
    {
        return ptr->value + columnSumRec(ptr->next, colNum);
    }
    else  
    {
        return columnSumRec(ptr->next, colNum);
    }
}

//Soru 45: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki en büyük eleman
int rowLargest(Node *head, int rowNum) { 
    Node *temp = head; 

    int largest = INT_MIN;    
    while (temp != nullptr) {
        //Sütunda değişim var mı?
        if ( temp->row == rowNum && temp->value > largest  ) {
            largest = temp->value;
        }

        temp = temp->next;
    }

    return largest; 
}

//Soru 46: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki en büyük eleman recursive
int rowLargestRec(Node *ptr, int rowNum)
{
    if ( ptr == nullptr ) {
        return INT_MIN;
    }

    if ( ptr->row == rowNum && ptr->value > rowLargestRec(ptr->next, rowNum)  ) {
        return ptr->value;
    }
    else 
    {
         return rowLargestRec(ptr->next, rowNum);
    }
}

//Soru 47: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki en küçük eleman
int rowSmallest(Node *head, int rowNum) { 
    Node *temp = head; 

    int smallest = INT_MAX;    
    while (temp != nullptr) {
        //Sütunda değişim var mı?
        if ( temp->row == rowNum && temp->value < smallest  ) {
            smallest = temp->value;
        }

        temp = temp->next;
    }

    return smallest; 
}

//Soru 48: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki en küçük eleman recursive
int rowSmallestRec(Node *ptr, int rowNum)
{
    if ( ptr == nullptr ) {
        return INT_MAX;
    }

    if ( ptr->row == rowNum && ptr->value < rowSmallestRec(ptr->next, rowNum)  ) {
        return ptr->value;
    }
    else 
    {
         return rowSmallestRec(ptr->next, rowNum);
    }
}

//Soru 49: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki en büyük eleman
int columnLargest(Node *head, int colNum) { 
    Node *temp = head; 

    int largest = INT_MIN;    
    while (temp != nullptr) {
        //Sütunda değişim var mı?
        if ( temp->column == colNum && temp->value > largest  ) {
            largest = temp->value;
        }

        temp = temp->next;
    }

    return largest; 
}

//Soru 50: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki en büyük eleman recursive
int columnLargestRec(Node *ptr, int colNum)
{
    if ( ptr == nullptr ) {
        return INT_MIN;
    }

    if ( ptr->column == colNum && ptr->value > columnLargestRec(ptr->next, colNum)  ) {
        return ptr->value;
    }
    else 
    {
         return columnLargestRec(ptr->next, colNum);
    }
}

//Soru 51: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki en küçük eleman
int columnSmallest(Node *head, int colNum) { 
    Node *temp = head; 

    int smallest = INT_MAX;    
    while (temp != nullptr) {
        if ( temp->column == colNum && temp->value < smallest  ) {
            smallest = temp->value;
        }

        temp = temp->next;
    }

    return smallest; 
}

//Soru 52: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki en küçük eleman recursive
int columnSmallestRec(Node *ptr, int colNum)
{
    if ( ptr == nullptr ) {
        return INT_MAX;
    }

    if ( ptr->column == colNum && ptr->value < columnSmallestRec(ptr->next, colNum)  ) {
        return ptr->value;
    }
    else 
    {
         return columnSmallestRec(ptr->next, colNum);
    }
}

//Soru 53: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki değerlerin ortalaması
double rowAvg(Node *head, int rowNum) { 
    Node *temp = head; 

    double sum = 0;    
    int count = 0;
    while (temp != nullptr) {
        //Sütunda değişim var mı?
        if ( temp->row == rowNum  ) {
            sum += temp->value;
            count ++;
        }

        temp = temp->next;
    }

    return sum / count; 
}

//Soru 54: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki değerlerin ortalaması
double columnAvg(Node *head, int colNum) { 
    Node *temp = head; 

    double sum = 0; 
    int count = 0;   
    while (temp != nullptr) {
        //Sütunda değişim var mı?
        if ( temp->column == colNum  ) {
            sum += temp->value;
            count ++;
        }

        temp = temp->next;
    }

    return sum / count; 
}

//Soru 55: Recursive olarak bir LinkedList'i sondan başa doğru yazdıran fonksiyon
void reversePrint (Node *head)
{
    //Tail recursion ile çözüldü
    if ( head != nullptr ) {
         reversePrint(head->next);
         cout << head->value << endl;
    }
    else
    {
         cout << "Sondan başa dogru LinkedList içeriği: " << endl;
    }
}

//Soru 56: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırı ekrana yazdıran 
void printRow(Node *head, int rowNum) { 
    Node *temp = head; 

    cout << "LinkedList satir iceriği: " << endl;
    while (temp != nullptr) {
        //Sütunda değişim var mı?
        if ( temp->row == rowNum  ) {
            cout << temp->value << endl;
        }

        temp = temp->next;
    }
}

//Soru 57: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütunu ekrana yazdıran 
void printColumn(Node *head, int colNum) { 
    Node *temp = head; 
 
    cout << "LinkedList sutun iceriği: " << endl;
    while (temp != nullptr) {
        //Sütunda değişim var mı?
        if ( temp->column == colNum  ) {
            cout << temp->value << endl;
        }

        temp = temp->next;
    }
}

//Soru 58: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırı sondan başa doğgru recursive yazdıran
void printRowReverse(Node *head, int rowNum) { 
    //Tail recursion ile çözüldü
    if ( head == nullptr ) {
        cout << "Sondan basa dogru LinkedList satir iceriği: " << endl;
    }
    else if ( head->row == rowNum  ) {
         printRowReverse(head->next, rowNum);
         cout << head->value << endl;
    }
    else
    {
        return printRowReverse(head->next, rowNum);
    }
}

//Soru 59: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütunu sondan başa doğgru recursive yazdıran
void printColumnReverse(Node *head, int colNum) { 
    //Tail recursion ile çözüldü
    if ( head == nullptr ) {
        cout << "Sondan basa dogru LinkedList sütun iceriği: " << endl;
    }
    else if ( head->column == colNum  ) {
         printColumnReverse(head->next, colNum);
         cout << head->value << endl;
    }
    else
    {
        return printColumnReverse(head->next, colNum);
    }
}

//Soru 60: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırda girilen search değerini recursive arayan
bool searchRow(Node *head, int rowNum, int search) { 
    if ( head == nullptr ) {
        return false;
    }
    else if ( head->row == rowNum && head->value == search  ) {
         return true;
    }
    else
    {
        return searchRow(head->next, rowNum, search);
    }
}

//Soru 61: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütunda  girilen search değerini recursive arayan
bool searchColumn(Node *head, int colNum, int search) { 
    if ( head == nullptr ) {
        return false;
    }
    else if ( head->column == colNum && head->value == search  ) {
         return true;
    }
    else
    {
        return searchColumn(head->next, colNum, search);
    }
}

//Soru 62: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir elemanı arayan ve düğüm olarak döndüren recursive fonksiyon
Node * search(Node *head, int value) { 
    if (head == nullptr)
        return nullptr;
    else if (head->value == value)
        return head;
    else
        return search(head->next, value);
}

//Soru 63: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'in kopyasını oluşturan recursive fonksiyon
Node * copy(Node *head) { 
    if (head == nullptr)
      return nullptr;
    else {
        return new Node  {head->value, head->row, head->column, head->frequency, head->visited,copy(head->next) }; 
    }
}

