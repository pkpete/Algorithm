#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<string> v;
int alpha[26];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
}
int main() {
	input();
	for (int i = 0; i < v.size(); i++) {
		int num = 1;
		for (int j = v[i].size() - 1; j >= 0; j--) {
			alpha[v[i][j] - 'A'] += num;
			num *= 10;
		}
	}
	sort(alpha, alpha + 26);
	int num = 9;
	int sum = 0;
	for (int i = 25; i >= 0; i--) {
		if (alpha[i] == 0)break;
		sum += alpha[i] * num--;
	}
	cout << sum;
}