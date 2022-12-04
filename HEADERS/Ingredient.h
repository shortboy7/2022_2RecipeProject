#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <string>
#include <iostream>
#include <fstream>
class Ingredient{
public:
	std::string	name;
	std::string	quantity;
	Ingredient(
		std::string name_,
		std::string quant) {
		name = name_;
		quantity = quant;
	}
	Ingredient(){
		name = "";
		quantity = "";
	}
	bool	operator<(const Ingredient& rhs);
	bool	operator>(const Ingredient& rhs);
	bool	operator==(const Ingredient & rhs);
	friend std::ostream& operator<<(std::ostream& out, const Ingredient& ingred) {
		out << ingred.name << " : " << ingred.quantity;
		return out;
	}
};
#endif