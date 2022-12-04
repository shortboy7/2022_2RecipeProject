#ifndef SERVICE_H
#define SERVICE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "RecipeArray.h"
#include "Reader.h"

template <typename T>
class Service{
	//메뉴 카테고리 기준 필터링 함수
	void menu_class();
	//요리 수준 기준 필터링 함수
	void menu_level();
	//요리 인분 기준 필터링 함수
	void menu_amount();
	//result.csv에서 요리 5개 랜덤으로 추출하는 함수
	void	extract_menu(int cmd, const int& condition);
	void 	extract_menu(int cmd, const std::string& condition);

	void	filterRecipe(RecipeArray<T>& filtered, int col, const std::string& condition);
	void	filterRecipe(RecipeArray<T>& filtered, int col, const int& condition);
	bool	showRandom(RecipeArray<T>& filtered, bool* selected);

private:
	RecipeArray<T>& recipes;
public:
	Service(RecipeArray<T>& book): recipes(book) {}
	void	run();

};
#endif