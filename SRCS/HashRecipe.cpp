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

 int HashRecipe::MakeHash(string t, int tSize) // Rabin-Karp �˰��򿡼� ���ڿ��� �ؽ��� ���ϴ� �κ� ����
{
	int tHash = 0; // text string�� �ؽð�
	int power = 1; // ������

	for (int i = 0; i < tSize; i++)
	{
		tHash += t[tSize - 1 - i] * power; // ���� ������ ���ں��� ���ʴ�� (�ش� ���� * power)�� �Ի��� ���� ���ؼ� �ؽð��� ����Ѵ�.
		if (i < tSize - 1)                 // ������ ���ں��� �������� ���� ���ʴ�� 3^0, 3^1, 3^2, ... �� �ȴ�.
			power *= 3;
	}
	if (tHash < 0) // ���밪���� �ٲ��� ��ⷯ ����
	{
		tHash = tHash * (-1);
	}
	tHash = tHash % SIZE_TABLE; // ��ⷯ ����

	return tHash;
}

int HashRecipe::searchIngredient(string s)
{
	int data = MakeHash(s, s.length());
	while (Hashtable[data].name != "")
	{
		if (Hashtable[data].name == s)
		{
			return 1; // ����
		}
		else
		{
			data = 1 + data % 7;
		}
	}
	return 0; // ����
}

void HashRecipe::PrintAll() const
{
	cout << "������ �̸� : " << name << "��� :";
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