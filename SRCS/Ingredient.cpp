#include "../HEADERS/Ingredient.h"

bool	Ingredient::operator<(const Ingredient& rhs) {
	if (name < rhs.name) return true;
	else return false;
}
bool	Ingredient::operator>(const Ingredient& rhs) {
	if (name > rhs.name) return true;
	else return false;
}
bool	Ingredient::operator==(const Ingredient & rhs) {
	if (name == rhs.name) return true;
	else return false;
}