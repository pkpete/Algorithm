#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string str;
	getline(cin, str);
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	for(int i = 0; i < str.size(); i++){
		str[i] = tolower(str[i]);
	}
	cout << str;
}