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
	bool			canMake(Ingredient *myIngred, int size);
	friend std::ostream& operator<<(std::ostream& out, const Recipe& recipe) {
		out << "�丮 �̸� : " << recipe.name << " "
		<< "�丮 ��� : ";
		for (int i = 0; i < recipe.ingredientNum ; i++) {
			out << recipe.mtrl[i].name << " : ";
			out << recipe.mtrl[i].quantity;
			if (i != recipe.ingredientNum - 1)
				out << ",";
		}
		out << "\n";
		return out;
	}
	friend std::ofstream& operator<<(std::ofstream& out, const Recipe& recipe) {
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
