#include "../HEADERS/Recipe.h"

Recipe::Recipe(
	int id_,
	std::string name_,
	std::string category_,
	std::string amount,
	std::string	level_,
	std::string time_) {
	id = id_;
	name = name_;
	category = category_;
	level = level_;
	time = time_;
}

void	Recipe::pushIngredient(std::string & token) {
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
	mtrl[ingredientNum].name = aft;
	mtrl[ingredientNum].quantity = qua;
	ingredientNum++;
}