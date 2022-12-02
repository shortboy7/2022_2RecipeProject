#include "../HEADERS/HashRecipe.h"
using namespace std;

HashRecipe::HashRecipe() {
	name = "";
}

void HashRecipe::SetRecipeName(string s)
{
	name = s;
}

void HashRecipe::PlusIngredient(string name, string quantity)
{
	int data = MakeHash(name, name.length());
	while (Hashtable[data].name != "")
	{
		data = 1 + data % 7;
	}
	Hashtable[data].name = name;
	Hashtable[data].quantity = quantity;
}

 int HashRecipe::MakeHash(string t, int tSize) // Rabin-Karp 알고리즘에서 문자열의 해쉬값 구하는 부분 응용
{
	int tHash = 0; // text string의 해시값
	int power = 1; // 제곱수

	for (int i = 0; i < tSize; i++)
	{
		tHash += t[tSize - 1 - i] * power; // 가장 오른쪽 문자부터 차례대로 (해당 문자 * power)를 게산한 값을 더해서 해시값을 계산한다.
		if (i < tSize - 1)                 // 오른쪽 문자부터 곱해지는 수가 차례대로 3^0, 3^1, 3^2, ... 이 된다.
			power *= 3;
	}
	if (tHash < 0) // 절대값으로 바꾼후 모듈러 연산
	{
		tHash = tHash * (-1);
	}
	tHash = tHash % SIZE_TABLE; // 모듈러 연산

	return tHash;
}

int HashRecipe::searchIngredient(string s)
{
	int data = MakeHash(s, s.length());
	while (Hashtable[data].name != "")
	{
		if (Hashtable[data].name == s)
		{
			return 1; // 있음
		}
		else
		{
			data = 1 + data % 7;
		}
	}
	return 0; // 없음
}

void HashRecipe::PrintAll() const
{
	cout << "레시피 이름 : " << name << "재료 :";
	for (int i = 0; i < SIZE_TABLE; i++)
	{
		if (Hashtable[i].name == "") continue;
		cout << Hashtable[i].name << " ";
	}
	cout << "\n";
}

void	HashRecipe::pushIngredient(std::string & token){
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
	PlusIngredient(aft, qua);
}

bool	HashRecipe::canMake(HashNode* ingred, int ingredNum){
	return false;
}