#include "Node.h"
using namespace std;

template <class T>
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty();
        void addFirst(T data);
        void addLast(T data);
        bool add(T data, int pos);
        void deleteFirst();
        void deleteLast();
        void del(int pos);
        int deleteAll();
        T set(T data, int pos);
        T get(int pos);
        bool change(int pos1, int pos2);
        void print();
        int getSize();
    private:
        Node<T> *head;
        int size;
}; 

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    size = 0;
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    return (size == 0);
}

template <class T>
int LinkedList<T>::getSize()
{
    return size;
}

template <class T>
void LinkedList<T>::addFirst(T data)
{
    head = new Node<T>(data, head);
    size++;
}

template <class T>
void LinkedList<T>::addLast(T data)
{
    if (size == 0)
    {
        addFirst(data);
    }

    else
    {
        Node<T> *curr = head;
        while (curr->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
bool LinkedList<T>::add(T data, int pos)
{
    if (pos > size)
    {
        return false;
    }

    if (pos == 0)
    {
        addFirst(data);
    }

    else if (pos == size)
    {
        addLast(data);
    }

    else 
    {
        Node<T> *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    return true;
}

template <class T>
void LinkedList<T>::deleteFirst()
{
    if (size > 0)
    {
        Node<T> *curr = head;
        head = head->getNext();
        size--;
        delete curr;
    }
}

template <class T>
void LinkedList<T>::deleteLast()
{
    if (size < 2)
    {
        deleteFirst();
    }

    else
    {
        Node<T> *curr = head;
        while (curr->getNext()->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        delete curr->getNext();
        size--;
        curr->setNext(nullptr);
    }
}

template <class T>
void LinkedList<T>::del(int pos)
{
    if (pos == 0)
    {
        deleteFirst();
    }

    else if (pos == size - 1)
    {
        deleteLast();
    }

    else 
    {
        Node<T> *curr = head;
        for (int i = 0; i < pos; i++)
        {
            curr = curr->getNext();
        }
        Node <T> *aux = curr->getNext();
        curr->setNext(aux->getNext());
        delete aux;
        size --;
    }
}

template <class T>
int LinkedList<T>::deleteAll()
{
    Node<T> *curr = head;

    while (head != nullptr)
    {
        head = head->getNext();
        delete curr;
        curr = head;
    }
    int auxSize = size;
    size = 0;
    return auxSize;
}

template <class T>
void LinkedList<T>::print()
{
    Node<T> *curr = head;

    while (curr != nullptr)
    {
        cout << curr->getData() << endl;
        curr = curr->getNext();
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *curr = head;

    while (head != nullptr)
    {
        head = head->getNext();
        delete curr;
        curr = head;
    }
}

template <class T>
T LinkedList<T>::get(int pos)
{
    Node<T> *curr = head;
    int i = 0;

    if (curr == nullptr)
    {
        return NULL;
    }

    else 
    {
        if (pos >= 0 && pos <= size)
        {
            while (curr != nullptr)
            {
                if (i = pos)
                {
                    return curr->getData();
                }
                i++;
                curr = curr->getNext();
            }
        }

        else
        {
            return NULL;
        }
        
    }
}

template <class T>
T LinkedList<T>::set(T data, int pos)
{
    Node<T> *curr = head;
    T temp;

    if (pos < 0 || pos > size)
    {
        return NULL;
    }

    for (int i = 0; i < pos && head != nullptr; i++)
    {
        if (i == pos - 1)
        {
            temp = head->data;
            head->data = data;
            return temp;
        }
    }
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2)
{
    Node<T> *temp;
    Node<T> *refhead = head;
    Node<T> *pos1curr = head;
    Node<T> *pos1prev = NULL;
    Node<T> *pos2curr = head;
    Node<T> *pos2prev = NULL;

    if (head == nullptr || size == 1)
    {
        return false;
    }

    else if (pos1 >= 0 && pos1 <= size && pos2 <= 0 && pos2 >= size)
    {
        if (pos1 == pos2)
        {
            return true;
        }   

        //Buscar y guardar anterior a 1
        while (pos1curr && pos1curr->data != pos1)
        {
            pos1prev = pos1curr;
            pos1curr= pos1curr->next;
        }

        //Buscar y guardar anterior a 2
        while (pos2curr && pos2curr->data != pos2)
        {
            pos2prev = pos2curr;
            pos2curr= pos2curr->next;
        }

        //pos1 not head
        if (pos1curr != nullptr)
        {
            pos1prev->next = pos2curr;
        }

        //pos1 head
        else
        {
            *refhead = pos2curr;
        }
        
        //pos2 not head
        if (pos2curr != nullptr)
        {
            pos2prev->next = pos1curr;
        }

        //pos2 head
        else
        {
            *refhead = pos1curr;
        }

        *temp = pos2curr->next;
        pos2curr->next = pos1curr->next;
        pos1curr->next = temp;
        return true;
    }
}