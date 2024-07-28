#include<iostream>
using namespace std;

/////////////////////////////////
//code of singly linear 
////////////////////////////////
template <class T>
struct nodeSL
{
    T data;
    nodeSL *next; // Use of 'nodeSL *next;' instead of 'struct nodeSL<T> *next;'
};

template <class T>
class SinglyLL {
private:
    nodeSL<T> *first; // Corrected to 'node<T> *first;' for clarity and consistency
    int iCount;
    
public:
    SinglyLL();    
    void Display();
    int Count() ; // Implementation of Count
    
    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertatPos(T No, int Pos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteatPos(int iPos);

};

template <class T>
 SinglyLL<T>::SinglyLL()
    {
        cout<<"Inside Constructor\n";
        first = NULL;
        iCount = 0;
    }   

template <class T>
void SinglyLL<T>::Display()//linked list display
{
    struct nodeSL<T> * temp = first;// why ? because we dont want to change the first node<T><T>

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>

int  SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = new nodeSL<T> ;//malloc in c

    newn->data = No;
    newn->next = NULL;

    if(first == NULL) //or iCount == 0
    {
        first = newn;
    }

    else if(first->next == NULL)
    {
        newn->next = first;
        first = newn;
    }   

    else
    {
        newn->next = first;
        first = newn;
    }

    iCount++;

}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    nodeSL<T> *newn = new nodeSL<T>();
     nodeSL<T> * temp = first;

    newn->data = No;
    newn->next = NULL;

    if(first == NULL)//or iCount == 0
    {
        first = newn;
    }
    else if(first->next == NULL)//or iCount == 1
    {
        first->next = newn;
    }

    else//iCount > 1
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
   
}


template <class T>
void SinglyLL<T>::InsertatPos(T no, int pos)
{
    int size = iCount;

    if((pos < 1) || (pos > size+1))
    {
        cout << "Position out of range" << endl;
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeSL<T> * newn = new nodeSL<T>;
        struct nodeSL<T> * temp = first;

        newn->data = no;
        newn->next = NULL;

        for(int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
    //iCount ++ should not be here bcoz it is already done in InsertFirst and InsertLast
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = first;
    if(first == NULL)
    {
        cout<<"LL is empty";
        return;
    }
    else if(first -> next == NULL)
   {
    delete first;
    first = NULL;
   }
   else
   {
    first = first -> next;
    delete temp;
   }
   iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = first;
    if(first == NULL)
    {
        cout<<"LL is empty";
        return;
    }
    else if(first -> next == NULL)
   {
    delete first;
    first = NULL;
   }
   else
   {
    //logic if there are more than 1 mode 
    while(temp -> next -> next != NULL)
    {
        temp = temp ->next;
    }
    delete temp ->next;
    temp->next = NULL;
   }
   iCount--;
   
}

template <class T>
void SinglyLL<T>::DeleteatPos(int iPos)
{
   //logic for delete at position 

    if((iPos < 1) || (iPos > iCount))
    {
        cout << "Position out of range" << endl;
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeSL<T> * temp1 = first;
        struct nodeSL<T> * temp2 = NULL;

        for(int i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
        iCount--;
    }
}

//////////////////////////////////
//code of doubly circular 
///////////////////////////////
template <class T>
struct nodeDC 
{
    T data;
    struct nodeDC<T> *next;
    struct nodeDC<T> *prev;
};



template <class T>

class DoublyCL
{
    private:
        struct nodeDC<T> * First;
        struct nodeDC<T> * Last;
        int iCount;

    public:
        DoublyCL();
        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No,int iPos);

        void DeleteFirtst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

};

template <class T>

DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>

void DoublyCL<T>::Display()
{
    do 
    {
        cout<<"|"<<First->data<<"|<->";
        First = First->next;
    } while (First != Last->next);

}

template <class T>

int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>

void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = new nodeDC<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }

    Last->next = First;
    First->prev = Last;
    iCount++;


}

template <class T>

void DoublyCL<T>::InsertLast(T No)
{
     struct nodeDC<T> * newn = new nodeDC<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }

    Last->next = First;
    First->prev = Last;
    iCount++;   
}

template <class T>

void DoublyCL<T>::InsertAtPos(T No,int iPos)
{
    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position\n"; 
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeDC<T> * newn = new nodeDC<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        struct nodeDC<T> * temp = First;
        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

template <class T>

void DoublyCL<T>::DeleteFirtst()
{
    //delete first node
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)//single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else//more than one node
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
        First->prev = Last;
    }
    iCount--;
    
}

template <class T>

void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)//single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete First->prev;
        Last->next = First;
        First->prev = Last;  
    }
}

template <class T>


void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirtst();
    }

    else if(iPos == iCount)
    {
        DeleteLast();
    }

    else
    {
        struct nodeDC<T> * temp = First;
        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

//////////////////////////////////
//code oF doubly linear 
///////////////////////////////
template<class T>
struct nodeDL
{
    T data;
    struct nodeDL<T> *next;
    struct nodeDL<T> *prev;
};



template <class T>
class DoublyLL
{
    private:
        struct nodeDL<T> * First;
        int iCount;

    public:
        
        DoublyLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};
template <class T>
 DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>

void DoublyLL<T>::InsertFirst(T iNo)
{
    struct nodeDL<T> * newn = new nodeDL<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T iNo)
{
    struct nodeDL<T> * newn = new nodeDL<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct nodeDL<T> * temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T iNo, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        struct nodeDL<T> * newn = new nodeDL<T>;
        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        struct nodeDL<T> * temp = First;
        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeDL<T> * temp = First;
        First = First->next;
        delete temp;
        First->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeDL<T> * temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeDL<T> * temp = First;
        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        struct nodeDL<T> * target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;
        iCount--;
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T> * temp = First;
    while(temp != NULL)
    {
        cout<<temp->data<<"=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}





//////////////////////////////////
//code oF singly circular 
///////////////////////////////

template<class T>
struct nodeSC
{
    T data;
    struct nodeSC<T> *next;
};


template<class T>
class SinglyCL{
    private:
        struct nodeSC<T> *Head;
        struct nodeSC<T> *Tail;
        int iSize;
    public:
        SinglyCL()
        {
            Head = NULL;
            Tail = NULL;
            iSize = 0;
        }
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPos(T iNo,int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};
template<class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
    struct nodeSC<T>* newn = new nodeSC<T>;
    newn->data = iNo;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL){
        Head = newn;
        Tail = newn;
    }
    else{
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
    iSize++;
}

template <class T>
void SinglyCL<T>::InsertLast(T iNo)
{
    struct nodeSC<T>* newn = new nodeSC<T>;
    newn->data = iNo;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL){
        Head = newn;
        Tail = newn;
    }
    else{
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
    iSize++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T iNo,int iPos)
{
    if(iPos < 1 || iPos > iSize+1){
        return;
    }
    if(iPos == 1){
        InsertFirst(iNo);
    }
    else if(iPos == iSize+1){
        InsertLast(iNo);
    }
    else{
        struct nodeSC<T>* newn = new nodeSC<T>;
        newn->data = iNo;
        newn->next = NULL;

        struct nodeSC<T>* temp = Head;
        for(int i = 1; i < iPos-1; i++){
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iSize++;
    }
}

template<class T>

void SinglyCL<T>::DeleteFirst(){
    if(Head == NULL && Tail == NULL){
        return;
    }
    else if(Head == Tail){
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else{
        Head = Head->next;
        delete Tail->next;
        Tail->next = Head;
    }
    iSize--;
}

template<class T>
void SinglyCL<T>::DeleteLast(){
    if(Head == NULL && Tail == NULL){
        return;
    }
    else if(Head == Tail){
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else{
        struct nodeSC<T>* temp = Head;
        while(temp->next != Tail){
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
        Tail->next = Head;
    }
    iSize--;
}
template<class T>
void SinglyCL<T>::DeleteAtPos(int iPos){
    if(iPos < 1 || iPos > iSize){
        return;
    }
    if(iPos == 1){
        DeleteFirst();
    }
    else if(iPos == iSize){
        DeleteLast();
    }
    else{
        struct nodeSC<T>* temp = Head;
        for(int i = 1; i < iPos-1; i++){
            temp = temp->next;
        }
        struct nodeSC<T>* temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
        iSize--;
    }
}
template<class T>
void SinglyCL<T>::Display(){
    struct nodeSC<T>* temp = Head;
        do{
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }while(temp != Tail->next);
}

template<class T>
int SinglyCL<T>::Count(){
    return iSize;
}

//////////////////////////////////
//code oF stack
///////////////////////////////

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template <class T>
class Stack
{
    private:
        struct nodeS<T> *Head;
        int iSize;
    public:
        Stack()
        {
            Head = NULL;
            iSize = 0;
        }
        void Push(T iNo);
        T Pop();
        void Display();
        int Count();
};

template <class T>
void Stack<T>::Push(T iNo)
{
    struct nodeS<T> *newn = new nodeS<T>;
    newn->data = iNo;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    iSize++;
}

template <class T>
T Stack<T>::Pop()
{
    if(Head == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else
    {
        T iRet = Head->data;
        struct nodeS<T> *temp = Head;
        Head = Head->next;
        delete temp;
        iSize--;
        return iRet;
    }
}

template <class T>
void Stack<T>::Display()
{
    struct nodeS<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int Stack<T>::Count()
{
    return iSize;
}

//////////////////////////////////
//code oF Queue
///////////////////////////////

template <class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template <class T>
class Queue
{
    private:
        struct nodeQ<T> *Head;
        int iSize;
    public:
        Queue()
        {
            Head = NULL;
            iSize = 0;
        }
        void Enqueue(T iNo);
        T Dequeue();
        void Display();
        int Count();
};

template <class T>
void Queue<T>::Enqueue(T iNo)
{
    struct nodeQ<T> *newn = new nodeQ<T>;
    newn->data = iNo;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    iSize++;
}

template <class T>
T Queue<T>::Dequeue()
{
    if(Head == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else
    {
        T iRet = Head->data;
        struct nodeQ<T> *temp = Head;
        Head = Head->next;
        delete temp;
        iSize--;
        return iRet;
    }
}

template <class T>
void Queue<T>::Display()
{
    struct nodeQ<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int Queue<T>::Count()
{
    return iSize;
}





///////////////////////////////////
//main
//////////////////////////////////

int main()
{

     SinglyLL<float> *obj = new SinglyLL<float>;//dynamic memory allocation
    int iRet = 0;

    obj->InsertFirst(90.43);
    obj->InsertFirst(80.43);
    obj->InsertFirst(70.43);

    obj->InsertLast(100.43);
    obj->InsertLast(110.43);
    obj->InsertLast(120.43);
 
    obj->Display();
    iRet = obj->Count();
    cout<<"Number of elements are : "<<iRet<<"\n";
    
    obj->InsertatPos(50.43, 5);
    
    obj->Display();
     iRet = obj->Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    obj->InsertatPos(60.43, 6);
     iRet = obj->Count();
    cout<<"Number of elements are : "<<iRet<<"\n";


    //SinglyLL of char
    SinglyLL<char> *cobj = new SinglyLL<char>;//dynamic memory allocation

    cobj->InsertFirst('a');
    cobj->InsertFirst('b');
    cobj->InsertFirst('c');

    cobj->InsertLast('d');
    cobj->InsertLast('e');
    cobj->InsertLast('f');
 
    cobj->Display();
    
    
    cobj->InsertatPos('f', 5);
    
    cobj->Display();

    cobj->InsertatPos('g', 6);

    //////////////////////////////////////
    DoublyCL<int> *iobj = new DoublyCL<int>();

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);

   
    iobj->DeleteAtPos(4);

    iobj->Display();

    return 0;
}