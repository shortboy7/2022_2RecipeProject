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