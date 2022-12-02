#include "../HEADERS/RBmain.h"
using namespace std;

RedBlackNode * Tnil = new RedBlackNode();

int main(){
	setlocale(LC_ALL, "ko_KR.EUC-KR");
	vector<RBRecipe> book;
	vector<RBRecipe> canMakeRecipe;
	RedBlackTree ingred;
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
			ingred.insert(Ingredient( input.substr(0, i), input.substr(i + 1, input.size() - i)));
		}
		cout << "\n";
		fin.close();
	}
	for (auto & page : book) {
		if (page.canMake(ingred)) {
			cout << page << "\n";
		}
	}

	// do{
	// 	cin >> cmd;
	// 	switch(cmd) {
	// 		case 's':

	// 	}
	// }while (cmd != 'q' || cmd != 'Q');
	return 0;
}
