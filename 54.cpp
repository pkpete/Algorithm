#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	string str;
	cin >> str;
	stack<char> st;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			st.push('(');
		}
		else {
			if (!st.empty() && st.top() == '(') {
				st.pop();
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	if (st.empty()) cout << "YES";
	else cout << "NO";
}