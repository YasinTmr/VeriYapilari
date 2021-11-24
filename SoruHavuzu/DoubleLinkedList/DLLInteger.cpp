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
    struct Node *prev;
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
void printList(Node *head);//Listeyi ekrana yazdırır
void append( int data );//Liste sonuna dügüm ekliyor
void append(Node **head, int data );//Liste sonuna dügüm ekliyor

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
    newNode->prev = nullptr;

    head = newNode;
}

//Liste başına dügüm ekler
void push(Node **head, int data ) { 
    Node * newNode = new Node;
    newNode->value = data;
    newNode->next = *head;
    newNode->prev = nullptr;

    *head = newNode;
}

//Liste sonuna dügüm ekler
void append( int data ) { 
    Node *newNode; //Yeni dügüm
    Node *last;//Liste içinde son düğüme ulaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if ( head == nullptr ) {
        //Liste boşsa
        head = newNode;
    }
    else {
        //İşaretçi liste başını gösterir
        last = head;

        while ( last->next ) {
            last = last->next;
        }

        //En son dügüm yeni ekleneni gösterdi
        last->next = newNode;
        newNode->prev = last;
    }
}

//Liste sonuna dügüm ekler
void append(Node **head, int data ) { 
    Node *newNode; //Yeni dügüm
    Node *last;//Liste içinde son düğüme ulaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if ( *head == nullptr ) {
        //Liste boşsa
        *head = newNode;
    }
    else {
        //İşaretçi liste başını gösterir
        last = *head;

        while ( last->next ) {
            last = last->next;
        }

        //En son dügüm yeni ekleneni gösterdi
        last->next = newNode;
        newNode->prev = last;
    }
}

//Listeyi ileri yönde ekrana yazdırır
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


//Listeyi ileri yönde ekrana yazdırır
void printList(Node * head)
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

//Soru 1: Listede bir değeri arayıp bulursa indisini bulamazsa 
//-1 döndüren fonksiyon. (İpucu: indis sıfırdan başlamalıdır, tek while döngüsünde iki şartla yapabilirsiniz ) 
int indexOf( int key )
{
    //Liste içinde dolaşmak için gerekli pointer
    return -1;
}

//Soru 2: Birinci soruyu recursive olarak gerçekleştiren fonksiyonu
//yazınız.İpucu: fonksiyon içinde static bir değişken kullabilirsiniz
int indexOfRec(Node *ptr, int key )
{
    return -1;
}

//Soru 3: Listede yer alan elemanların toplamını bulan fonksiyon
int sum()
{
    return -1;
}


//Soru 4: Üçüncü soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
int sumRec(Node *ptr)
{
    return -1;
}

//Soru 5: Listede yer alan elemanların en büyüğünü bulan fonksiyon
int largest()
{
    return -1;
}

//Soru 6: Beşinci soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
//İpucu: Head recursion ve ternary operatör (koşul operatörü) ile çözebilirsiniz. INT_MIN kullanırsanız soru kolaylaşacaktır.
int largestRec(Node *ptr)
{
    return -1;
}

//Soru 7: Listede yer alan elemanların en küçüğünü bulan fonksiyon
int smallest()
{
   return -1;
}

//Soru 8: Yedinci soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
//İpucu: Head recursion ve ternary operatör (koşul operatörü) ile çözebilirsiniz. INT_MAX kullanırsanız soru kolaylaşacaktır.
int smallestRec(Node *ptr)
{
   return -1;
}

//Soru 9: Listedeki eleman sayısını döndüren fonksiyon
int length()
{
   return -1;
}

//Soru 10: Dokuzuncu soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
int lengthRec(Node *ptr)
{
    return -1;
}

//Soru 12: On birinci soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
int evenCountRec(Node *ptr)
{
    return -1;
}

//Soru 13: Listedeki tek eleman sayısını döndüren fonksiyon
int oddCount()
{
    return -1;
}

//Soru 14: On üçüncü soruyu recursive olarak gerçekleştiren fonksiyonu yazınız
int oddCountRec(Node *ptr)
{
    return -1;
}

//Soru 15: Listedeki elemanların ortalamasını bulan fonksiyon
double avg()
{
    return -1;
}

//Soru 16: En büyük üç elemanı ekrana yazdıran fonksiyon
void largestThree()
{
    
}

//Soru 17: En küçük üç elemanı ekrana yazdıran fonksiyon
void smallestThree()  {
    
}

//Soru 18: Listeyi alfabetik olarak küçükten büyüge Insertion Sort algoritmasını kullanarak sıralayan fonksiyon
void sortInsertionAsc() {
  
}

//Soru 19: Listeyi alfabetik olarak büyükten küçüge Insertion Sort algoritmasını kullanarak sıralayan fonksiyon
void sortInsertionDesc() {
  
}

//Soru 20: Listeyi alfabetik olarak küçükten büyüge Buble Sort algoritmasını kullanarak sıralayan fonksiyon
void sortBubleAsc() {
	
}

//Soru 21: Listeyi alfabetik olarak büyükten küçüğe  Buble Sort algoritmasını kullanarak sıralayan fonksiyon
void sortBubleDesc() {
	
}

//Soru 22: Listeyi ters çeviren fonksiyon
void reverse() {
   
}

//Soru 23: Verilen bir listede toplamları belli bir değer olan ikili eleman sayısını bulan C++ fonksiyonunu yazınız? 
//(Örneğin toplam 5 olsun {1, 4, 3, 2, 3}  listesinde toplamı 5 olan 3 tane ikili eleman vardır.
int findPairSum( int sum) {
   return -1;
}

//Soru 24: Verilen bir listede ikili eleman çiftlerinin mod toplamını bulan C++ fonksiyonu yazınız?
// (Örneğin {5, 4, 3, 6}  listesinde sonuç 5 % 4 + 4 % 3 + 3 % 6 = 4 + 1 + 0 = 5’dir) 
int findModSum() {
   return -1;
}

//Soru 25: Bir listeyi diğerinin arkasına ekleyen  fonksiyon
Node * concateList(Node *head1, Node *head2) {
    return nullptr;
}

//Soru 26: Bir diziyi listeye sonuna ekleyen fonksiyon (pointer kullanarak) *ptr parametresi liste başını gösteriyor
void append( Node **ptr, int * data, int n ) { 
    
}

//Soru 27: Bir diziyi liste başına ekleyen fonksiyon  *ptr parametresi liste başını gösteriyor
void push( Node **ptr, int * data, int n ) { 
   
}

//Soru 28: Bir vektörü elemanlarını liste sonuna ekleyen fonksiyon  *ptr parametresi liste başını gösteriyor
void append( Node **ptr, vector<int> data ) { 
    
}

//Soru 29: Bir vektör elemanlaını liste başına ekleyen fonksiyon  *ptr parametresi liste başını gösteriyor
void push( Node **ptr,  vector<int> data ) { 
   
}

//Soru 30: Bir listeyi sondakini başa alarak bir birim döndüren fonksiyon
void rotateRight() { 
    
}

//Soru 31: Bir listeyi baştakini sona alarak bir birim döndüren fonksiyon
void rotateLeft() { 

}

//Soru 32: İki listenin eşit olup olmadığını döndüren fonksiyon
bool areIdentical(Node *a, Node *b)
{
   return false;
}

//Soru 33: İkili guruplanan liste elemanlarını kendi aralarında yerdeğiştiren fonksiyon
//Giriş : 1->2->3->4->5->6->nullptr 
//Çıkış : 2->1->4->3->6->5->nullptr
//Giriş : 1->NULL 
//Çıkış : 1->NULL 
void pairWiseSwap()
{
    
}

//Soru 34: Listeyi vektöre döndüren fonksiyon
vector<int> toVector( Node *head ) { 
    vector<int> vect;       
    return vect;
}

//Soru 35: Verilen bir listede eleman değerlerinin tekrar adetlerini ekrana yazdıran
void frequency() { 
    
}

//*************** İki boyutlu dizi fonskyionları *************************/
//Soru 36: İki boyutlu r x 4'lük (r satır, 4 sütun) diziyi liste sonuna ekleyen fonksiyon  *head parametresi liste başını gösteriyor
void append( Node **head, const int arr[][COLS], int r) { 
   
}

//Soru 37: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen belli satır ve sütundaki eleman değeri, bulamazda -1 döndürsün
int getValue(Node *head, int row, int column) { 
    return -1;
}

//Soru 38: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'in satır sayısı
int rowCount(Node *head) { 
   return -1;
}

//Soru 39: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'in satır sayısı recursive
int rowCountRec(Node *ptr ) { 
   return -1;
}

//Soru 40: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'in sütun sayısı
int columnCount(Node *head) { 
    return -1;
}

//Soru 41: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki değerlerin toplamı
int rowSum(Node *head, int rowNum) { 
   return -1;
}

//Soru 42: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki değerlerin toplamı recursive
int rowSumRec(Node *ptr, int rowNum) { 
    return -1;
}

//Soru 43: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki değerlerin toplamı
int columnSum(Node *head, int colNum) { 
   return -1;
}

//Soru 44: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki değerlerin toplamı recursive
int columnSumRec(Node *ptr, int colNum) { 
   return -1;
}

//Soru 45: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki en büyük eleman
int rowLargest(Node *head, int rowNum) { 
   return -1;
}

//Soru 46: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki en büyük eleman recursive
int rowLargestRec(Node *ptr, int rowNum)
{
   return -1;
}

//Soru 47: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki en küçük eleman
int rowSmallest(Node *head, int rowNum) { 
    return -1;
}

//Soru 48: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki en küçük eleman recursive
int rowSmallestRec(Node *ptr, int rowNum)
{
    return -1;
}

//Soru 49: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki en büyük eleman
int columnLargest(Node *head, int colNum) { 
    return -1;
}

//Soru 50: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki en büyük eleman recursive
int columnLargestRec(Node *ptr, int colNum)
{
   return -1;
}

//Soru 51: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki en küçük eleman
int columnSmallest(Node *head, int colNum) { 
   return -1;
}

//Soru 52: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki en küçük eleman recursive
int columnSmallestRec(Node *ptr, int colNum)
{
   return -1;
}

//Soru 53: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırdaki değerlerin ortalaması
double rowAvg(Node *head, int rowNum) { 
   return -1;
}

//Soru 54: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütundaki değerlerin ortalaması
double columnAvg(Node *head, int colNum) { 
   return -1;
}

//Soru 55: Recursive olarak bir LinkedList'i sondan başa doğru yazdıran fonksiyon
void reversePrint (Node *head)
{
   
}

//Soru 56: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırı ekrana yazdıran 
void printRow(Node *head, int rowNum) { 
    
}

//Soru 57: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütunu ekrana yazdıran 
void printColumn(Node *head, int colNum) { 
    
}

//Soru 58: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırı sondan başa doğgru recursive yazdıran
void printRowReverse(Node *head, int rowNum) { 
    //Tail recursion ile çözüldü
}

//Soru 59: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütunu sondan başa doğgru recursive yazdıran
void printColumnReverse(Node *head, int colNum) { 
    //Tail recursion ile çözüldü
}

//Soru 60: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir satırda girilen search değerini recursive arayan
bool searchRow(Node *head, int rowNum, int search) { 
   return false;
}

//Soru 61: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir sütunda  girilen search değerini recursive arayan
bool searchColumn(Node *head, int colNum, int search) { 
    return false;
}

//Soru 62: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'deki bir elemanı arayan ve düğüm olarak döndüren recursive fonksiyon
Node * search(Node *head, int value) { 
   return nullptr;
}

//Soru 63: Otuz altıncı fonksiyonla iki boyutlu dizi yüklenen LinkedList'in kopyasını oluşturan recursive fonksiyon
Node * copy(Node *head) { 
   return nullptr;
}

