#include "../HEADERS/RBRecipe.h"

extern RedBlackNode* Tnil;

void RBRecipe::pushIngredient(std::string & token) {
	if (token.empty()) return ;
	int i;
	for (i = token.size() - 1 ; i >= 0 ; i--) {
		if (token[i] == ' ') break;
	}
	std::string aft = token;
	std::string qua = "0";
	if (token.size() > i && i >= 1)
	{
		aft = token.substr(0, i);
		qua = token.substr(i + 1, token.size() - i);
	}
	tree.insert(Ingredient(aft, qua));
	mtrl[ingredientNum].name = aft;
	mtrl[ingredientNum].quantity = qua;
	ingredientNum++;
}

bool	RBRecipe::canMakeVec(RedBlackTree& myIngred){
	for (int i = 0 ; i < ingredientNum; i++) {
		if (myIngred.search(mtrl[i].name) == Tnil) {
			return false;
		}
	}
	return true;
}

bool	RBRecipe::canMakeTree(RedBlackTree& myIngred) {
	return tree.traverse(myIngred);
}