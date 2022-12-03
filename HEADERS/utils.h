#ifndef UNTILS_H
#define UNTILS_H
#include <string>
#include <iostream>

void	skipBracket(const std::string& line, int& idx, char bracket = '[');
void	removeBracket(std::string& line, char bracket = '(');
int		getTime(const std::string& line);
int		getLevel(const std::string& line);
int		getAmount(const std::string& line);

#endif