#include <iostream>
#include <algorithm>
using namespace std;
int map[35][35];
int n, m, h, answer = 1000000000;

bool check_answer() {
	for (int i = 1; i <= n; i++) {
		int current_col = i;
		for (int j = 1; j <= h; j++) {
			if (map[j][current_col] == 1) current_col++;
			else if (map[j][current_col - 1] == 1) current_col--;
		}
		if (i != current_col)
			return false;
	}
	return true;
}

void dfs(int cur_row, int cnt) {
	if (cnt > 3) return;
	if (check_answer()) {
		answer = min(answer,cnt);
		return;
	}
	for (int i = cur_row; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] || map[i][j - 1] || map[i][j + 1]) continue;
			map[i][j] = 1;
			dfs(i, cnt + 1);
			map[i][j] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	
	dfs(1, 0);
	if (answer == 1000000000)
		cout << -1;
	else
		cout << answer;
}