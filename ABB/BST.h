#ifndef BST_h
#define BST_h
#include "NodeT.h"
#include <iostream>

using namespace std;

class BST{
	public:
		BST();
		~BST();
		bool search(int data);
		void add(int data);
		void remove(int data);
		void print(int tipo);// tipo 1 = preorden // tipo 2 = inorden // tipo 3 = postorden;
	private:
		NodeT *root;
		int howManyChildren(NodeT *r);
		int succ(NodeT *r);
		int pred(NodeT *r);
		void preorden(NodeT *r);
		void inorden(NodeT *r);
		void postorden(NodeT *r);
		void destruye(NodeT *r);
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

void BST::preorden(NodeT *r){
	if (r != nullptr){
		cout << r->getData() << " " ;
		preorden(r->getLeft());
		preorden(r->getRight());
	}
}

void BST::inorden(NodeT *r){
	if (r!=nullptr){
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