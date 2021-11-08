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
void deleteNode( int num );//Listeden bir düğüm siliyor
bool search( int key );
bool searchRec(Node *ptr,  int key );

int main()
{
    //Değerler ekleniyor
    push( 12 );
    push( 21 );
    push( 7 );
    push( 3 );
    push( 4 );
    append(27);

    printList();

    deleteNode( 3 );
    printList();

    cout << "search( 7 ): " << search( 7 ) << endl;
    cout << "searchRec( 21 ): " << searchRec(head, 21 ) << endl;
    cout << "searchRec( 45 ): " << searchRec(head, 45 ) << endl;
    cout << "searchRec( 3 ): " << searchRec(head, 3 ) << endl;


   return 0;
}

//Liste başına dügüm ekler
void push( int data ) { 
    Node * newNode;

    newNode = new Node;
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

        while ( temp->next) {
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

//dügüm siler
void deleteNode( int num) {
    Node *previousNode; //Bir önceki dügüm
    Node* temp = head;//Listede dolaşmak için

    if ( head == nullptr ) {
         head = temp->next;     // Head değişti
        delete temp;            // Eski head hafızadan silindi
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
            previousNode = temp;
            temp = temp->next;
        }

        if ( temp ) {
            previousNode->next = temp->next;
            delete temp;
        }
    }
} 

//Listede düğüm  arıyor - Iteratif
bool search( int key )
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;

    while ( temp ) {
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
    // Base case
    if (ptr == nullptr)
        return false;
     
    // If key is present in current node, return true
    if ( ptr->value == key )
        return true;
 
    // Recur for remaining list
    return searchRec(ptr->next, key);
}