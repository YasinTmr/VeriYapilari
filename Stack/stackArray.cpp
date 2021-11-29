#include <iostream>
#include <limits.h>
#include <vector>
#include <string>
using namespace std;

#define MAX 100

// Stack veri yapısı
struct Stack {
    int top;
    int array[MAX];
};


Stack * createStack();
bool push(Stack *stack, int x);
int pop(Stack *stack);
void printStack(Stack *stack);
int peek( Stack *stack );
int peek(Stack *stack, int index);
bool isEmpty( Stack *stack );
bool isFull( Stack * stack);
void printNextGraterElement(Stack *stack);
Stack *reverseStack(Stack * stack);

int main() {
    Stack *stack = createStack();
    push(stack, 3);
    push(stack, 21);
    push(stack, 13);
    push(stack, 11);

    printStack( stack );
    printNextGraterElement(stack);
    stack = reverseStack( stack );
    printStack( stack );
    printNextGraterElement(stack);
    return 0;
}

//Stack oluşturuluyor
Stack * createStack() {
    Stack *stack = new Stack;
    stack->top = -1;
    return stack;
}

//Yığının en sonuna eleman eklendi
bool push(Stack *stack, int x)
{
    if (stack->top >= (MAX - 1)) {
        cout << "Yıgın üst taşması meydana geldi";
        return false;
    }
    else {
        stack->array[++stack->top] = x;
        cout << x << " yıgının sonuna atıldı\n";
        return true;
    }
}

//En tepedeki eleman silindi
int pop(Stack *stack)
{
    if ( stack->top < 0 ) {
        cout << "Yıgın alt taşması meydana geldi";
        return 0;
    }
    else {
        return stack->array[stack->top--];
    }
}

//Stack içerigi ekrana yazdırır
void printStack(Stack *stack)
{
    cout << "Stack icerigi:" << endl;
    for(int i=stack->top;i>=0;i-- ) {
        cout << stack->array[i] << endl;
    }
    cout << endl;
}

//En tepedeki eleman değeri döndürüldü
int peek( Stack *stack )
{
    if (stack->top < 0) {
        cout << "Stack boş";
        return 0;
    }
    else {
        return stack->array[stack->top];
    }
}

//En tepedeki index değerine sahip eleman döndürülür
int peek(Stack *stack, int index)
{
    if(stack->top- index + 1 < 0 ) {
        cout<< "Hatalı indis degeri" << endl;
        return -1;
    }
    else {
        return stack->array[stack->top- index + 1];
    }   
}

//Stack boş ise true degilse false döndürür
bool isEmpty( Stack *stack )
{
    return stack->top < 0;
}

//Stack dolu ise true, degilse false değer döndürür
bool isFull( Stack * stack)
{
    int size = sizeof(stack->array) / sizeof(stack->array[0]);
     return stack->top == size - 1;
}

//Stack'te kendisinden bir sonraki en büyük ilk elemanı ekrana yazdıran
//Kendisinden sonra büyük eleman yoksa -1 yazsın
void printNextGraterElement(Stack *stack)
{
   for(int i = stack->top; i >=0;  i--) {
       int nextGreater = -1;
       for (int j = i - 1; j >= 0; j -- ) {
           if (  stack->array[j] >  stack->array[i] ) {
               nextGreater = stack->array[j];
               break;
           }
       }

       cout << stack->array[i] << " --> " << nextGreater << endl;
   } 
}

Stack *reverseStack(Stack * stack) {
   Stack *temp = createStack();
   while( !isEmpty(stack) ) {
       int value = pop( stack );
       push( temp, value);
   }

   return temp;
}