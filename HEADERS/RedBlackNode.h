#ifndef REDBLACKNODE_H
#define REDBLACKNODE_H
#include "Ingredient.h"

class RedBlackNode{
private:
	char color;
public:
	Ingredient data;
	RedBlackNode *parent;
	RedBlackNode *leftChild;
	RedBlackNode *rightChild;
	RedBlackNode();
	RedBlackNode(Ingredient data_);
	bool	isTnil();
	char	whichChild();
	RedBlackNode *sibling();
	RedBlackNode *cousin();
	void	swapColor(RedBlackNode * oth);
	friend class RedBlackTree;
};

#endif