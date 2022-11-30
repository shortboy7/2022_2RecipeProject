#include "../HEADERS/RedBlackTree.h"

using namespace std;

extern RedBlackNode *Tnil;

RedBlackTree::RedBlackTree() {
	root = Tnil;
}

RedBlackTree::~RedBlackTree() {
	deleteRecursive(root);
	root = Tnil;
}

void	RedBlackTree::deleteRecursive(RedBlackNode * node){
	if (node != Tnil) return ;
	deleteRecursive(node->leftChild);
	deleteRecursive(node->rightChild);
	delete node;
}

void	RedBlackTree::rotate(RedBlackNode * node) {
	RedBlackNode *temp = node->parent;
	switch(node->parent->whichChild()) {
		case 'L':
			if (node->whichChild() == 'R')
			{
				rotateLeft(node->parent);
				node = temp;
			}
			node->parent->swapColor(node->parent->parent);
			rotateRight(node->parent->parent);
			break;
		case 'R':
			if (node->whichChild() == 'L'){
				rotateRight(node->parent);
				node = temp;
			}
			node->parent->swapColor(node->parent->parent);
			rotateLeft(node->parent->parent);
			break;
		case 'E':
			break ;
	}
}

void	RedBlackTree::fixUpTree(RedBlackNode * newNode) {
	if (newNode->parent->isTnil()) return;
	if (newNode->parent->color == 'B') return ;
	if (newNode->cousin()->color == 'R') {
		recolor(newNode);
	}
	else {
		rotate(newNode);
	}
	// cout << newNode->data.name << ":::" << newNode->data.quantity << "\n";
	if (newNode->parent != Tnil && newNode->parent->parent != Tnil)
		fixUpTree(newNode->parent->parent);
	root->color = 'B';
}

void	RedBlackTree::recolor(RedBlackNode * node) {
	if (node->parent != Tnil)
		node->parent->color = 'B';
	if (node->cousin() != Tnil)
		node->cousin()->color = 'B';
	if (node->parent != Tnil &&
		node->parent->parent != Tnil)
	node->parent->parent->color = 'R';
}

void	RedBlackTree::rotateRight(RedBlackNode * node) {
	RedBlackNode * y = node->leftChild;
	node->leftChild = y->rightChild;
	if (y->rightChild != Tnil) y->rightChild->parent = node;
	y->parent = node->parent;
	switch(node->whichChild()) {
		case 'E':
			root = y;
			break ;
		case 'L':
			node->parent->leftChild = y;
			break;
		case 'R':
			node->parent->rightChild = y;
			break;
	}
	y->rightChild = node;
	node->parent = y;
}

void	RedBlackTree::rotateLeft(RedBlackNode * node) {
	RedBlackNode * y = node->rightChild;
	node->rightChild = y->leftChild;
	if (y->leftChild != Tnil) y->leftChild->parent = node;
	y->parent = node->parent;
	switch(node->whichChild()) {
		case 'E':
			root = y;
			break ;
		case 'L':
			node->parent->leftChild = y;
			break;
		case 'R':
			node->parent->rightChild = y;
			break;
	}
	y->leftChild = node;
	node->parent = y;
}

RedBlackNode* RedBlackTree::search(Ingredient data){
	RedBlackNode * node = root;
	while (!node->isTnil()) {
		if (node->data > data) {
			node = node->leftChild;
		}else if (node->data < data) {
			node = node->rightChild;
		}else return node;
	}
	return node;
}

RedBlackNode *RedBlackTree::search(std::string data) {
	RedBlackNode * node = root;
	while (!node->isTnil()) {
		if (node->data.name > data) {
			node = node->leftChild;
		}else if (node->data.name < data) {
			node = node->rightChild;
		}else return node;
	}
	return node;
}

void	RedBlackTree::insert(Ingredient data) {
	RedBlackNode * newNode = new RedBlackNode(data);
	RedBlackNode * temp = root;
	if (root->isTnil()) {
		cout << "root is empty\n";
		root = newNode;
		root->color = 'B';
		return;
	}else {
		while (!temp->isTnil()) {
			if (temp->data < data) {
				if (!temp->rightChild->isTnil()) {
					temp = temp->rightChild;
				}else {
					temp->rightChild = newNode;
					newNode->parent = temp;
					break;
				}
			}
			else if (temp->data > data) {
				if (!temp->leftChild->isTnil()) {
					temp = temp->leftChild;
				}else {
					temp->leftChild = newNode;
					newNode->parent = temp;
					break;
				}
			}
			else {
				delete newNode;
				return;
			}
		}
	}
	fixUpTree(newNode);
}

void	RedBlackTree::printRecur(std::ostream& out , RedBlackNode * root) const{
	if (root->isTnil()){
		return ;
	}
	printRecur(out, root->leftChild);
	out << root->data << "&";
	printRecur(out, root->rightChild);
}

void	RedBlackTree::print(std::ostream& out) const{
	printRecur(out, root);
}
