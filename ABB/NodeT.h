#ifndef NodeT_h
#define NodeT_h

class NodeT{
	public:
		NodeT(int data);
		NodeT(int data, NodeT *left, NodeT *right);
		int getData();
		void setData(int data);
		NodeT* getLeft();
		void setLeft(NodeT *left);
		NodeT* getRight();
		void setRight(NodeT *right);
	private:
		int data;
		NodeT *left;
		NodeT *right;	
};

NodeT::NodeT(int data){
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

NodeT::NodeT(int data, NodeT *left, NodeT *right){
	this->data = data;
	this->left = left;
	this->right = right;
}

int NodeT::getData(){
	return data;
}

void NodeT::setData(int data){
	this->data = data;
}

NodeT* NodeT::getLeft(){
	return this->left;
}

void NodeT::setLeft(NodeT *left){
	this->left = left;
}

NodeT* NodeT::getRight(){
	return this->right;
}

void NodeT::setRight(NodeT *right){
	this->right = right;
}

#endif