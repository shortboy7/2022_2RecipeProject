#include "../HEADERS/Arraymain.h"
#include "../HEADERS/RecipeArray.h"
using namespace std;

RedBlackNode *Tnil = nullptr;

int main(int argc, char *argv[]){
	string path = "";
	if (argc == 1) {
		path = "DATA/myIngred.csv";
	}else {
		path = argv[1];
	}
	setlocale(LC_ALL, "ko_KR.EUC-KR");
	Timer timer;
	RecipeArray<Recipe> arr(50004);
	RecipeArray<Recipe> canMakeBook(50004);
	Ingredient *myIngred = new Ingredient[500];
	int ingredSize = 0;
	arr.read();
	ifstream fin(path);
	if (fin.is_open()) {
		string input;
		while(!fin.eof()) {
			getline(fin, input);
			int i;
			for (i = input.size() - 1; i >= 0; i--) {
				if (input[i] == ' ') break ;
			}
			myIngred[ingredSize].name = input.substr(0, i);
			myIngred[ingredSize].quantity = input.substr(i + 1, input.size() - i);
			ingredSize++;
		}
		fin.close();
	}
	cout << path << "\n";
	timer.start();
	for (int i = 0 ; i < arr.curSize ; i++) {
		if (arr[i].canMake(myIngred, ingredSize)){
			canMakeBook.push_back(arr[i]);
		}
	}
	timer.end("vector");
	Service<Recipe> service(canMakeBook);
	service.run();
	// cout << canMakeBook.curSize << "\n";
	delete myIngred;
	return 0;
}