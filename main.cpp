#include <iostream>
#include <vector>
using namespace std;


//////////////////////ZADANIE1 I 2/////////////////////////////////

class MyStack{
private:
    int top;
public:
    MyStack():top(-1), next(nullptr){}
    MyStack(int x):top(x), next(nullptr){}

    MyStack* next;
    void push(int a);
    int peek();
    int pop();
};

void MyStack::push(int a) {
    if(top<0)
    {
        top=a;
    }
    else
    {
        MyStack* temp= new MyStack(top);
        temp->next = next;
        next=temp;
        top=a;
    }
}
int MyStack::peek() {
    return top;
}
int MyStack::pop() {
    if(!next)
    {
        int temp = top;
        top=-1;
        return temp;
    }
    else
    {
        int temp = top;
        top=next->top;
        next=next->next;
        return temp;
    }
}


MyStack* CreateStackPtr(int size)
{
    MyStack* test = new MyStack();
    for(int i=0; i<size; i++)
    {
        test->push(i);
    }
    return test;
}
MyStack* StosL(int m, int l){
    MyStack* temp = new MyStack();
    for(int i=1; i<=m; i++) //sprawdzamy liczby naturalne od 1 bo 0 zawsze byloby wielokrotnoscia czegokolwiek
    {
        if(i%l==0) //jezeli liczba jest podzielna przez l to dodajemy ja na stos
        {
            temp->push(i);
        }
    }
    return temp;
}


MyStack* ReverseStack(MyStack* stack)
{
    MyStack* temp = new MyStack(); //tworze nowy stos
    MyStack* itt = stack; //to jest  niepotrzebne ale wykorzystuje stos z pierwszego zadania
    //i nie chce go modyfikowac dla zobaczenia wynikow

    while(itt)
    {
        temp->push(itt->peek()); //kazdy element ze stosu1 przenosze do stosu2
        itt=itt->next;  //wiec stos mi sie obroci
    }

    return temp; //zwracam obrocony stos
}



//////////////////////ZADANIE3/////////////////////////////////
const int MAX = 20;

class MyStack1 {

    int top;

public:
    MyStack1() {

        top = -1;

    }
    int a[MAX];
    bool push(int a);
    int pop();
    int peek();
    int topval();
};

bool MyStack1::push(int val) {

    if (top >= MAX) {

        printf("Stack overflow!");
        return false;

    }
    else {

        top++;
        a[top] = val;

    }

}
int MyStack1::pop() {
    int temp = a[top];
    a[top]=0;
    top--;
    return temp;
}
int MyStack1::peek() {
    return a[top];
}
int MyStack1::topval() {
    return top;
}

MyStack1* CreateStack(int size)
{
    MyStack1* test = new MyStack1();
    for(int i=0; i<size; i++)
    {
        test->push(i);
    }
    return test;
}

MyStack1* PopN(MyStack1* stack, int n)
{
    if(stack->topval() < n || n < 0) //sprawdzam czy poszukiwana pozycja jest w zakresie stosu
    {
        return stack; //jak nie to po prostu zwracam stos
    }
    for(int i=n; i<=stack->topval(); i++) //przesuwam wszystkie elementy od pozycji usuwanego elementu
    {
        stack->a[i]=stack->a[i+1];
    }
    stack->pop(); //usuwam gore stosu ktora teraz de facto jest pusta ale chce tylko zmienic index top
    return stack;
}



//////////////////////ZADANIE4/////////////////////////////////
struct List
{
    int val;
    List* next;

    List(): next(nullptr){}
    List(int x): val(x), next(nullptr){}
};

List* CreateList(int size,int first_val)
{
    List* head = nullptr;
    List* temp = head;
    for(int i=first_val; i<size+first_val; i++)
    {
        if(temp) {
            temp->next = new List(i);
            temp = temp->next;
        }
        else
        {
            head = new List(i);
            temp=head;
        }
    }
    return head;
}

void MergeLists(List*& list1, List*& list2)
{
    List* place = list1; //tworze sobie kopie wkaznika na glowe listy1
    List* temp; //tworze pomocniczy wskaznik temp
    while(list2) //dopoki sa elementy w liscie2
    {
        temp=list2; //tymczasowo zapisuje sobie element z listy2
        list2=list2->next; //lista2 iteruje na kolejny element
        temp->next=place->next; //tymczasowy element wskazuje na kolejny element listy1
        place->next=temp; //lista1 wskazuje na tymczasowy element
        //czyli wyglada to tak   Lista1.element1 -> temp->element(Lista2.element1) -> Lista1.element2 ->Lista1.element3 itd


        if(place->next->next)   //teraz po prostu przesuwamy sie w liscie 1 o 2 elementy jezeli jest taka mozliwosc
        {
            place=place->next->next;
        }
        else //a jak nie to o jeden(bo moglismy natrafic na koniec listy)
        {
            place=place->next;
        }
    }
}

//////////////////////ZADANIE5/////////////////////////////////

class Queue{
public:
    int first =0;
    int last =-1;
    int a[MAX];
    void enqueue(int x);
    int dequeue();


};

void Queue::enqueue(int x){
    if(last==MAX-1)
    {
        last=-1;
    }
    if(a[last+1]!=0)
    {
        first++;
    }
    a[last+1]=x;
    last++;
}

int Queue::dequeue() {
    int temp = a[first];
    a[first]=0;
    first++;
    if(first==MAX)
    {
        first=0;
    }
    return temp;
}

void UsunX(Queue*& queue,int val)
{
    int first = queue->first;
    int last = queue->last;
    int deleteindex=-1;

    if(first < last) //sprawdzam czy kolejka jest juz nadpisywana czy jeszcze nie
    {
        for(int i=first; i<=last; i++)
        {
            if(queue->a[i]==val)
            {
                deleteindex = i;
                break;
            }
        }
        if(deleteindex==-1) //sprawdzam czy znalazlo element kolejki o poszukiwanej wartosci
        {
            cout << "Nie znaleziono elementu w kolejce." << endl;
            return;
        }
        for(int i=deleteindex; i<last; i++) // jezeli znaleziono element to przesuwam pozostale elementy
        {
            queue->a[i]=queue->a[i+1];
        }
        queue->a[last]=0;
        queue->last--; //i na koniec przesuwam last bo przesuwalem elementy do tylu
    }
    else if(last<first){  //np first 990 a last 25
        for(int i=first; i<MAX; i++) //tutaj wszystko analogicznie tylko musze podzielic to na dwa przypadki
        {   //jeden gdy wartosc jest mniejsza od 0 do last, a druga gdy jest wieksza od first ale mniejsza od MAX
            if(queue->a[i]==val)
            {
                deleteindex = i;
                break;
            }
        }
        if(deleteindex==-1)
        {
            for(int i=0; i<=last; i++)
            {
                if(queue->a[i]==val)
                {
                    deleteindex = i;
                    break;
                }
            }
            if(deleteindex==-1)
            {
                cout << "Nie znaleziono elementu w kolejce." << endl;
                return;
            }
        }

        if(deleteindex>=first)
        {
            for(int i=deleteindex; i>first; i--)
            {
                queue->a[i]=queue->a[i-1];
            }
            queue->a[first]=0;
            queue->first++;

            if(queue->first==MAX) // dodatkowo trzeba sprawdzac czy first i last nie wyjda poza granice kolejki
            {
                queue->first=0;
            }
        }
        else
        {
            for(int i=deleteindex; i<last; i++)
            {
                queue->a[i]=queue->a[i+1];
            }
            queue->a[last]=0;
            queue->last--;

            if(queue->last==-1)
            {
                queue->last=MAX-1;
            }
        }


    }
}



int main() {
    //ZADANIE1
    MyStack* zadanie1 = StosL(13,3);

    //ZADANIE2
    MyStack* zadanie2 = ReverseStack(zadanie1);

    //ZADANIE3
    MyStack1* zadanie3 = CreateStack(50);
    PopN(zadanie3,25);

    //ZADANIE4
    List* lista1 = CreateList(5,0);
    List* lista2 = CreateList(7,6);
    MergeLists(lista1,lista2);

    //ZADANIE5
    Queue* test = new Queue;
    for(int i=1; i<40; i++) //dodaje elementy od i do wybranej liczby do kolejki
    {
        test->enqueue(i);
    }
    UsunX(test,20);


    return 0;
}
