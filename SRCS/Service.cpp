#include "../HEADERS/Service.h"
using namespace std;

//���� �Լ�
template class Service<Recipe>;
template class Service<HashRecipe>;
template class Service<RBRecipe>;

template <typename T>
void	Service<T>::run()
{
    int selectCMD = 0;
    srand(time(NULL));
    cout << "-----�޴� ��õ ���α׷�-----" << endl;
    while (selectCMD != -1)
    {
        cout << "��� �������� �޴��� ��õ�ްڽ��ϱ�?" << endl;
        cout << "1. �޴� ī�װ���  2. �丮 ����  3. �丮 �κ�  0.����" << endl;
        cin >> selectCMD;
        cout << endl;
        switch(selectCMD)
        {
            case 0:
                cout << "���α׷��� �����մϴ�." << endl;
                return;
            case 1:
                cout << "1. �޴� ī�װ����� �����ϼ̽��ϴ�." << endl;
                menu_class();
                break;
            case 2:
                cout << "2. �丮 ������ �����ϼ̽��ϴ�." << endl;
                menu_level();
                break;
            case 3:
                cout << "3. �丮 �κ��� �����ϼ̽��ϴ�." << endl;
                menu_amount();

            default:
                cout << "�߸��� ���Դϴ�." << endl;
        }
    }
}

template <typename T>
void Service<T>::menu_class(){
    int classCMD = 0;
    cout << endl;
    cout << "���ϴ� ī�װ����� �������ּ���." << endl;
    while(classCMD != -1)
    {
        cout << "1.�ѽĸ޴� | 2.��ĸ޴� | 3.�      | 4.��,��       | 5.��,��,��    | " << endl;
        cout << "6.���ι��� | 7.�ع���   | 8.��ġ,���� | 9.���,�ҽ�,�� | 10.��,����    | " << endl;
        cout << "11.��      | 12.����   | 13.������   | 14.����Ʈ      | 15.��,����,�� | " << endl;
        cout << "16.ǻ��    | 17.��Ÿ   | 0. ����" << endl;

        cin >> classCMD;

        switch(classCMD)
        {
            case 1:
                cout << "1.�ѽĸ޴��� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "�ѽĸ޴�");
                break;
            case 2:
                cout << "2.��ĸ޴��� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "��ĸ޴�");
                break;
            case 3:
                cout << "3.��� �����ϼ̽��ϴ�." << endl;
                extract_menu(1,"�");
                break;
            case 4:
                cout << "4.��,���� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "��,��");
                break;
            case 5:
                cout << "5.��,��,���� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "��,��,��");
                break;
            case 6:
                cout << "6.���ι����� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "���ι���");
                break;
            case 7:
                cout << "7.�ع����� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "�ع���");
                break;
            case 8:
                cout << "8.��ġ,������ �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "��ġ,����");
                break;
            case 9:
                cout << "9.���,�ҽ�,���� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "���,�ҽ�,��");
                break;
            case 10:
                cout << "10.��,���θ� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "��,����");
                break;
            case 11:
                cout << "11.���� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "��");
                break;
            case 12:
                cout << "12.������ �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "����");
                break;
            case 13:
                cout << "13.�����带 �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "������");
                break;
            case 14:
                cout << "14.����Ʈ�� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "����Ʈ");
                break;
            case 15:
                cout << "15.��,����,���� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "��,����,��");
                break;
            case 16:
                cout << "16.ǻ���� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "ǻ��");
                break;
            case 17:
                cout << "17.��Ÿ�� �����ϼ̽��ϴ�." << endl;
                extract_menu(1, "��Ÿ");
                break;
            case 0:
                cout << "���α׷��� �����մϴ�." << endl;
                exit;
            default:
                cout << "�߸��� �Է��Դϴ�." << endl;
        }
        return;
    }
}

//�丮 ���� ���� ���͸� �Լ�
template <typename T>
void Service<T>::menu_level()
{
    int levelCMD = 0;
	cout << endl;
	cout << "���ϴ� �丮 ���̵��� �������ּ���." << endl;
	while(levelCMD != -1)
	{
		cout << " 0.�ƹ��� | 1. �ʺ� | 2.�߱� | 3.���� | 4.���ǰ��� " << endl;

		cin >> levelCMD;

		switch(levelCMD) {
			case 0:
				cout << "0. �ƹ��� ���̵��� �����ϼ̽��ϴ�." << endl;
				extract_menu(2, 0);
				break;
			case 1:
				cout << "1. �ʺ� ���̵��� �����ϼ̽��ϴ�." << endl;
				extract_menu(2, 1);
				break;
			case 2:
				cout << "2. �߱� ���̵��� �����ϼ̽��ϴ�." << endl;
				extract_menu(2, 2);
				break;
            case 3:
                cout << "3. ���� ���̵��� �����ϼ̽��ϴ�." << endl;
				extract_menu(2, 3);
				break;
            case 4:
                cout << "4. ���ǰ��� ���̵��� �����ϼ̽��ϴ�." << endl;
				extract_menu(2, 4);
				break;
			default:
				cout << "�߸��� �Է��Դϴ�." << endl;
		}
		return;
	}
}
//�丮 �κ� ���� ���͸� �Լ�
template <typename T>
void Service<T>::menu_amount()
{
    int amountCMD = 0;
    cout << endl;
    cout << "���ϴ� �丮�� �κ�(��)�� �������ּ���." << endl;
    while(amountCMD != -1)
    {
        cout << " 1. 1�κ� | 2. 2�κ� | 3. 3�κ� | 4. 4�κ� | 5. 5�κ� | 6. 6�κ� �̻�  |" << endl;

        cin >> amountCMD;

        switch(amountCMD) {
            case 1:
                cout << "1. 1�κ� ������ �����ϼ̽��ϴ�." << endl;
                extract_menu(3, 1);
                break;
            case 2:
                cout << "2. 2�κ� ������ �����ϼ̽��ϴ�." << endl;
                extract_menu(3, 2);
                break;
            case 3:
                cout << "3. 3�κ� ������ �����ϼ̽��ϴ�." << endl;
                extract_menu(3, 3);
                break;
            case 4:
                cout << "4. 4�κ� ������ �����ϼ̽��ϴ�." << endl;
                extract_menu(3, 4);
                break;
            case 5:
                cout << "4. 5�κ� ������ �����ϼ̽��ϴ�." << endl;
                extract_menu(3, 5);
                break;
            case 6:
                cout << "4. 6�κ� �̻� ������ �����ϼ̽��ϴ�." << endl;
                extract_menu(3, 6);
                break;
            default:
                cout << "�߸��� �Է��Դϴ�." << endl;
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

//result.csv���� �丮 5�� �������� �����ϴ� �Լ�
template <typename T>
void Service<T>::extract_menu(int cmd, const std::string& condition)
{
    RecipeArray<T> filtered(recipes.curSize + 1);
    filterRecipe(filtered, cmd, condition);
     if (filtered.curSize == 0) {
        cout << "�˻��� ����� �����ϴ�!\n";
        return;
    }else cout << "�� " << filtered.curSize << "���� ���\n";
    bool *selected = new bool[filtered.curSize];
    for (int i = 0 ; i < filtered.curSize; i++) selected[i] = false;
    char re = 'n';
    do{
        bool fin = showRandom(filtered, selected);
        if (fin) {
            cout << "��� �����Ǹ� Ȯ���ϼ̽��ϴ�!\n";
            break;
        }
        cout << "�ٸ� �����Ǹ� ���ðڽ��ϱ�?(y, n)\n";
        cin >> re;
    }while(re == 'y');
    delete selected;
}

//result.csv���� �丮 5�� �������� �����ϴ� �Լ�
template <typename T>
void Service<T>::extract_menu(int cmd, const int& condition)
{
    RecipeArray<T> filtered(recipes.curSize + 1);
    filterRecipe(filtered, cmd, condition);
    if (filtered.curSize == 0) {
        cout << "�˻��� ����� �����ϴ�!\n";
        return;
    }else cout << "�� " << filtered.curSize << "���� ���\n";
    bool *selected = new bool[filtered.curSize];
    for (int i = 0 ; i < filtered.curSize; i++) selected[i] = false;
    char re = 'n';
    do{
        bool fin = showRandom(filtered, selected);
        if (fin) {
            cout << "��� �����Ǹ� Ȯ���ϼ̽��ϴ�!\n";
            break;
        }
        cout << "�ٸ� �����Ǹ� ���ðڽ��ϱ�?(y, n)\n";
        cin >> re;
    }while(re == 'y');
    delete selected;
}