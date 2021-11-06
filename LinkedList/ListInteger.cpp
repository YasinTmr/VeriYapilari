#include <iostream>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

void push(Node** head,  int data );//Liste başına dügüm ekler
void printList(Node* head);//Listeyi ekrana yazdırır
void append(Node **head,  int data );//Liste sonuna dügüm ekliyor
void deleteNode(Node** head, int num);//Listeden bir düğüm siliyor
bool search(Node* head, int key);
bool searchRec(Node* head, int key);

int main()
{
    struct Node* head = nullptr;

    //Değerler ekleniyor
    push(&head, 12);
    push(&head, 21);
    push(&head, 7);
    push(&head, 3);
    push(&head, 4);
    append(&head, 27);

    printList(head);

    cout << "search(head, 7): " << search(head, 7) << endl;
    cout << "searchRec(head, 21): " << searchRec(head, 21) << endl;
    cout << "searchRec(head, 45): " << searchRec(head, 45) << endl;
    cout << "searchRec(head, 3): " << searchRec(head, 3) << endl;

   return 0;
}

//Liste başına dügüm ekler
void push(Node **head,  int data ) { 
	Node *newNode = new Node;
	newNode->value = data;
	newNode->next = (*head);
	(*head) = newNode;
}

//Liste sonuna dügüm ekler
void append(Node **head,  int data ) { 
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

        while ( temp->next) {
            temp = temp->next;
        }

        //En son dügüm yeni ekleneni gösterdi
        temp->next = newNode;
    }
}

//Listeyi ekrana yazdırır
void printList(Node* head)
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
void deleteNode(Node** head, int num) {
    Node *previousNode; //Bir önceki dügüm
    Node* temp = *head;//Listede dolaşmak için

    if ( *head == nullptr ) {
        *head = temp->next;     // Head değişti
        delete temp;            // Eski head hafızadan silindi
        return;
    }

    //Silinecek dügüm liste başındaysa
    if ( temp->value == num ) {
        temp = temp->next;
        delete head;
        *head = temp;
    }
    else
    {
        //İşaretçi liste başını gösterir
        temp = *head;

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

//Listede eleman arıyor
bool search(Node* head, int key)
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

//Listede eleman arıyor
bool searchRec(Node* head, int key)
{
    // Base case
    if (head == nullptr)
        return false;
     
    // If key is present in current node, return true
    if ( head->value == key )
        return true;
 
    // Recur for remaining list
    return searchRec(head->next, key);
}