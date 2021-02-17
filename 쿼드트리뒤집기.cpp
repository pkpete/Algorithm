#include <iostream>
using namespace std;
string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w') {
		return string(1, head);
	}
	string upper_left = reverse(it);
	string upper_right = reverse(it);
	string lower_left = reverse(it);
	string lower_right = reverse(it);
	return string("x") + lower_left + lower_right + upper_left + upper_right;
}
int main() {
	int num;
	cin >> num;
	while (num) {
		num--;
		string str;
		cin >> str;
		string::iterator iter = str.begin();
		cout << reverse(iter) << "\n";
	}
}
