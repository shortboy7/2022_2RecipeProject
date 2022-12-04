#include "../HEADERS/Service.h"
using namespace std;

//메인 함수
template class Service<Recipe>;
template class Service<HashRecipe>;
template class Service<RBRecipe>;

template <typename T>
void	Service<T>::run()
{
    int selectCMD = 0;
    srand(time(NULL));
    cout << "-----메뉴 추천 프로그램-----" << endl;
    while (selectCMD != -1)
    {
        cout << "어느 기준으로 메뉴를 추천받겠습니까?" << endl;
        cout << "1. 메뉴 카테고리  2. 요리 수준  3. 요리 인분  0.종료" << endl;
        cin >> selectCMD;
        cout << endl;
        switch(selectCMD)
        {
            case 0:
                cout << "프로그램을 종료합니다." << endl;
                return;
            case 1:
                cout << "1. 메뉴 카테고리를 선택하셨습니다." << endl;
                menu_class();
                break;
            case 2:
                cout << "2. 요리 수준을 선택하셨습니다." << endl;
                menu_level();
                break;
            case 3:
                cout << "3. 요리 인분을 선택하셨습니다." << endl;
                menu_amount();
                break;
            default:
                cout << "잘못된 값입니다." << endl;
        }
    }
}

template <typename T>
void Service<T>::menu_class(){
    int classCMD = 0;
    cout << endl;
    cout << "원하는 카테고리를 선택해주세요." << endl;
    while(classCMD != -1)
    {
        cout << "1.한식메뉴 | 2.양식메뉴 | 3.찌개      | 4.국,탕       | 5.밥,죽,떡    | " << endl;
        cout << "6.메인반찬 | 7.밑반찬   | 8.김치,젓갈 | 9.양념,소스,잼 | 10.면,만두    | " << endl;
        cout << "11.빵      | 12.스프   | 13.샐러드   | 14.디저트      | 15.차,음료,술 | " << endl;
        cout << "16.퓨전    | 17.기타   " << endl;

        cin >> classCMD;

        switch(classCMD)
        {
            case 1:
                cout << "1.한식메뉴를 선택하셨습니다." << endl;
                extract_menu(1, "한식메뉴");
                break;
            case 2:
                cout << "2.양식메뉴를 선택하셨습니다." << endl;
                extract_menu(1, "양식메뉴");
                // continue;
                break;
            case 3:
                cout << "3.찌개를 선택하셨습니다." << endl;
                extract_menu(1,"찌개");
                break;
            case 4:
                cout << "4.국,탕을 선택하셨습니다." << endl;
                extract_menu(1, "국/탕");
                break;
            case 5:
                cout << "5.밥,죽,떡을 선택하셨습니다." << endl;
                extract_menu(1, "밥/죽/떡");
                break;
            case 6:
                cout << "6.메인반찬을 선택하셨습니다." << endl;
                extract_menu(1, "메인반찬");
                break;
            case 7:
                cout << "7.밑반찬을 선택하셨습니다." << endl;
                extract_menu(1, "밑반찬");
                break;
            case 8:
                cout << "8.김치,젓갈을 선택하셨습니다." << endl;
                extract_menu(1, "김치/젓갈");
                break;
            case 9:
                cout << "9.양념,소스,잼을 선택하셨습니다." << endl;
                extract_menu(1, "양념/소스/잼");
                break;
            case 10:
                cout << "10.면,만두를 선택하셨습니다." << endl;
                extract_menu(1, "면/만두");
                break;
            case 11:
                cout << "11.빵을 선택하셨습니다." << endl;
                extract_menu(1, "빵");
                break;
            case 12:
                cout << "12.스프를 선택하셨습니다." << endl;
                extract_menu(1, "스프");
                break;
            case 13:
                cout << "13.샐러드를 선택하셨습니다." << endl;
                extract_menu(1, "샐러드");
                break;
            case 14:
                cout << "14.디저트를 선택하셨습니다." << endl;
                extract_menu(1, "디저트");
                break;
            case 15:
                cout << "15.차,음료,술을 선택하셨습니다." << endl;
                extract_menu(1, "차/음료/술");
                break;
            case 16:
                cout << "16.퓨전을 선택하셨습니다." << endl;
                extract_menu(1, "퓨전");
                break;
            case 17:
                cout << "17.기타를 선택하셨습니다." << endl;
                extract_menu(1, "기타");
                break;

            default:
                cout << "잘못된 입력입니다." << endl;
        }
        return;
    }
}

//요리 수준 기준 필터링 함수
template <typename T>
void Service<T>::menu_level()
{
    int levelCMD = 0;
	cout << endl;
	cout << "원하는 요리 난이도를 선택해주세요." << endl;
	while(levelCMD != -1)
	{
		cout << " 0.아무나 | 1. 초보 | 2.중급 | 3.고급 | 4.신의경지 " << endl;

		cin >> levelCMD;

		switch(levelCMD) {
			case 0:
				cout << "0. 아무나 난이도를 선택하셨습니다." << endl;
				extract_menu(2, 0);
				break;
			case 1:
				cout << "1. 초보 난이도를 선택하셨습니다." << endl;
				extract_menu(2, 1);
				break;
			case 2:
				cout << "2. 중급 난이도를 선택하셨습니다." << endl;
				extract_menu(2, 2);
				break;
            case 3:
                cout << "3. 고급 난이도를 선택하셨습니다." << endl;
				extract_menu(2, 3);
				break;
            case 4:
                cout << "4. 신의경지 난이도를 선택하셨습니다." << endl;
				extract_menu(2, 4);
				break;
			default:
				cout << "잘못된 입력입니다." << endl;
		}
		return;
	}
}
//요리 인분 기준 필터링 함수
template <typename T>
void Service<T>::menu_amount()
{
    int amountCMD = 0;
    cout << endl;
    cout << "원하는 요리의 인분(양)을 선택해주세요." << endl;
    while(amountCMD != -1)
    {
        cout << " 1. 1인분 | 2. 2인분 | 3. 3인분 | 4. 4인분 | 5. 5인분 | 6. 6인분 이상  |" << endl;

        cin >> amountCMD;

        switch(amountCMD) {
            case 1:
                cout << "1. 1인분 기준을 선택하셨습니다." << endl;
                extract_menu(3, 1);
                break;
            case 2:
                cout << "2. 2인분 기준을 선택하셨습니다." << endl;
                extract_menu(3, 2);
                break;
            case 3:
                cout << "3. 3인분 기준을 선택하셨습니다." << endl;
                extract_menu(3, 3);
                break;
            case 4:
                cout << "4. 4인분 기준을 선택하셨습니다." << endl;
                extract_menu(3, 4);
                break;
            case 5:
                cout << "4. 5인분 기준을 선택하셨습니다." << endl;
                extract_menu(3, 5);
                break;
            case 6:
                cout << "4. 6인분 이상 기준을 선택하셨습니다." << endl;
                extract_menu(3, 6);
                break;
            default:
                cout << "잘못된 입력입니다." << endl;
        }
        return;
    }
}

template <typename T>
void    Service<T>::filterRecipe(RecipeArray<T>& filtered, int col, const string& condition) {
    for (int i = 0; i < recipes.curSize; i++) {
        bool good = false;
        switch(col) {
            case 1:
                good = recipes[i].category == condition;
                break;
            // case 2:
            //     good = recipes[i].level == condition;
            //     break;
            // case 3:
            //     good = recipes[i].amount == condition;
            //     break;
        }
        if (good) filtered.push_back(recipes[i]);
    }
}

template <typename T>
void    Service<T>::filterRecipe(RecipeArray<T>& filtered, int col, const int& condition) {
    for (int i = 0; i < recipes.curSize; i++) {
        bool good = false;
        switch(col) {
            case 2:
                good = recipes[i].level == condition;
                break;
            case 3:
                good = recipes[i].amount == condition;
                break;
        }
        if (good) filtered.push_back(recipes[i]);
    }
}

template <typename T>
bool	Service<T>::showRandom(RecipeArray<T>& filtered, bool* selected){
    int picked = -1;
    for (int i = 0 ; i < 5; i++) {
        int ch = 0;
        for (ch = 0 ; ch < filtered.curSize && selected[ch]; ch++) {
        }
        if (ch == filtered.curSize){
            return true;
            break;
        }
        do{
            picked = rand() % filtered.curSize;
        }while(selected[picked]);
        selected[picked] = true;
        cout << filtered[picked];
    }
    return false;
}

//result.csv에서 요리 5개 랜덤으로 추출하는 함수
template <typename T>
void Service<T>::extract_menu(int cmd, const std::string& condition)
{
    RecipeArray<T> filtered(recipes.curSize + 1);
    filterRecipe(filtered, cmd, condition);
     if (filtered.curSize == 0) {
        cout << "검색된 결과가 없습니다!\n";
        return;
    }else cout << "총 " << filtered.curSize << "개의 결과\n";
    bool *selected = new bool[filtered.curSize];
    for (int i = 0 ; i < filtered.curSize; i++) selected[i] = false;
    char re = 'n';
    do{
        bool fin = showRandom(filtered, selected);
        if (fin) {
            cout << "모든 레시피를 확인하셨습니다!\n";
            break;
        }
        cout << "다른 레시피를 보시겠습니까?(y, n)\n";
        cin >> re;
    }while(re == 'y');
    delete [] selected;
    return;
}

//result.csv에서 요리 5개 랜덤으로 추출하는 함수
template <typename T>
void Service<T>::extract_menu(int cmd, const int& condition)
{
    RecipeArray<T> filtered(recipes.curSize + 1);
    filterRecipe(filtered, cmd, condition);
    if (filtered.curSize == 0) {
        cout << "검색된 결과가 없습니다!\n";
        return;
    }else cout << "총 " << filtered.curSize << "개의 결과\n";
    bool *selected = new bool[filtered.curSize];
    for (int i = 0 ; i < filtered.curSize; i++) selected[i] = false;
    char re = 'n';
    do{
        bool fin = showRandom(filtered, selected);
        if (fin) {
            cout << "모든 레시피를 확인하셨습니다!\n";
            break;
        }
        cout << "다른 레시피를 보시겠습니까?(y, n)\n";
        cin >> re;
    }while(re == 'y');
    delete [] selected;
    return;
}