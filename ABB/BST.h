#ifndef BST_h
#define BST_h
#include "NodeT.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class BST{
	public:
		BST();
		~BST();
		bool search(int data);
		void add(int data);
		void remove(int data);
		void print(int tipo);
		void printLeaves();
		// tipo 1 = preorden
		// tipo 2 = inorden
		// tipo 3 = postorden;
		// tipo 4 = Imprimir Hojas
		// tipo 5 = Nivel x Nivel
		int count();
		int height();
		void ancestors(int dato);
		int whatLevelamI(int dato);
		int maxWidth();
		int nearstRelative(int num1, int num2);
		BST(const BST& copia);
	private:
		NodeT *root;
		int howManyChildren(NodeT *r);
		int succ(NodeT *r);
		int pred(NodeT *r);
		void preorden(NodeT *r);
		void inorden(NodeT *r);
		void postorden(NodeT *r);
		void destruye(NodeT *r);
		void preordenLeaves(NodeT *r);
		int countRec(NodeT *r);
		int heightMax(NodeT *r);
		void nivelPorNivel(NodeT *r);
		int getWidth(NodeT *r, int level);
		void copy(NodeT *i);
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destruye(root);
}

void BST::destruye(NodeT *r){
	if (r != nullptr){
		destruye(r->getLeft());
		destruye(r->getRight());
		delete r;
	}
}

int BST::howManyChildren(NodeT *r){
	int cont = 0;
	if (r->getLeft() != nullptr){
		cont++;
	}
	if (r->getRight() != nullptr){
		cont++;
	}
	return cont;
}

int BST::succ(NodeT *r){
	NodeT *curr = r->getRight();
	while (curr->getLeft() != nullptr){
		curr = curr->getLeft();
	}
	return curr->getData();
}

int BST::pred(NodeT *r){
	NodeT *curr = r->getLeft();
	while (curr->getRight() != nullptr){
		curr = curr->getRight();
	} 
	return curr->getData();
}

void BST::preordenLeaves(NodeT *r){
	if (r != nullptr){
		if (howManyChildren(r) == 0){
			cout << r->getData() << " " ;			
		}
		else{
			preordenLeaves(r->getLeft());
			preordenLeaves(r->getRight());
		}
	}
}

int BST::count(){
	return countRec(root);
}

int BST::countRec(NodeT *r){
	if (r == nullptr){
		return 0;
	}
	return 1 + countRec(r->getLeft())+countRec(r->getRight());
}
//----------------------------------------------------------------------------------------------------------------
//TAREA OPERACIONES BST 1
int BST::height(){
	return heightMax(root);
}

int BST::heightMax(NodeT *r){
	if (r == nullptr){
		return 0;
	}

	else
	{
		int maxRight = heightMax(r->getRight());
		int maxLeft = heightMax(r->getLeft());

		if (maxLeft > maxRight){
			return (maxLeft + 1);
		}

		else return (maxRight + 1);
	}
}

void BST::ancestors(int dato){
	NodeT *curr = root;
	stack<int> stack;

	while (curr->getData() != dato){
		stack.push(curr->getData());
		curr = (curr->getData() > dato) ? curr->getLeft() : curr->getRight();
	}

	while (!stack.empty()){
		cout << stack.top() << " ";
		stack.pop();
	}
}

int BST::whatLevelamI(int dato){
	int level = 0;
	NodeT *curr = root;

	while (curr != nullptr){
		if (curr->getData() == dato){
			return level;
		}

		else
		{
			curr = (curr->getData() > dato) ? curr->getLeft() : curr->getRight();
		}
		level++;
	}
	//No se encuentra
	return -1;
}

void BST::nivelPorNivel(NodeT *r){
	//Árbol vacío
    if (r == nullptr) {
		return;
	}  
  
    queue<NodeT *> queue;  
    queue.push(root);  
  
    while (queue.empty() == false) {   
        int numNodos = queue.size();  
  
        while (numNodos > 0) {  
            NodeT *nodo = queue.front();  
            cout << nodo->getData() << " ";  
            queue.pop();  

            if (nodo->getLeft() != nullptr) {
				queue.push(nodo->getLeft());
			} 

            if (nodo->getRight() != nullptr) {
				queue.push(nodo->getRight()); 
			} 
            numNodos--;  
        } 
    } 
}
//----------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------
//TAREA OPERACIONES BST 2
int BST::maxWidth(){
	int level = heightMax(root);
	int maxWidth = 0;

	for (int i = 1; i <= level; i++){
		int currWidth = getWidth(root, i);
		if (currWidth > maxWidth){
			maxWidth = currWidth;
		}
	}
	return maxWidth;
}

int BST::getWidth(NodeT *r, int level){
	if (r == nullptr){
		return 0;
	}

	if (level == 1){
		return 1;
	}

	else if (level > 1){
		return getWidth(r->getLeft(), level - 1) + getWidth(r->getRight(), level - 1);
	}
}

int BST::nearstRelative(int num1, int num2){
	if (root == nullptr){
		return -1;
	}

	queue<int> queue1, queue2;
	NodeT *curr1 = root;
	while (curr1->getData() != num1){
		queue1.push(curr1->getData());
		curr1 = (curr1->getData() > num1) ? curr1->getLeft() : curr1->getRight();
	}
	
	NodeT *curr2 = root;
	while (curr2->getData() != num2){
		queue2.push(curr2->getData());
		curr2 = (curr2->getData() > num2) ? curr2->getLeft() : curr2->getRight();
	}

	int aux = 0;
	while (queue1.front() == queue2.front()){
		aux = queue1.front();
		//Caso que los dos elementos a buscar son hijos del mismo padre, ya que si se quedan ambas filas vacías el valor de retorno será 0
		//El único caso en el que las ambas filas llegan a tener tamaño de 1 independientemente del nivel en el que se encuentren, es que los elementos que se están buscando son hijos del mismo padre
		if (queue1.size() && queue2.size() == 1){
			return aux;
		}
		queue1.pop();
		queue2.pop();
	}
	return aux;
}

BST::BST(const BST &copia){
    NodeT *i = copia.root;
    copy(i);
}

void BST::copy(NodeT *i){
    if(i != nullptr){
        this->add(i->getData());
        copy(i->getLeft());
        copy(i->getRight());
    }
}


//----------------------------------------------------------------------------------------------------------------

void BST::preorden(NodeT *r){
	if (r != nullptr){
		cout << r->getData() << " " ;
		preorden(r->getLeft());
		preorden(r->getRight());
	}
}

void BST::inorden(NodeT *r){
	if (r != nullptr){
		inorden(r->getLeft());
		cout << r->getData() << " " ;
		inorden(r->getRight());
	}
}

void BST::postorden(NodeT *r){
	if (r != nullptr){
		postorden(r->getLeft());
		postorden(r->getRight());
		cout << r->getData() << " " ;
	}
}

void BST::print(int tipo){
	switch(tipo){
		case 1: preorden(root);
				break;
		case 2: inorden(root);
				break;
		case 3: postorden(root);
				break;
		case 4: preordenLeaves(root);
				break;
		case 5: nivelPorNivel(root);
				break;
	}
	cout << endl;
}

bool BST::search(int data){
	if (root == nullptr){
		return false;
	}
	NodeT *curr = root;
	while (curr != nullptr){
		if (curr->getData() == data){
			return true;
		}
/*		if (curr->getData() > data){
			curr = curr->getLeft();
		}
		else{
			curr = curr->getRight();
		}
		cond ? verdadero : falso
*/
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	return false;
}


void BST::add(int data){
	NodeT *curr = root;
	NodeT *father = nullptr;
	while (curr != nullptr){
		if (curr->getData() == data){
			return;
		}
		father = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();		
	}
	if (father == nullptr){
		root = new NodeT(data);
	}
	else{
		if (father->getData() > data){
			father->setLeft(new NodeT(data));
		}
		else{
			father->setRight(new NodeT(data));
		}
	}
}

void BST::remove(int data){
	NodeT *curr = root;
	NodeT *father = nullptr;
	while (curr != nullptr && curr->getData() != data){
		father = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();	 
	}
	if (curr == nullptr){
		return;
	}
	int cantHijos = howManyChildren(curr);
	switch (cantHijos){
		case 0: if (father == nullptr){
					root = nullptr;
				}
				else {
					if (father->getData() > data){
						father->setLeft(nullptr);
					}
					else{
						father->setRight(nullptr);
					}
				}
				delete curr;
				break;
		case 1: if (father == nullptr){
					if (curr->getLeft() != nullptr){
						root = curr->getLeft();
					}
					else{
						root = curr->getRight();
					}
				}
				else {
					if (father->getData() > data){
						if (curr->getLeft() != nullptr){
							father->setLeft(curr->getLeft());
						}
						else{
							father->setLeft(curr->getRight());
						}
					}
					else {
						if (curr->getLeft() != nullptr){
							father->setRight(curr->getLeft());
						}
						else{
							father->setRight(curr->getRight());
						}
					}
				}
				delete curr;
				break;
		case 2: int sucesor = succ(curr);
				remove(sucesor);
				curr->setData(sucesor);
				break;
	}
}

#endif