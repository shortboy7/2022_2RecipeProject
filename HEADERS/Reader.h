#ifndef READER_H
#define READER_H
#include "RBRecipe.h"
#include "HashRecipe.h"
#include "utils.h"
#include <vector>

void	parseLineOther(const std::string& line, Recipe& recipe, int& idx, int& column);
void	parseMtrl(const std::string& line, Recipe& recipe, int& idx, int& column);


#endif