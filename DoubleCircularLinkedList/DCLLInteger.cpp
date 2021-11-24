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
void push(Node **head, int data ) ;
void printList();//Listeyi ekrana yazdırır
void append( int data );//Liste sonuna dügüm ekliyor
void appendAsc( int data );//Listeye artan şekilde eleman ekliyor
void deleteNode( int num );//Listeden bir düğüm siliyor
bool search( int key );//Liste içinde arama yapıyor
bool searchRec(Node *ptr,  int key );//Liste içinde recursive arama yapıyor

int main()
{
    //Değerler ekleniyor
    push(&head, 12 );
    push(&head, 21 );
    push(&head, 4 );
    push(&head, 25 );

    printList();

   cout << searchRec(head, 45) << endl;
   return 0;
}

//Liste başına dügüm ekler
void push( int data ) { 
    Node *newNode; //Yeni dügüm

    //Liste boşsa 
    if ( head == nullptr ) {
        newNode = new Node;
        newNode->value = data;
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }

    //Son düğüm bulunur
    Node *last = head->prev;
    
    //Yeni düğüm dinamik olarak oluşturuldu
    newNode = new Node;
    newNode->value = data;  
 
    //Yeni düğümüm önceki ve sonraki düğüm değerleri
    newNode->next = head;
    newNode->prev = last;
 
    //Son düğüm ve başlangıç düğümünün next ve prev değerleri güncellendi
    last->next = head->prev = newNode;
 
    //head düğümü newNode yapıldı
    head = newNode;
}

//Liste başına dügüm ekler
void push(Node **head, int data ) { 
    Node *newNode; //Yeni dügüm

    //Liste boşsa 
    if ( *head == nullptr ) {
        newNode = new Node;
        newNode->value = data;
        newNode->next = newNode->prev = newNode;
        *head = newNode;
        return;
    }

    //Son düğüm bulunur
    Node *last = (*head)->prev;
    
    //Yeni düğüm dinamik olarak oluşturuldu
    newNode = new Node;
    newNode->value = data;  
 
    //Yeni düğümüm önceki ve sonraki düğüm değerleri
    newNode->next = *head;
    newNode->prev = last;
 
    //Son düğüm ve başlangıç düğümünün next ve prev değerleri güncellendi
    last->next = (*head)->prev = newNode;
 
    //head düğümü newNode yapıldı
    *head = newNode;
}

//Liste sonuna dügüm ekler
void append( int data ) { 
    Node *newNode; //Yeni dügüm
    
    //Liste boşsa 
    if ( head == nullptr)
    {
        newNode = new Node;
        newNode->value = data;
        newNode->next = newNode->prev = newNode;
        head = newNode;
        return;
    }
 
    //Liste boş değilse
    //Son düğüm bulundu
    Node *last = head->prev;
 
    //Yeni düğüm dinamik olarak oluşturuldu
    newNode = new Node;
    newNode->value = data;
 
    //Yeni düğümün  next'i liste başını gösterdi
    newNode->next = head;
 
    //head'in önceki düğümü yeni düğümü gösterdi
    head->prev = newNode;
 
    //Yeni düğümün prev değeri son düğüm yapıldı
    newNode->prev = last;
 
    //Son düğümün next'i yeni eklenen düğüm yapıldı
    last->next = newNode;
}

//Liste sonuna veya başına artan sırada eleman ekler
void appendAsc( int data ) { 
    Node *newNode; //Yeni dügüm
    Node *last;//Liste içinde dolaşmak için

    //Yeni dügüm yaratıldı
    newNode = new Node;
    newNode->value = data;

    if ( head == nullptr ) { //Head boşsa
        //Liste boşsa
        newNode = new Node;
        newNode->value = data;
        newNode->next = newNode->prev = newNode;
        head = newNode;
    }
    else if ( data <= head->value ) //Head solundaysa
    {
        //Son düğüm bulundu
        last = head->prev;

        //Yeni düğümün  next'i liste başını gösterdi
        newNode->next = head;
 
        //head'in önceki düğümü ve last'ın sonraki düğümü  yeni düğümü gösterdi
        head->prev = last->next = newNode;
 
        //Yeni düğümün prev değeri son düğüm yapıldı
        newNode->prev = last;
 
        //head değiştirildi
        head = newNode;
    }
    else
    {
        //Eklenecek düğüm head'ın sağ tarafında ise
        //Liste içinde dolaşılacak
        last = head;

        //Liste sonuna gelinmediyse, 
        //aktif dügümden sonraki dügümün değeri eklenen değerdem  küçükse sonraki dügüme geç
        while( last->next != head && last->next->value < data ) {
            last = last->next;
        }
        
        if ( last->next == head ) {
            //Son düğüme ekleme yapılmışsa
            newNode->next = head;
            head->prev = last->next = newNode;
            newNode->prev = last;
        }
        else {
            //Ara düğümlere eklenmişse
            newNode->next = last->next;//Yeni düğümün next'i bulunandan sonraki
            last->next = newNode;//Bulunanın next'i yeni düğüm
            newNode->prev = last;//Yeni düğümün prev'i bulunan 
            last->next->prev = newNode;//Bulunan düğümden bir sonrakinin prev'i yeni düğüm
        }
    }
}

//Listeyi ekrana yazdırır
void printList()
{
    //Liste içinde dolaşmak için gerekli pointer
    Node *temp = head;

    cout << "Double CircularLinkList icerigi:" << endl;
    do {
        cout << temp->value << endl;
        temp = temp->next;
    } while( temp != head );
    cout << endl;
}

//Aranılan düğümü siler
void deleteNode( int num) {
    Node *prevNode; //Bir önceki dügüm
    Node* last;//Listede dolaşmak için

    if ( head == nullptr ) {
        //Liste boşsa işlem yapma
        return;
    }
    else if ( head->value == num )
    {
        //Son düğüm bulundu
        last = head->prev;

        //Silinecek bir düğüm varsa 
        if ( last->next == last && last->prev == last) {
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
            head->prev = last;

            delete nodeDeleted;
        }
    }
    else 
    {
        last = head;

        //Silinecek düğüm sonda ya da ortadadır
        while(last->next!=head){
            if(last->value == num ) {
                //Silinecek düğüm ortalarda 
                prevNode->next = last->next;
                last->next->prev = prevNode;
                delete last;
                return;
            }

            prevNode = last;
            last = last->next;
        }

        //Eğer son düğümde bulunduysa 
        if ( last->value == num ) {
            prevNode->next = head;
            head->prev = prevNode;
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