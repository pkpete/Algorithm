#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> crane, box;
bool cmp(int a, int b) {
	if (a > b) 
		return true;
	return false;
}
void input() {
	cin >> n;
	crane.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> crane[i];
	}
	sort(crane.begin(), crane.end(), cmp);

	cin >> m;
	box.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> box[i];
	}
	sort(box.begin(), box.end(), cmp);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();

	if (box[0] > crane[0]) {
		cout << -1;
		return 0;
	}

	int answer = 0;
	while (!box.empty()) {
		for (int i = 0; i < crane.size(); i++) {
			for (int j = 0; j < box.size(); j++) {
				if (crane[i] >= box[j]) {
					box.erase(box.begin() + j);
					break;
				}
			}
		}
		answer++;
	}
	cout << answer;
}