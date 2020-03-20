#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    bool b;
    LinkedList<int> lista1;
    LinkedList<int> lista2;
    lista1.addFirst(3);
    lista2.addFirst(2);
    b = lista1 == lista2;
    /*lista.addFirst("HOLA");
    lista.addFirst("CRAYOLA");
    lista.addFirst("AQUI");
    lista.addFirst("ESTOY");*/
    cout << boolalpha << b;
    /*lista.deleteFirst();
    lista.print();
    lista.addFirst("LUIS");
    lista.print();
    lista.deleteLast();
    cout << lista.getSize() << endl;
    cout << lista.get(2) << endl;
    cout << lista.set("ABC", 1);*/
    

    return 0;
}