#include <iostream>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Node* head = nullptr;

void push( int data );//Liste başına dügüm ekler
void printList();//Listeyi ekrana yazdırır
void printListRec(Node *ptr);
void append( int data );//Liste sonuna dügüm ekliyor
void appendAsc( int data );//Sona sıralı bir şekilde ekliyor
void deleteNode( int num );//Listeden bir düğüm siliyor
bool search( int key );//Arama işlemi yapıyor
bool searchRec(Node *ptr,  int key );//Recursive arama

int main()
{
    //Değerler ekleniyor
    push( 12 );
    push( 21 );
    push( 4 );
    push( 1 );

    
    printList();
    deleteNode( 21 );
    printList();

   return 0;
}

//Liste başına dügüm ekler
void push( int data ) { 
    Node * newNode = new Node;
    newNode->value = data;
    newNode->next = head;

    if ( head != nullptr ) {
        head->prev = newNode;
    }

    newNode->prev = nullptr;

    head = newNode;
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

//Liste sonuna veya başına artan sırada eleman ekler
void appendAsc( int data ) { 
    Node *newNode; //Yeni dügüm
    Node *last;//Liste içinde son düğüme ulaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if ( head == nullptr ) { //Head boşsa
        //Liste boşsa
        head = newNode;
    }
    else if ( data <= head->value ) //Head solundaysa
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else
    {
        last = head;

        //Liste sonuna gelinmediyse, 
        //aktif dügümden sonraki dügümün değeri eklenen değerdem  küçükse sonraki dügüme geç
        while( last->next != nullptr && last->next->value < data ) {
            last = last->next;
        }

        newNode->next = last->next;
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

void printListRec(Node *ptr)
{
    if ( ptr == nullptr ) {
        return;
    }
    else {
        cout << ptr->value << endl;
        return printListRec(ptr->next);
    }
}

//dügüm siler
void deleteNode( int num) {
    Node *prevNode; //Bir önceki dügüm
    Node* temp = head;//Listede dolaşmak için

    if ( head == nullptr ) {
        return;
    }

    //Silinecek dügüm liste başındaysa
    if ( temp->value == num ) {
        temp = temp->next;
        delete head;
        temp->prev = nullptr;
        head = temp;
    }
    else
    {
        //İşaretçi liste başını gösterir
        temp = head;

        while( temp != nullptr && temp->value != num ) {
            prevNode = temp;
            temp = temp->next;
        }

        if ( temp->next == nullptr ) {
            //Son düğüm silinmişse
            prevNode->next = nullptr;
            delete temp;
        } 
        else {
            //Ara bir güm silinecekse 
            prevNode->next = temp->next;
            temp->next->prev = prevNode;
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