#include "../HEADERS/Recipe.h"
using namespace std;

Recipe::Recipe(
	int id_,
	std::string name_,
	std::string category_,
	int	amount,
	int	level_,
	int time_) {
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

bool	Recipe::canMake(Ingredient *myIngred, int size){
	for (int i = 0; i < ingredientNum; i++) {
		bool found = false;
		for (int j = 0 ; j < size; j++) {
			// std::cout << i << " " << j << " compare\n";
			if (mtrl[i].name == myIngred[j].name) {
				found = true;
				break;
			}
		}
		if (!found) return false;
	}
	// cout << name <<"\n";
	return true;
}
