#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<string> lista;

    lista.addFirst("HOLA");
    lista.addFirst("CRAYOLA");
    lista.addFirst("AQUI");
    lista.addFirst("ESTOY");
    lista.print();
    lista.reverse();
    cout << endl;
    lista.print();

    return 0;
}