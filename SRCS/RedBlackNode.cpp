#include "../HEADERS/RedBlackNode.h"

extern RedBlackNode *Tnil;

RedBlackNode::RedBlackNode() {
	color = 'B';
	parent = Tnil;
	leftChild = Tnil;
	rightChild = Tnil;
}

RedBlackNode::RedBlackNode(Ingredient data_) {
	data = data_;
	color = 'R';
	parent = Tnil;
	leftChild = Tnil;
	rightChild = Tnil;
}

void	RedBlackNode::swapColor(RedBlackNode * oth){
	char temp = this->color;
	this->color = oth->color;
	oth->color = temp;
}


RedBlackNode * RedBlackNode::sibling() {
	switch(whichChild()) {
		case 'L':
			return parent->rightChild;
		case 'R':
			return parent->leftChild;
		case 'E':
			return Tnil;
	}
	return Tnil;
}

RedBlackNode * RedBlackNode::cousin() {
	if (parent == Tnil) return Tnil;
	return parent->sibling();
}

char	RedBlackNode::whichChild() {
	if (parent == Tnil) return 'E';
	if (parent->leftChild == this) return 'L';
	else return 'R';
}

bool	RedBlackNode::isTnil() {
	return (this == Tnil);
}
