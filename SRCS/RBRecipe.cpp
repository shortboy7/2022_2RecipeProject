#include "../HEADERS/RBRecipe.h"

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
	ingredientNum++;
}