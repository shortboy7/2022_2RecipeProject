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
	void	print();
	friend std::ostream& operator<<(std::ofstream& out, const RBRecipe& recipe) {
		out << recipe.id << ","
		<< recipe.name << ","
		<< recipe.category << ","
		<< recipe.level << ","
		<< recipe.time << ",";
		recipe.tree.print(out);
		out << "\n";
		return out;
	}
};

#endif