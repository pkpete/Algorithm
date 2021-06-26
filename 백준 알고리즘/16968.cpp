#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	char before = 'a';
	cin >> str;
	int answer = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != before) {
			if (str[i] == 'd') {
				answer *= 10;
			}
			else if (str[i] == 'c') {
				answer *= 26;
			}
		}
		else {
			if (str[i] == 'd') {
				answer *= 9;
			}
			else if (str[i] == 'c') {
				answer *= 25;
			}
		}

		before = str[i];
	}

	cout << answer;
}