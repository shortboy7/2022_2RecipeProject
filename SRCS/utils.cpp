#include "../HEADERS/utils.h"

static char opBracket(char b) {
	switch(b) {
		case '(':
			return ')';
		case '[':
			return ']';
		case '<':
			return '>';
		case '{':
			return '}';
	}
	return 0;
}

void removeBracket(std::string& line, char bracket) {
	int edge[100][2], cursor = 0, i;
	for (i = 0; i < line.size(); i++){
		if (line[i] == bracket) {
			edge[cursor][0] = i;
			while (line[i] && line[i] != opBracket(bracket)) {
				i++;
			}
			edge[cursor][1] = i;
			cursor++;
		}
		if (!line[i]) {
			break;
		}
	}
	while (cursor > 0) {
		cursor--;
		line.erase(edge[cursor][0], edge[cursor][1] - edge[cursor][0] + 1);
	}
}

void skipBracket(const std::string& line, int& idx, char bracket)
{
	if (line[idx] == bracket) {
		while (line[idx] && line[idx] != opBracket(bracket)) idx++;
		idx++;
	}
}
