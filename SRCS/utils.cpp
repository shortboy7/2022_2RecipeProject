#include "../HEADERS/utils.h"
using namespace std;

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

int	getTime(const std::string& line) {
	int i = 0,idx = 0, sum = 0;
	while(line[idx] == ' ') idx++;
	for (i = idx; i < line.size(); i++) {
		if (line.compare(i, 2, "분") == 0)
			break;
		else if (line.compare(i, 4, "시간") == 0) {
			sum *= 60;
			if (line.compare(i + 4, 4, "이상") == 0)
				sum += 1;
			break;
		}
		if ('0' <= line[i] && line[i] <= '9') {
			sum = 10 * sum + (line[i] - '0');
		}
	}
	return sum;
}

int getLevel(const std::string& line) {
	if (line.compare(0, 4, "초급") == 0) {
		return 1;
	}else if (line.compare(0, 4, "중급") == 0) {
		return 2;
	}else if (line.compare(0, 4, "고급") == 0) {
		return 3;
	}else if (line.compare(0, 6, "아무나") == 0) {
		return 0;
	}
	cout << "등급 오류\n";
	return -1;
}