#include "../HEADERS/Hashmain.h"
using namespace std;

RedBlackNode *Tnil = nullptr;

int main(int argc, char *argv[]){
	string path = "";
	if (argc == 1) {
		path = "DATA/myIngred.csv";
	}else {
		path = argv[1];
	}
	Timer timer;
	setlocale(LC_ALL, "ko_KR.EUC-KR");
	RecipeArray<HashRecipe> book(50004);
	book.read();
	RecipeArray<HashRecipe> canMakeRecipe1(50004);
	RecipeArray<HashRecipe> canMakeRecipe2(50004);
	HashRecipe ingred;
	int ingredNum = 0;
	ifstream fin(path);
	if (fin.is_open()) {
		string input;
		while(!fin.eof()) {
			getline(fin, input);
			int i;
			for (i = input.size() - 1; i >= 0; i--) {
				if (input[i] == ' ') break ;
			}
			ingred.PlusIngredient(input.substr(0, i), input.substr(i + 1, input.size() - i));
			ingredNum++;
		}
		fin.close();
	}
	timer.start();
	for (int i = 0 ; i < book.curSize ; i++)
	{
		if (book[i].canMakeVec(ingred))
		{
			canMakeRecipe1.push_back(book[i]);
			// cout << page << "\n";
		}
	}
	timer.end("vec hash");
	// cout << "1: " << canMakeRecipe1.curSize<< "\n";
	// timer_hash_v.end("Hashtable vec");
	// Timer timer_tree;
	timer.start();
	for (int i = 0 ; i < book.curSize ; i++)
	{
		if (book[i].canMakeHash(ingred))
		{
			canMakeRecipe2.push_back(book[i]);
			// cout << page  "\n";
		}
	}
	timer.end("hash hash");
	Service<HashRecipe> service(canMakeRecipe1);
	service.run();
	// timer_tree.end("Hashtable Hashtable");

	// cout << "2: " << canMakeRecipe2.curSize << "\n";
	return 0;
}