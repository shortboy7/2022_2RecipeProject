#include <iostream>
#include <string>
using namespace std;

int main(){
	string str = "°¡³ª´Ù";
	int i;
	for (i = str.size() - 1; i >=0 ; i--) {
		if (str[i] == ',') break;
	}
	cout << i << " " << str.size() - i << "\n";
	cout << str.substr(0, i) <<"\n";
	cout << str.substr(i + 1, str.size() - i) << "\n";
	return 0;
}