#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
	string str;
	while (1) {
		bool balance = true;
		stack<char> st;
		getline(cin, str);
		if (str == ".") break;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				st.push(str[i]);
			}
			else if (str[i] == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else balance = false;
			}
			else if (str[i] == ']') {
				if (!st.empty() && st.top() == '[')
					st.pop();
				else balance = false;
			}
		}
		if (!st.empty() || !balance)
			cout << "no" << endl;
		else cout << "yes" << endl;

	}
}