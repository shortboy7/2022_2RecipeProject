#include "../HEADERS/main.h"
using namespace std;

RedBlackNode * Tnil = new RedBlackNode();

int main(){
	setlocale(LC_ALL, "ko_KR.EUC-KR");
	vector<RBRecipe> vec;
	read(vec);
	return 0;
}

/*
set LANG=ko_KR.UTF-8
set LC_CTYPE="ko_KR.UTF-8"
set LC_NUMERIC="ko_KR.UTF-8"
set LC_TIME="ko_KR.UTF-8"
set LC_COLLATE="ko_KR.UTF-8"
set LC_MONETARY="ko_KR.UTF-8"
set LC_MESSAGES="ko_KR.UTF-8"
set LC_ALL=

set LANG=C
set LC_CTYPE="C"
set LC_NUMERIC="C"
set LC_TIME="C"
set LC_COLLATE="C"
set LC_MONETARY="C"
set LC_MESSAGES="C"
set LC_ALL=

*/
