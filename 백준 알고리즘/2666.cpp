#include <iostream>
#include <algorithm>
using namespace std;
int n, m, answer = 1000000000;
int order[21];
void dfs(int a, int b, int index, int sum) {
	if (index == m) {
		answer = min(sum, answer);
		return;
	}
	dfs(order[index], b, index + 1, sum + abs(order[index] - a));
	dfs(a, order[index], index + 1, sum + abs(order[index] - b));
}
int main() {
	cin >> n;
	int a, b;
	cin >> a >> b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> order[i];
	}
	dfs(a, b, 0, 0);
	cout << answer;
}