#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;



//string solve(string str) {
//	stack<char> st;
//	for (int i = 0; i < str.size(); i++) {
//		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
//			st.push(str[i]);
//		}
//		else if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
//			if (st.empty())
//				return "NO";
//			else {
//				if (str[i] == ')') {
//					if (st.top() == '(')
//						st.pop();
//					else
//						return "NO";
//				}
//				else if (str[i] == ']') {
//					if (st.top() == '[')
//						st.pop();
//					else
//						return "NO";
//				}
//				if (str[i] == '}') {
//					if (st.top() == '{')
//						st.pop();
//					else
//						return "NO";
//				}
//			}
//		}
//	}
//	if (!st.empty())
//		return "NO";
//	return "YES";
//}

string solve(string& str) {
	const string open = "({[", close = ")}]";
	stack<char> st;

	for (int i = 0; i < str.size(); i++) {
		// 여는 괄호인지 아닌지 확인
		if (open.find(str[i]) != -1) {
			cout << str[i] << endl;
			cout << open.find(str[i]) << endl;
			st.push(str[i]);
		}
		else {
			if (st.empty())
				return "NO";
			else {
				if (open.find(st.top()) != close.find(str[i]))
					return "NO";
				else st.pop();
			}
		}
	}
	if (!st.empty())
		return "NO";
	return "YES";
}

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		string tmp;
		cin >> tmp;
		cout << solve(tmp) << "\n";
	}
}