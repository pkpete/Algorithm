#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> v(n), answer;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	string str;
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (binary_search(v.begin(), v.end(), str)) {
			answer.push_back(str);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
}