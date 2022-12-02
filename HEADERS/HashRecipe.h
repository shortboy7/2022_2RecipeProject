#ifndef HASHRECIPE_H
#define HASHRECIPE_H
#include "Recipe.h"

#define SIZE_TABLE 25

typedef struct HashNode
{
    std::string name;
    std::string quantity;
} HashNode;


class HashRecipe : public Recipe
{
private:
	// 레시피 이름
    HashNode Hashtable[SIZE_TABLE]; // 재료의 이름과 양을 저장할 해쉬테이블

public:
    HashRecipe();
	void	pushIngredient(std::string & token);
	bool	canMake(HashNode* ingred, int ingredNum);
    void 	SetRecipeName(std::string s);
    void 	PlusIngredient(std::string name, std::string quantity);
    int     MakeHash(std::string t, int tSize); // Rabin-Karp 알고리즘에서 문자열의 해쉬값 구하는 부분 응용
    int     searchIngredient(std::string s);
    void PrintAll() const;
	friend std::ostream& operator<<(std::ostream& out, const HashRecipe& recipe) {
		recipe.PrintAll();
        return out;
	}
    friend std::ofstream& operator<<(std::ofstream& fout, const HashRecipe& recipe) {
        fout << recipe.name << ",";
        for (int i = 0; i < SIZE_TABLE; i++)
        {
            if (recipe.Hashtable[i].name == "") continue;
            fout << recipe.Hashtable[i].name << ",";
        }
        fout << "\n";
        return fout;
    }
};

#endif