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
    append( 7 );
    append( 3 );
    append( 4 );
    append( 27 );

    printList();

    deleteNode( 27 );
    printList();


     cout << "search( 7 ): " << search( 27 ) << endl;
     cout << "searchRec( head, 21 ): " << searchRec(head, 21 ) << endl;
     cout << "searchRec( head, 45 ): " << searchRec(head, 45 ) << endl;
     cout << "searchRec( head, 3 ): " << searchRec(head, 3 ) << endl;


   return 0;
}

//Liste başına dügüm ekler
void push( int data ) { 
    Node *newNode; //Yeni dügüm
    Node *temp;//Liste içinde dolaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;

    if ( head == nullptr ) {
        //Liste boşsa
        newNode->next = newNode;
        head = newNode;
    }
    else {
        //İşaretçi liste başını gösterir
        temp = head;

        while ( temp->next != head ) {
            temp = temp->next;
        }

        //En son dügüm yeni ekleneni gösterdi
        temp->next = newNode;

        //Yeni dügüm head yapıldı
        newNode->next = head;
        head = newNode;
    }
}

//Liste sonuna dügüm ekler
void append( int data ) { 
    Node *newNode; //Yeni dügüm
    Node *temp;//Liste içinde dolaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;
    newNode->next = head;

    if ( head == nullptr ) {
        //Liste boşsa
        newNode->next = newNode;
        head = newNode;
    }
    else {
        //İşaretçi liste başını gösterir
        temp = head;

        while ( temp->next != head ) {
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

    cout << "CircularLinkList icerigi:" << endl;
    do {
        cout << temp->value << endl;
        temp = temp->next;
    } while( temp != head );
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

        while( temp->next != head && temp->value != num ) {
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

     do {
        if ( temp->value == key ) {
            return true;
        }

        temp = temp->next;
    } while( temp->next != head );
    
    return false;
}

//Listede düğüm  arıyor - Recursive
bool searchRec(Node *nodePtr,  int key )
{
    // Base case
    if (nodePtr->next == head)
        return false;
     
    // If key is present in current node, return true
    if ( nodePtr->value == key )
        return true;
 
    // Recur for remaining list
    return searchRec(nodePtr->next, key);
}