#include <iostream>
#include <stack>
using namespace std;
int main() {
	string str;
	cin >> str;
	int sum = 0, tmp = 1;
	bool error = false;
	stack<char> st;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			tmp *= 2;
			st.push(str[i]);
		}
		else if (str[i] == ')') {
			if (st.empty()) {
				error = true;
				break;
			}
			if (st.top() == '(') {
				st.pop();
				if (str[i - 1] == '(')
					sum += tmp;
				tmp /= 2;
			}
			else {
				error = true;
				break;
			}
		}

		else if (str[i] == '[') {
			tmp *= 3;
			st.push(str[i]);
		}
		else if (str[i] == ']') {
			if (st.empty()) {
				error = true;
				break;
			}
			if (st.top() == '[') {
				st.pop();
				if (str[i - 1] == '[')
					sum += tmp;
				tmp /= 3;
			}
			else {
				error = true;
				break;
			}
		}
	}
	if (error || !st.empty()) {
		cout << 0;
		return 0;
	}
	cout << sum;
}