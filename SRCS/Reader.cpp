#include "../HEADERS/Reader.h"
using namespace std;

static void	parseLineOther(const string& line, Recipe& recipe, int& idx, int& column) {
	string token = "";
	while (line[idx] && line[idx] != ',') {
		token += line[idx];
		idx++;
	}
	if (idx == 0) return ;
	switch(column) {
		case 1:
			recipe.id = token;
			break;
		case 2:
			recipe.name = token;
			break;
		case 3:
			recipe.category = token;
			break;
		case 4:
			recipe.amount = token;
			break;
		case 5:
			recipe.level = token;
			break;
		case 6:
			recipe.time = token;
			break;
	}
	idx++;
	column++;
}

static void	parseMtrl(const string& line, Recipe& recipe, int& idx, int& column) {
	while (line[idx]){
		string token = "";
		skipBracket(line, idx);
		if (line[idx] == ' ') idx++;
		while (line[idx] && line[idx] != '|' && line[idx] != '[') {
			token += line[idx];
			idx++;
		}
		skipBracket(line, idx);
		// if (line[idx] == ' ') idx++;
		if (!token.empty()){
			if (token[token.size() - 1] == ' ') token.pop_back();
			recipe.pushIngredient(token);
		}
		if(line[idx]) idx++;
	}
}

void read(vector<RBRecipe>& recipes){
	ifstream fin("DATA/recipe_DB.csv");
	// ofstream fout("recipe_()_rm2.csv");
	ofstream fout("DATA/result.csv");
	// vector<Recipe> recipes;
	if (fin.is_open() && fout.is_open()) {
		while (!fin.eof()) {
			RBRecipe recipe;
			string line;
			getline(fin, line);
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
			fout << recipe;
			recipes.push_back(recipe);
		}
		cout << recipes.size() << "\n";
		fin.close();
		fout.close();
	}
}
