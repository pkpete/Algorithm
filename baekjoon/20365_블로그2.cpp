#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	char first = str[0];
	char before = 'A';
	int cnt = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		if (first != str[i] && before != str[i])
			cnt++;
		before = str[i];
	}
	cout << cnt;
}