#ifndef RBRECIPE_H
#define RBRECIPE_H
#include "Recipe.h"
#include "RedBlackTree.h"

class RBRecipe : public Recipe{
private:
	RedBlackTree tree;
public:
	RBRecipe() {
		Recipe();
	}
 	void	pushIngredient(std::string & token) override;
	bool	canMake(RedBlackTree& myIngred);
	bool	canMakeVec(RedBlackTree& myIngred);
	bool	canMakeTree(RedBlackTree& myIngred);
	void	print();
	friend std::ofstream& operator<<(std::ofstream& out, const RBRecipe& recipe) {
		out << recipe.id << ","
		<< recipe.name << ","
		<< recipe.category << ","
		<< recipe.amount << ","
		<< recipe.level << ","
		<< recipe.time << ",";
		recipe.tree.print(out);
		out << "\n";
		return out;
	}
};

#endif