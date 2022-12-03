#include "../HEADERS/RBRecipe.h"

extern RedBlackNode* Tnil;

void RBRecipe::pushIngredient(std::string & token) {
	if (token.empty()) return ;
	int i;
	for (i = token.size() - 1 ; i >= 0 ; i--) {
		if (token[i] == ' ') break;
	}
	std::string aft = token;
	std::string qua = "0";
	if (token.size() > i && i >= 1)
	{
		aft = token.substr(0, i);
		qua = token.substr(i + 1, token.size() - i);
	}
	tree.insert(Ingredient(aft, qua));
	mtrl[ingredientNum].name = aft;
	mtrl[ingredientNum].quantity = qua;
	ingredientNum++;
}

// Recipe : RB 유지 -> tree 순회 (모든 노드들을 확인)
// vector : 0 ~ N -1 포인터 이동 << tree순회 recursive함수 호출 모든 재료들확인 훨씬 느릴거같다.
// Recipe(배열) + 사용자(RB)
// Recipe(RB)  + 사용자(RB)
// Recipe(배열) + 사용자(hash)
// Recipe(hash) + 사용자(hash)

// 0b11110000 (8가지의 상태의 모든 경우를 다 표현)
// 상태를 : 어떤 재료의 보유 유무를 상태로 봄
// 너 사과있어? -> 양파 있어? -> 돼지고기있어? -... 8번 비교할 거를 1번에
// 0b0010000 & 0b11110000 = 0b00100000(다 없구나) !=  (0b11110000) 다 가지고 있구나
/*
	문제점 : 문자열 일치 X 경우 -> 비슷한 단어 추천/포함 (알고리즘) : 그래프(자료구조) -> 유사한 의미를 갖는다고 보는 단어들을 간선으로
	입력받은 단어에서 두글자가 레시피에 등록된 단어 두개랑 같다

*/
bool	RBRecipe::canMakeVec(RedBlackTree& myIngred){
	for (int i = 0 ; i < ingredientNum; i++) {
		if (myIngred.search(mtrl[i].name) == Tnil) {
			return false;
		}
	}
	return true;
}

bool	RBRecipe::canMakeTree(RedBlackTree& myIngred) {
	return tree.traverse(myIngred);
}