#include <iostream>

using namespace std;

#include "LinkedList.h"

int main()
{
    LinkedList<string> lista;

    lista.addFirst("HOLA");
    lista.addFirst("CRAYOLA");
    lista.addFirst("AQUI");
    lista.addFirst("ESTOY");
    lista.print();
    lista.deleteFirst();
    lista.print();
    lista.addFirst("LUIS");
    lista.print();
    lista.deleteLast();
    cout << lista.getSize() << endl;
    cout << lista.get(2) << endl;
    cout << lista.set("ABC", 1);
    
    return 0;
}