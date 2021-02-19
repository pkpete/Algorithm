#include <iostream>
#include <string>
using namespace std;
char arr[4] = { 'U', 'C', 'P', 'C' };
int main() {
	string str;
	getline(cin, str);
	string answer = "";
	int index = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == arr[index]) {
			answer += str[i];
			index++;
		}
	}
	if (answer == "UCPC") {
		cout << "I love UCPC" << "\n";
	}
	else
		cout << "I hate UCPC" << "\n";
}