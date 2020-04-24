#include <iostream>
#include "BST.h"

using namespace std;

int main(){
	BST miArbol;
	miArbol.add(20);
	miArbol.add(50);
	miArbol.add(44);
	miArbol.add(10);
	miArbol.add(15);
	miArbol.add(9);
	miArbol.add(100);
	miArbol.add(60);
	miArbol.add(8);
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
}