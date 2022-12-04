#include "../HEADERS/Reader.h"
using namespace std;

void	parseLineOther(const string& line, Recipe& recipe, int& idx, int& column) {
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
			recipe.amount = getAmount(token);
			break;
		case 5:
			recipe.level = getLevel(token);
			break;
		case 6:
			recipe.time = getTime(token);
			break;
	}
	idx++;
	column++;
}

void	parseMtrl(const string& line, Recipe& recipe, int& idx, int& column) {
	while (line[idx]){
		string token = "";
		skipBracket(line, idx);
		while (line[idx] == ' ') idx++;
		while (line[idx] && line[idx] != '|' && line[idx] != '[') {
			token += line[idx];
			idx++;
		}
		skipBracket(line, idx);
		if (!token.empty()){
			if (token[token.size() - 1] == ' ') token.pop_back();
			recipe.pushIngredient(token);
		}
		if(line[idx]) idx++;
	}
}

void read(vector<RBRecipe>& recipes){
	ifstream fin("DATA/recipe_DB.csv");
	ofstream fout("DATA/result.csv");
	if (fin.is_open() && fout.is_open()) {
		while (!fin.eof()) {
			RBRecipe recipe;
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
			recipes.push_back(recipe);
			fout << recipe;
		}
		cout << recipes.size() << "\n";
		fin.close();
		fout.close();
	}
}

void	read(vector<HashRecipe>& recipes) {
	ifstream fin("DATA/recipe_DB.csv");
	ofstream fout("DATA/result_hash.csv");
	if (fin.is_open() && fout.is_open()) {
		while (!fin.eof()) {
			HashRecipe recipe;
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
			recipes.push_back(recipe);
			fout << recipe;
			// fout << recipe;
		}
		cout << recipes.size() << "\n";
		fin.close();
		fout.close();
	}
}

void	read(Recipe* recipes, int& curSize) {
	ifstream fin("DATA/recipe_DB.csv");
	ofstream fout("DATA/result_array.csv");
	cout << "read\n";
	if (fin.is_open() && fout.is_open()) {
		while (!fin.eof()) {
			Recipe recipe;
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
			recipes[curSize++] = recipe;
			fout << recipe;
			// fout << recipe;
		}
		cout << curSize << "\n";
		fin.close();
		fout.close();
	}
}