#include "../HEADERS/RBmain.h"
using namespace std;

RedBlackNode * Tnil = new RedBlackNode();

int main(int argc, char *argv[]){
	string path = "";
	if (argc == 1) {
		path = "DATA/myIngred.csv";
	}else {
		path = argv[1];
	}
	Timer timer;
	setlocale(LC_ALL, "ko_KR.EUC-KR");
	RecipeArray<RBRecipe> arr(50004);
	RecipeArray<RBRecipe> canMakeRecipe(50004);
	RedBlackTree ingred;
	arr.read();
	ifstream fin(path);
	if (fin.is_open()) {
		cout << path << "is opened \n";
		string input;
		while(!fin.eof()) {
			getline(fin, input);
			int i;
			for (i = input.size() - 1; i >= 0; i--) {
				if (input[i] == ' ') break ;
			}
			ingred.insert(Ingredient( input.substr(0, i), input.substr(i + 1, input.size() - i)));
		}
		fin.close();
	}
	cout << argv[1] << "\n";
	timer.start();
	for (int i = 0 ; i < arr.curSize; i++) {
		if (arr.recipes[i].canMakeVec(ingred)) {
			canMakeRecipe.push_back(arr.recipes[i]);
			// cout << page << "\n";
		}
	}
	timer.end("RB tree vec");
	canMakeRecipe.curSize = 0;
	timer.start();
	for (int i = 0 ; i < arr.curSize; i++) {
		if (arr.recipes[i].canMakeTree(ingred)) {
			canMakeRecipe.push_back(arr.recipes[i]);
			// cout << arr.recipes[i] << "\n";
		}
	}
	timer.end("RB tree tree");

	return 0;
}
