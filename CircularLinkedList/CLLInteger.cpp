#include <iostream>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

struct Node* head = nullptr;

void push( int data );//Liste başına dügüm ekler
void push(Node **head,  int data );
void printList();//Listeyi ekrana yazdırır
int lastValue();
void append( int data );//Liste sonuna dügüm ekliyor
void appendAsc( int data );//Listeye artan şekilde eleman ekliyor
void appendDesc( int data );
void deleteNode( int num );//Listeden bir düğüm siliyor
bool search( int key );//Liste içinde arama yapıyor
bool searchRec(Node *ptr,  int key );//Liste içinde recursive arama yapıyor

int main()
{
    //Değerler ekleniyor
    push(&head, 12 );
    push(&head, 5 );
    push(&head, 7 );
    push(&head, 45 );

    printList();
    cout << lastValue() << endl;

    searchRec( head, 7 );

    printList();

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

void push(Node **head,  int data ) { 
    Node *newNode; //Yeni dügüm
    Node *temp;//Liste içinde dolaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;

    if ( *head == nullptr ) {
        //Liste boşsa
        newNode->next = newNode;
        *head = newNode;
    }
    else {
        //İşaretçi liste başını gösterir
        temp = *head;

        while ( temp->next != *head ) {
            temp = temp->next;
        }

        //En son dügüm yeni ekleneni gösterdi
        temp->next = newNode;

        //Yeni dügüm head yapıldı
        newNode->next = *head;
        *head = newNode;
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
        newNode->next = newNode;
        head = newNode;
    }
    else if ( data <= head->value ) //Head solundaysa
    {
        newNode->next = head;

        //Son düğüme gidilir bunun next'i newNode yapılır
         temp = head;
         while(temp->next!=head){
            temp = temp->next;
         }
         
         //Son düğümün next'i yeni düğüm yapıldı
         temp->next = newNode;

         newNode->next = head;

         //head yeni düğüm oldu
         head = newNode;
    }
    else
    {
        temp = head;

        //Liste sonuna gelinmediyse, 
        //aktif dügümden sonraki dügümün değeri eklenen değerdem  küçükse sonraki dügüme geç
        while( temp->next != head && temp->next->value < data ) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//Liste sonuna veya başına azalan sırada eleman ekler
void appendDesc( int data ) { 
    Node *newNode; //Yeni dügüm
    Node *temp;//Liste içinde dolaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;
    newNode->next = nullptr;

    if ( head == nullptr ) { //Head boşsa
        //Liste boşsa
        newNode->next = newNode;
        head = newNode;
    }
    else if ( data >= head->value ) //Head solundaysa
    {
        newNode->next = head;

        //Son düğüme gidilir bunun next'i newNode yapılır
         temp = head;
         while(temp->next!=head){
            temp = temp->next;
         }
         
         //Son düğümün next'i yeni düğüm yapıldı
         temp->next = newNode;

         newNode->next = head;

         //head yeni düğüm oldu
         head = newNode;
    }
    else
    {
        temp = head;

        //Liste sonuna gelinmediyse, 
        //aktif dügümden sonraki dügümün değeri eklenen değerdem  küçükse sonraki dügüme geç
        while( temp->next != head && temp->next->value > data ) {
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

    cout << "CircularLinkList icerigi:" << endl;
    do {
        cout << temp->value << endl;
        temp = temp->next;
    } while( temp != head );
    cout << endl;
}

int lastValue()
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;

    do {
        temp = temp->next;
    } while( temp->next != head );

    return temp->value;
}

//Aranılan düğümü siler
void deleteNode( int num) {
    Node *prev; //Bir önceki dügüm
    Node* last;//Listede dolaşmak için

    if ( head == nullptr ) {
        //Liste boşsa işlem yapma
        return;
    }
    else if ( head->value == num )
    {
        //Silinecek değer başlangıçta ise         
        //Son düğüme gidilir
        last = head;

         while(last->next!=head){
            last = last->next;
         }

        //Silinecek bir düğüm varsa 
        if ( last->next == last ) {
            //Liste boşaltılır
            delete head;
            head = nullptr;
        }
        else
        {
            //Son düğüm head kısmı düzeltilir
            Node *nodeDeleted = head;//Geçici değişkene atandı listeyi bozmamak için
            head = head->next;
            last->next = head;
            delete nodeDeleted;
        }
    }
    else 
    {
        //İşaretçi liste başını gösterdi
        last = head;

        //Silinecek düğüm sonda ya da ortadadır
        while(last->next!=head){
            //Silinecek düğüm ortalarda 
            if(last->value == num ) {
                prev->next = last->next;
                delete last;
                return;
            }

            prev = last;
            last = last->next;
        }

        //Silinecek düğüm son düğümse 
        if ( last->value == num ) {
            prev->next = head;
            delete last;
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