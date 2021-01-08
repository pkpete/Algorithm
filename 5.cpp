#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	cin >> s;
	int year;
	string sex;
	switch(s[7]-'0'){
		case 1:
			year = 1900 + (s[0]-'0')*10 + (s[1]-'0');
			sex = 'M';
			break;
		case 2:
			year = 1900 + (s[0]-'0')*10 + (s[1]-'0');
			sex = 'W';
			break;
		case 3:
			year = 2000 + (s[0]-'0')*10 + (s[1]-'0');
			sex = 'M';
			break;
		case 4:
			year = 2000 + (s[0]-'0')*10 + (s[1]-'0');
			sex = 'W';
			break;
	}
	cout << year << " " << sex;
	
}