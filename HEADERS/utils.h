#ifndef UNTILS_H
#define UNTILS_H
#include <string>

void skipBracket(const std::string& line, int& idx, char bracket = '[');
void removeBracket(std::string& line, char bracket = '(');

#endif