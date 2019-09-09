/*
Helen Li
November 16, 2018
Homework #17 - RBT
*/

#include <iostream>
#include <ctime>

using namespace std;

//every node is either red or black
//the root is always black
//there are no two adjacent red nodes
//every path from node to descendents null node has same num of black nodes
//if a node is red, all its children are black
//num of black nodes must be same in all paths from root to null nodes

//must check colors

template <class T>
class RBT;

template <class T>
T& max(T& left, T& right){
	if (left > right)
		return left;
	else
		return right;

}
template <class T>
T max(const T& left, const T& right){
	if (left > right)
		return left;
	else
		return right;

}

template <class T>
class RBTNode{
	RBTNode<T>* parent, *left, *right;
	int height;
	bool color;
	T data;
public:
	friend class RBT < T >;
	RBTNode(const T& newdata = T(), RBTNode<T>* newparent = nullptr, RBTNode<T>* newleft = nullptr, RBTNode<T>* newright = nullptr) :
		data(newdata), parent(newparent), left(newleft), right(newright) { calcHeight(); }
	void calcHeight(){
		int leftHeight = -1;
		int rightHeight = -1;
		if (left != nullptr)
			leftHeight = left->height + 1;
		if (right != nullptr)
			rightHeight = right->height + 1;
		height = max(leftHeight, rightHeight) + 1;
	}
		void printInOrder()const{
		if (left != nullptr)
			left->printInOrder();
		cout << data << endl;
		if (right != nullptr)
			right->printInOrder();
	}
	int size()const{
		int leftSize = 0;
		int rightSize = 0;
		if (left != nullptr)
			leftSize = left->size();
		if (right != nullptr)
			rightSize = right->size();
		return 1 + leftSize + rightSize;
	}
/*	int height()const{
		int leftSize = -1;
		int rightSize = -1;
		if (left != nullptr)
			leftSize = left->height();
		if (right != nullptr)
			rightSize = right->height();
		return 1 + max(leftSize, rightSize);
	}*/
	int depth() const{
		int parentDepth = -1;
		if (parent != nullptr)
			parentDepth = parent->depth();
		return 1 + parentDepth;
	}
};

template <class T>
class RBT{
	RBTNode<T>* root;
	int size;
	RBTNode<T>* recursiveCopy(RBTNode<T>* toCopy);
	void singleCCR(RBTNode<T>*& point);
	void doubleCR(RBTNode<T>*& point);
	void singleCR(RBTNode<T>*& point);
	void doubleCCR(RBTNode<T>*& point);
	int heightDiff(RBTNode<T>* point);
	void doRotation(RBTNode<T>* point);
public:
	RBT() :size(0){ root = nullptr; }

	RBT(const RBT<T>& rhs) :root(nullptr){ *this = rhs; }
	virtual ~RBT(){ clear(); }
	RBT& operator=(const RBT<T>& rhs);

	bool isInTree(const T& toFind) const{ return find(toFind) != nullptr; }
	bool isEmpty()const{ return root == nullptr; }
	int getSize()const { return size; }
	void remove(const T& toRemove){
		RBTNode<T>* item = find(toRemove);
		if (item != nullptr)
			remove(item);
	}
	void insert(const T&);
	void remove(RBTNode<T>*);
	RBTNode<T>* find(const T& toFind) const;
	void clear(){ while (!isEmpty()) remove(root); }
	void printInOrder()const{ root->printInOrder(); }
};
template <class T>
void RBT<T>::doubleCCR(RBTNode<T>*& point){
	singleCR(point->right);
	singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T>*& point){
	singleCCR(point->left);
	singleCR(point);
}

//need to check the colors and update if necessary
template <class T>
void RBT<T>::singleCR(RBTNode<T>*& point){
	RBTNode<T>* grandparent = point;
	RBTNode<T>* parent = point->left;
	parent->parent = grandparent->parent;
	grandparent->parent = parent; 
	grandparent->left = parent->right;
	parent->right = grandparent;

	if (grandparent->left != nullptr) //if we now have a left child, update its parent pointer
		grandparent->left->parent = grandparent;
	if (parent->parent == nullptr)//if we were the root, update the root!
		root = parent;
	else if (parent->parent->left == grandparent)
		parent->parent->left = parent;
	else
		parent->parent->right = parent;
	grandparent->calcHeight();
	parent->calcHeight();
}

//need to check the colors and update if necessary
template <class T>
void RBT<T>::singleCCR(RBTNode<T>*& point){
	RBTNode<T>* grandparent = point;
	RBTNode<T>* parent = point->right;
	parent->parent = grandparent->parent;
	grandparent->parent = parent;
	grandparent->right = parent->left;
	parent->left = grandparent;

	if (grandparent->right != nullptr) //if we now have a right child, update its parent pointer
		grandparent->right->parent = grandparent;
	if (parent->parent == nullptr)//if we were the root, update the root!
		root = parent;
	else if (parent->parent->right == grandparent)
		parent->parent->right = parent;
	else
		parent->parent->left = parent;
	grandparent->calcHeight();
	parent->calcHeight();
}


template <class T>
RBTNode<T>* RBT<T>::recursiveCopy(RBTNode<T>* toCopy){
	if (toCopy == nullptr)
		return nullptr;
	RBTNode<T>* temp = new RBTNode<T>(toCopy->data, nullptr, recursiveCopy(toCopy->left), recursiveCopy(toCopy->right));
	if (temp->left != nullptr)
		temp->left->parent = temp;
	if (temp->right != nullptr)
		temp->right->parent = temp;
	return temp;
}

template <class T>
RBT<T>& RBT<T>::operator=(const RBT<T>& rhs){
	if (this == &rhs)
		return *this;
	clear();
	root = recursiveCopy(rhs.root);
	size = rhs.size;
	return *this;
}

template <class T>
void RBT<T>::remove(RBTNode<T>* toRemove){
	if (root == nullptr)
		return; //Remove from an empty tree?
	if (toRemove->left == nullptr && toRemove->right == nullptr){ //leaf node case
		if (toRemove->parent == nullptr){
			root = nullptr;
		}
		else if (toRemove == toRemove->parent->left) //left child!
			toRemove->parent->left = nullptr; //fix the parent's pointer!
		else
			toRemove->parent->right = nullptr;
		delete toRemove;
		size--;
	}
	else if (toRemove->right == nullptr){ //has one (left) child
		if (toRemove->parent == nullptr){
			root = toRemove->left;
			root->parent = nullptr;
		}
		else if (toRemove == toRemove->parent->left){ //we're the left child of our parent
			toRemove->parent->left = toRemove->left;
			toRemove->left->parent = toRemove->parent;
		}
		else{
			toRemove->parent->right = toRemove->left;
			toRemove->left->parent = toRemove->parent;
		}
		delete toRemove;
		size--;
	}
	else if (toRemove->left == nullptr){ //has one right child, almost same solution as left child only
		if (toRemove->parent == nullptr){
			root = toRemove->right;
			root->parent = nullptr;
		}
		else if (toRemove == toRemove->parent->left){ //we're the left child of our parent
			toRemove->parent->left = toRemove->right;
			toRemove->right->parent = toRemove->parent;
		}
		else{
			toRemove->parent->right = toRemove->right;
			toRemove->right->parent = toRemove->parent;
		}
		delete toRemove;
		size--;
	}
	else{ //two children
		RBTNode<T>* temp = toRemove->right;
		while (temp->left != nullptr)
			temp = temp->left;
		toRemove->data = temp->data;
		remove(temp);
	}

}

template <class T>
RBTNode<T>* RBT<T>::find(const T& toFind) const{
	RBTNode<T>* temp = root;
	while (temp != nullptr && temp->data != toFind){
		if (toFind < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

//need to check the colors and update if necessary
template <class T>
void RBT<T>::insert(const T& toInsert){
	size++;
	if (root == nullptr){
		root = new RBTNode<T>(toInsert);
	}
	else{
		RBTNode<T>* temp = root;
		RBTNode<T>* prev = nullptr;
		while (temp != nullptr){
			prev = temp;
			if (toInsert < temp->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
		

		if (toInsert < prev->data){ 
			prev->left = new RBTNode<T>(toInsert, prev);
		}
		else
			prev->right = new RBTNode<T>(toInsert, prev);

		if(prev != nullptr){
			prev->calcHeight();
			if (heightDiff(prev)>1)
				doRotation(prev);
		}
	}
}

//nned to check colors after rotation
template <class T>
void RBT<T>::doRotation(RBTNode<T>* point){
	int leftChild = -1;
	int rightChild = -1;
	if (point->left != nullptr)
		leftChild = point->left->height;
	if (point->right != nullptr)
		rightChild = point->right->height;

	if (leftChild > rightChild){//CR, but is it single or double?
		int leftGC = -1;
		int rightGC = -1;
		if (point->left->left != nullptr)
			leftGC = point->left->left->height;
		if (point->left->right != nullptr)
			rightGC = point->left->right->height;
		if (leftGC > rightGC) // single rotation
			singleCR(point);
		else
			doubleCR(point);
	}
	else{//definitely a CCR, but which one?
		int leftGC = -1;
		int rightGC = -1;
		if (point->right->left != nullptr)
			leftGC = point->right->left->height;
		if (point->right->right != nullptr)
			rightGC = point->right->right->height;
		if (leftGC > rightGC) // double rotation
			doubleCCR(point);
		else
			singleCR(point);
	}
}


template<class T>
int RBT<T>::heightDiff(RBTNode<T>* point){
	int leftHeight = -1;
	int rightHeight = -1;
	if (point->left != nullptr)
		leftHeight = point->left->height;
	if (point->right != nullptr)
		rightHeight = point->right->height;
	return (abs(leftHeight - rightHeight));
}


int main(){
	{
		
		RBT<int> b;
		srand(time(NULL));
		for (int i = 0; i < 100; i++)
			b.insert(rand() % 1000);

		b.printInOrder();
		cout << "Got here!" << endl;
	}
	cout << "Got here #2" << endl;
}
