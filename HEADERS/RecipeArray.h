#ifndef RECIPEARRAY_H
#define RECIPEARRAY_H
#include "Recipe.h"
#include "Reader.h"
#include <fstream>

template <typename T>
class RecipeArray{
private:
public:
	int maxSize;
	int curSize;
	T *recipes;
	RecipeArray(int size) {
		maxSize = size;
		curSize = 0;
		recipes = new T[maxSize];
	}
	void read();
	void	push_back(T& recipe);
	~RecipeArray(){
		delete [] recipes;
	}
	T& operator[](int idx) {
		return recipes[idx];
	}
};
#endif