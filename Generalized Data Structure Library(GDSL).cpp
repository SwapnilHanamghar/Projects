#include<iostream>
using namespace std;

template <class T>
struct SLnode
{
    T data;
    struct SLnode<T> * next;
};

template <class T>
class SinglyLL
{
    public:
        struct SLnode<T> * head;
        int iCount;

        SinglyLL();

        void InsertFirst(T no);

        void InsertLast(T no);
        
        void InsertAtPos(T no , int ipos);
          
        void DeleteFirst();
       
        void DeleteLast(); 
        
        void DeleteAtPos(int ipos);
          
        void Display();
        
        int Count();
        
};

template <class T>
SinglyLL<T> :: SinglyLL()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct SLnode<T> * newn = NULL;

    newn = new SLnode<T>;    
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct SLnode<T> * newn = NULL;
    struct SLnode<T> * temp = NULL;

    newn = new SLnode<T>;   
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> :: InsertAtPos(T no , int ipos)
{
    struct SLnode<T> * temp = NULL;
    int i = 0;

    if(ipos < 1 || ipos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct SLnode<T> * newn = NULL; 

        newn = new SLnode<T>;
        newn->data = no;
        newn->next = NULL;
        
        temp = head;
        for(i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
    
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct SLnode<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        head = head -> next;
        delete temp;
        
    }
    iCount--;
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    struct SLnode<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
    struct SLnode<T> * temp = NULL;
    struct SLnode<T> * target = NULL;
    int i = 0;

    if(ipos < 1 || ipos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;
        for(i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;
        delete target;

        iCount--;
    }

}

template <class T>
void SinglyLL<T> :: Display()
{
    struct SLnode<T> * temp = head;

    cout<<"Elements of LinkedList are : \n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }

    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T> :: Count()
{
    return iCount;
}

template <class T>
struct DLnode
{
    T data;
    struct DLnode<T> *next;
    struct DLnode<T> *prev;
};

template <class T>
class DoublyLL
{
    public:
        int iCount;
        struct DLnode<T> * head;

        DoublyLL();
       
        void InsertFirst(T no);

        void InsertLast(T no);

        void InsertAtPos(int ipos, T no);

        void DeleteAtPos(int ipos);
       
        void DeleteFirst();

        void DeleteLast(); 

        void Display();

        int Count();     
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    iCount = 0;
    head = NULL;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct DLnode<T> * newn = NULL;

    newn = new DLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct DLnode<T> * temp = NULL;
    struct DLnode<T> * newn = NULL;

    newn = new DLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        temp = head;
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
void DoublyLL<T> :: InsertAtPos(int ipos, T no)
{
    if(ipos < 1 && ipos > iCount+1)
    {
        cout<<"Invalid Position\n";
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct DLnode<T> * newn = NULL;
        struct DLnode<T> * temp = NULL;
        int i = 0;

        newn = new DLnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = head;
        for(i = 1; i < ipos-1; i++)
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
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
    if(ipos < 1 && ipos > iCount)
    {
        cout<<"Invalid Position\n";
    }
    
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct DLnode<T> * target = NULL;
        struct DLnode<T> * temp = NULL;
        int i = 0;

        temp = head;
        for(i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;
        delete target;

        iCount--;
    }   
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    struct DLnode<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct DLnode<T> * temp = NULL;

    if(head == NULL)
    {
        return;
    }
    if(head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;

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
void DoublyLL<T> :: Display()
{
    struct DLnode<T> * temp = head;
    
    cout<<"ELements of the LL are : NULL <=>";
    while(temp != NULL)
    {
        cout<<" | "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}


template <class T>
struct SCnode
{
    T data;
    struct SCnode<T> *next;
};

template <class T>
class SinglyCL
{
    public:
        struct SCnode<T> *  head;
        struct SCnode<T> *  tail;
        int iCount;

        SinglyCL();

        void InsertFirst(T no);
       
        void InsertLast(T no);
       
        void DeleteFirst();
       
        void DeleteLast();

        void InsertAtPos(T no,int ipos);
       
        void DeleteAtPos(int ipos);

        void Display();

        int Count();
};        

template <class T>
SinglyCL<T> :: SinglyCL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct SCnode<T> *  newn = NULL;

    newn = new SCnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    tail->next = head;

    iCount++;
}

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct SCnode<T> *  newn = NULL;

    newn = new SCnode<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL & tail == NULL)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        tail = newn;
    }
    tail->next = head;

    iCount++;
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        delete (tail->next);
        tail->next = head;
    }

    iCount--;
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct SCnode<T> *  temp = NULL;

    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete tail;
        head = NULL;
        tail = NULL;
    }
    else
    {
        temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        tail = temp;
        delete(temp->next);
        tail->next = head;
    }

    iCount--;
}

template <class T>
void SinglyCL<T> :: InsertAtPos(T no,int ipos)
{
    struct SCnode<T> *  newn = NULL;
    struct SCnode<T> *  temp = NULL;

    int i = 0;

    if(ipos < 1 || ipos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SCnode<T>;
        newn->data = no;
        newn->next = NULL;

        temp = head;

        for(i = 1; i < (ipos-1); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(int ipos)
{
    struct SCnode<T> *  temp = NULL;
    struct SCnode<T> *  target = NULL;

    int i = 0;

    if(ipos < 1 || ipos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    if(ipos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        temp = head;
        for(i = 1; i < (ipos-1); i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;

        iCount--;
    }
}

template <class T>
void SinglyCL<T> :: Display()
{
    if(head == NULL && tail == NULL)
    {
        cout<<"LL is Empty\n";
        return;
    }

    cout<<"Nodes of Singly Circular : \n";
    do
    {
        cout<<" | "<<head->data<<" | > ";
        head = head->next;
    }while(head != tail->next);

    cout<<"\n";
}

template <class T>
int SinglyCL<T> :: Count()
{
    return iCount;
}


template <class T>
struct DCnode
{
    T data;
    struct DCnode<T> *next;
    struct DCnode<T> *prev;
};

template <class T>
class DoublyCL
{
    public:
        struct DCnode<T> * head;
        struct DCnode<T> * tail;
        int iCount;

        DoublyCL();
    
        void InsertFirst(T no);

        void InsertLast(T no);

        void DeleteFirst();

        void DeleteLast();

        void InsertAtPos(T no, int ipos);

        void DeleteAtPos(int ipos);

        void Display();
       
        int Count();
};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct DCnode<T> * newn = NULL;

    newn = new DCnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    tail->next = head;
    head->prev = tail;

    iCount++;
}

template <class T>
void DoublyCL<T> :: InsertLast(T no)
{
    struct DCnode<T> * newn = NULL;

    newn = new DCnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(head == NULL && tail == NULL)
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        newn->prev = tail;

        tail = newn;
    }
    tail->next = head;
    head->prev = tail;

    iCount++;

}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        delete (tail->next);
        head->prev = tail;
        tail->next = head;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if(head == NULL && tail == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        delete tail;
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        delete (head->prev);
        
        tail->next = head;
        head->prev = tail;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
    struct DCnode<T> * newn = NULL;
    struct DCnode<T> * temp = NULL;
    int i = 0;

    if(ipos < 1 || ipos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    if(ipos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DCnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->next = NULL;

        temp = head;

        for(i = 1; i < ipos-1; i++)
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
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    struct DCnode<T> * temp = NULL;
    struct DCnode<T> * target = NULL;
    int i = 0;

    if(ipos < 1 || ipos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    if(ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;
        for(i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;

        iCount--;
    }
}

template <class T>
void DoublyCL<T> :: Display()
{
    if(head == NULL && tail == NULL)
    {
        cout<<"LL is Empty\n";
        return;
    }

    cout<<"Elements of Doubly Circular LL are : \n";
    do
    {
        cout<<" | "<<head->data<<" | <=> ";
        head = head->next;
    }while(head != tail->next);

    cout<<"\n";
}

template <class T>
int DoublyCL<T> :: Count()
{
    return iCount;
}

int main()
{
    return 0;
}
