#include "../HEADERS/Hashmain.h"
using namespace std;

RedBlackNode *Tnil = nullptr;

int main(){
	setlocale(LC_ALL, "ko_KR.EUC-KR");
	vector<HashRecipe> book;
	HashNode ingred[1000];
	int ingredNum = 0;
	read(book);
	ifstream fin("DATA/myIngred.csv");
	if (fin.is_open()) {
		string input;
		while(!fin.eof()) {
			getline(fin, input);
			int i;
			for (i = input.size() - 1; i >= 0; i--) {
				if (input[i] == ' ') break ;
			}
			ingred[ingredNum].name = input.substr(0, i);
			ingred[ingredNum].quantity = input.substr(i + 1, input.size() - i);
			ingredNum++;
		}
		cout << "\n";
		fin.close();
	}
	// for (auto & page : book) {
	// 	if (page.canMake(ingred)) {
	// 		cout << page << "\n";
	// 	}
	// }
	return 0;
}