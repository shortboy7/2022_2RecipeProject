// #include "RedBlackTree.h"
#ifndef RECIPE_H
#define RECIPE_H
#include "Ingredient.h"
#include <fstream>

class Recipe{
private:
public:
	int ingredientNum = 0;
	std::string id;
	std::string name;
	std::string category;
	int	amount;
	int	level;
	int time;
	Ingredient mtrl[100];
	Recipe() {}
	Recipe(
		int id_,
		std::string name_,
		std::string category_,
		int	amount,
		int	level_,
		int time_
	);
	virtual void	pushIngredient(std::string & token);
	friend std::ostream& operator<<(std::ostream& out, const Recipe& recipe) {
		out << "요리 번호 : " << recipe.id << " "
		<< "요리 이름 : " << recipe.name << " "
		<< "요리 분류 : " << recipe.category << "\n"
		<< "요리 수준 : " << recipe.level << " "
		<< "요리 시간 : " << recipe.time << "\n"
		<< "요리 재료 : \n";
		for (int i = 0; i < recipe.ingredientNum ; i++) {
			out << recipe.mtrl[i].name << " : ";
			out << recipe.mtrl[i].quantity;
			if (i != recipe.ingredientNum - 1)
				out << ",";
		}
		return out;
	}
	friend std::ostream& operator<<(std::ofstream& out, const Recipe& recipe) {
		out << recipe.id << ","
		<< recipe.name << ","
		<< recipe.category << ","
		<< recipe.amount << ","
		<< recipe.level << ","
		<< recipe.time << ",";
		for (int i = 0; i < recipe.ingredientNum ; i++) {
			out << recipe.mtrl[i].name;
			out << ":" << recipe.mtrl[i].quantity;
			if (i != recipe.ingredientNum - 1)
				out << "|";
		}
		out << "\n";
		return out;
	}
};
#endif
