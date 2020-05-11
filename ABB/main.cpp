#include <iostream>
#include "BST.h"

using namespace std;

int main(){
	BST miArbol, arbol2, arbol3, arbol4;
	miArbol.add(20);
	miArbol.add(50);
	miArbol.add(44);
	miArbol.add(10);
	miArbol.add(15);
	miArbol.add(9);
	miArbol.add(100);
	miArbol.add(60);
	miArbol.add(8);
	miArbol.add(55);
	miArbol.add(58);
	miArbol.add(15);
	miArbol.add(18);
	miArbol.add(16);
	miArbol.add(17);
	arbol2.add(20);
	arbol2.add(50);
	arbol2.add(44);
	arbol2.add(10);
	arbol2.add(15);
	arbol2.add(9);
	arbol2.add(100);
	arbol2.add(60);
	arbol2.add(8);
	arbol2.add(55);
	arbol2.add(58);
	arbol2.add(15);
	arbol2.add(18);
	arbol2.add(16);
	miArbol.print(1);
	miArbol.print(2);
	miArbol.print(3);
	if (miArbol.search(8)){
		cout << "Si esta el 8"<<endl;
	}
	else{
		cout << "No esta el 8" << endl;
	}
	if (miArbol.search(80)){
		cout << "Si esta el 80"<<endl;
	}
	else{
		cout << "No esta el 80" << endl;
	}	
	if (miArbol.search(10)){
		cout << "Si esta el 10"<<endl;
	}
	else{
		cout << "No esta el 10" << endl;
	}
	//miArbol.remove(20);
	miArbol.print(1);
	miArbol.print(2);
	miArbol.print(3);
	miArbol.print(4);
	cout << "El árbol tiene: "<< miArbol.count() << " nodos" << endl;
	cout << "La altura del árbol es: "<< miArbol.height() << endl;
	miArbol.ancestors(8);
	cout << endl;
	cout << miArbol.whatLevelamI(10) << endl;
	miArbol.print(5);
	cout << miArbol.maxWidth() << endl;
	cout << "-------------" << endl;
	cout << miArbol.nearstRelative(50, 10) << endl;
	if (miArbol == arbol2){
		cout << "Iguales" << endl;
	}
	else
	{
		cout << "No iguales" << endl;
	}
	cout << "-------------" << endl;
	BST arbolitoCopy(miArbol);
	arbolitoCopy.print(1);
	cout << endl;
	miArbol.print(1);
}