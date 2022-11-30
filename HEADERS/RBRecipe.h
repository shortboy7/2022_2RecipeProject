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
	void	print();
	friend std::ostream& operator<<(std::ofstream& out, const RBRecipe& recipe) {
		out << recipe.id << ","
		<< recipe.name << ","
		<< recipe.category << ","
		<< recipe.level << ","
		<< recipe.time << ",";
		recipe.tree.print(out);
		// for (int i = 0; i < recipe.ingredientNum ; i++) {

		// 	out << recipe.mtrl[i].name;
		// 	out << ":" << recipe.mtrl[i].quantity;
		// 	if (i != recipe.ingredientNum - 1)
		// 		out << "|";
		// }
		out << "\n";
		return out;
	}
};

#endif