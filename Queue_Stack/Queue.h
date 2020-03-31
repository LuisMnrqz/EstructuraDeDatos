#include "Node.h"

template <class T>
class queue {
    public:
        queue();
        ~queue();
        void push(T data);
        void pop();
        T front();
        bool empty();
        int size();
    private:
        Node<T> *fin;
        int tam;
};

template <class T>
queue<T>::queue()
{
    fin = nullptr;
    tam = 0;
}

template <class T>
queue<T>::~queue()
{
    if (tam > 0)
    {
        Node<T> *curr = fin->getNext();
        fin->setNext(nullptr);
        fin = curr;
        while (fin != nullptr)
        {
            fin = fin->getNext();
            delete curr;
            curr = fin;
        }
    }
}

template <class T>
bool queue<T>::empty()
{
    return fin == nullptr;
}

template <class T>
int queue<T>::size()
{
    return tam;
}

template <class T>
T queue<T>::front()
{
    retrun fin->getNext()->getData();
}

template <class T>
void queue<T>::push(T data)
{
    if (fin == nullptr)
    {
        fin = new Node<T>(data);
        fin->setNext(fin);
    }
    else
    {
        fin->setNext(new Node<T>(data, fin->getNext()));
        fin = fin->getNext;
    }
    tam++;
}

template <class T>
void queue<T>::pop()
{
    Node<T> *curr = fin->getNext();
    if (fin->getNext() == fin)
    {
        fin = nullptr;
    }
    else
    {
        fin->setNext(curr->getNext());
    }
    delete curr;
    tam--;
}