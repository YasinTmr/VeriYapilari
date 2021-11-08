#include <iostream>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

struct Node* head = nullptr;

void push( int data );//Liste başına dügüm ekler
void printList();//Listeyi ekrana yazdırır
void append( int data );//Liste sonuna dügüm ekliyor
void appendAsc( int data );//Sona sıralı bir şekilde ekliyor
void deleteNode( int num );//Listeden bir düğüm siliyor
bool search( int key );//Arama işlemi yapıyor
bool searchRec(Node *ptr,  int key );//Recursive arama

int main()
{
    //Değerler ekleniyor
    appendAsc( 12 );
    appendAsc( 21 );
    appendAsc( 4 );
    appendAsc( 27 );

     printList();
     cout << "searchRec(head, 32 ): " << searchRec(head, 32 ) << endl;
     cout << "search( 12 ): " << search( 12 ) << endl;

    // deleteNode( 12 );
    // printList();

    // cout << "searchRec( 21 ): " << searchRec(head, 21 ) << endl;

    // cout << "search( 7 ): " << search( 7 ) << endl;
    // cout << "searchRec( 21 ): " << searchRec(head, 21 ) << endl;
    // cout << "searchRec( 45 ): " << searchRec(head, 45 ) << endl;
    // cout << "searchRec( 3 ): " << searchRec(head, 3 ) << endl;


   return 0;
}

//Liste başına dügüm ekler
void push( int data ) { 
    Node * newNode = new Node;
    newNode->value = data;
    newNode->next = head;

    head = newNode;
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

//Liste sonuna veya başına artan sırada eleman ekler
void appendAsc( int data ) { 
    Node *newNode; //Yeni dügüm
    Node *temp;//Liste içinde dolaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;
    newNode->next = nullptr;

    if ( head == nullptr ) { //Head boşsa
        //Liste boşsa
        head = newNode;
    }
    else if ( data <= head->value ) //Head solundaysa
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;

        //Liste sonuna gelinmediyse, 
        //aktif dügümden sonraki dügümün değeri eklenen değerdem  küçükse sonraki dügüme geç
        while( temp->next != nullptr && temp->next->value < data ) {
            temp = temp->next;
        }

        newNode->next = temp->next;
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

//dügüm siler
void deleteNode( int num) {
    Node *prev; //Bir önceki dügüm
    Node* temp = head;//Listede dolaşmak için

    if ( head == nullptr ) {
        return;
    }

    //Silinecek dügüm liste başındaysa
    if ( temp->value == num ) {
        temp = temp->next;
        delete head;
        head = temp;
    }
    else
    {
        //İşaretçi liste başını gösterir
        temp = head;

        while( temp != nullptr && temp->value != num ) {
            prev = temp;
            temp = temp->next;
        }

        if ( temp ) {
            prev->next = temp->next;
            delete temp;
        }
    }
} 

//Listede düğüm  arıyor - Iteratif
bool search( int key )
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;

    while ( temp != nullptr ) {
        if ( temp->value == key ) {
            return true;
        }

        temp = temp->next;
    } 
    
    return false;
}

//Listede düğüm  arıyor - Recursive
bool searchRec(Node *ptr,  int key )
{
    //Recursive sonlandırma şartı
    if (ptr == nullptr)
        return false;
     
    //Değer bulunduysa true döndür
    if ( ptr->value == key )
        return true;
 
    //liste içinde recursive ilerle
    return searchRec(ptr->next, key);
}