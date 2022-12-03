#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <fstream>
#include <vector>
#include "RedBlackNode.h"

int	getDigits(int num);

class RedBlackTree{
private:
	RedBlackNode	*root;
	void	rotateLeft(RedBlackNode * node);
	void	rotateRight(RedBlackNode * node);
	void	recolor(RedBlackNode * node);
	void	rotate(RedBlackNode * node);
	void	fixUpTree(RedBlackNode * newNode);
	void	printRecur(std::ostream& out , RedBlackNode * node) const;
	bool	traverseRecur(RedBlackNode * node, RedBlackTree& myIngred);
public:
	static int nodeNum;
	RedBlackTree();
	RedBlackNode *search(Ingredient data);
	RedBlackNode *search(std::string data);
	void	insert(Ingredient data);
	void	deleteRecursive(RedBlackNode * node);
	void	print(std::ostream& out) const;
	bool	traverse(RedBlackTree& myIngred);
	~RedBlackTree();
};


#endif
