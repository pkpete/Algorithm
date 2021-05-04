#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<char> v;
	stack<int> st;
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		if (num == cnt) {
			v.push_back('P');
			v.push_back('O');
			cnt++;
		}
		else {
			v.push_back('P');
			st.push(num);
		}
		while (!st.empty() && st.top() == cnt) {
			v.push_back('O');
			st.pop();
			cnt++;
		}
	}
	if (st.empty()) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
	}
	else {
		cout << "impossible";
	}

}