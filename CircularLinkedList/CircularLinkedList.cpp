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
    append( 7 );
    append( 3 );
    append( 4 );
    append( 27 );

    printList();

    cout << "searchRec(head, 7 ): " << searchRec(head, 7 ) << endl;


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

//Aranılan düğümü siler
void deleteNode( int num) {
    Node *prev; //Bir önceki dügüm
    Node* temp = head;//Listede dolaşmak için

    if ( head == nullptr ) {
        //Liste boşsa işlem yapma
        return;
    }
    else if ( head->value == num )
    {
        //Silinecek değer başlangıçta ise         

         //Son düğüme gidilir
         while(temp->next!=head){
            temp = temp->next;
         }

         //Son düğüm head kısmı düzeltilir
         Node *nodeDeleted = head;//Geçici değişkene atandı listeyi bozmamak için
         head = head->next;
         temp->next = head;
         delete nodeDeleted;
    }
    else 
    {
        //Silinecek düğüm sonda ya da ortadadır
        while(temp->next!=head){
            //Silinecek düğüm ortalarda 
            if(temp->value == num ) {
                prev->next = temp->next;
                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        //Eğer son düğümde bulunduysa 
        if ( temp->value == num ) {
            prev->next = head;
            delete temp;
        }
    }
} 

//Listede düğüm  arıyor - Iteratif
bool search( int key )
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;
   
    //Son düğüm dahil hepsi karşılaştırıldı
    do {
        if ( temp->value == key ) {
            return true;
        }
        
        temp = temp->next;
    } while( temp != head );
    
    return false;
}

//Listede düğüm  arıyor - Recursive
bool searchRec(Node *nodePtr,  int key )
{     
    //Son düğüm ve ilk düğümden dolayı öne alındı
    if ( nodePtr->value == key )
        return true;
 
    //Sonlandırma şartı
    if (nodePtr->next == head)
        return false;

    //Kalan düğümlerde dolaşılacak
    return searchRec(nodePtr->next, key);
}