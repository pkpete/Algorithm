#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n, k, answer = 0;
bool abc[26];	//a = 49
vector<string> words;

void dfs(int idx, int size) {
	if (size == k) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			bool read = true;
			for (int j = 0; j < words[i].size(); j++) {
				if (abc[words[i][j] - 'a'] == false) {
					read = false;
					break;
				}
			}
			if (read) cnt++;
		}
		answer = max(cnt, answer);
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (abc[i]) continue;
		abc[i] = true;
		dfs(i+1, size + 1);
		abc[i] = false;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		tmp = tmp.substr(4, tmp.size() - 8);
		words.push_back(tmp);
	}

	if (k < 5) {
		cout << 0;
		return 0;
	}
	else if (k == 26) {
		cout << n;
		return 0;
	}
	k = k - 5;
	string tmp = "antic";
	for (int i = 0; i < tmp.size(); i++) {
		abc[tmp[i] - 'a'] = true;
	}

	dfs(0, 0);

	cout << answer;
}