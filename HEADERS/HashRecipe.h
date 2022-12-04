#ifndef HASHRECIPE_H
#define HASHRECIPE_H
#include "Recipe.h"
#include "RecipeArray.h"
#define SIZE_TABLE 300

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
    // Hashtable[value].name = "" : 없다 : (main함수에서 : 어떤 재료명(외부) -> value를 가져와서 이 recipe의 재료를
    // main함수 : {내가 가지고 있는 재료} 그게 이 레시피 재료에 있는지? 물어보는 함수가 됨

    // 지금은 {내 재료 set} - {이 레시피 재료 set} =
    // 원래 성공조건 : {이 레시피 재료 set} - {내 재료 set} = 공집합 :
public:
    HashRecipe();
	void	pushIngredient(std::string & token);
    void 	SetRecipeName(std::string s);
    void 	PlusIngredient(std::string name, std::string quantity);
    int     MakeHash(std::string t, int tSize); // Rabin-Karp 알고리즘에서 문자열의 해쉬값 구하는 부분 응용
    int     searchIngredient(std::string s);
    bool    canMakeVec(HashRecipe &myIngred);
    bool    canMakeHash(HashRecipe &myIngred);
    void    PrintAll() const;
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