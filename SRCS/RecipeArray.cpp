#include "RecipeArray.h"
using namespace std;

template class RecipeArray<Recipe>;
template class RecipeArray<RBRecipe>;
template class RecipeArray<HashRecipe>;

template <typename T>
void RecipeArray<T>::read() {
	ifstream fin("DATA/recipe_DB.csv");
	// ofstream fout("DATA/result.csv");
	if (fin.is_open()) {
		while (!fin.eof()) {
			T recipe;
			string line;
			getline(fin, line);
			// cout << line <<"\n";
			if (line.substr(0, 2) == "NO")
				continue;
			removeBracket(line);
			int idx = 0;
			int column = 1;
			while (column <= 6) {
				parseLineOther(line, recipe, idx, column);
				if (idx == 0) break;
			}
			if (idx == 0) break;
			parseMtrl(line, recipe, idx, column);
			recipes[this->curSize++] = recipe;
			// fout << recipe;
		}
		// cout << this->curSize << "\n";
		fin.close();
		// fout.close();
	}
}

template <typename T>
void	RecipeArray<T>::push_back(T& recipe){
	recipes[curSize++] = recipe;
}