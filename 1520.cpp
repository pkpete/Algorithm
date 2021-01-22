#include <iostream>
using namespace std;
int map[501][501];
int dp[501][501];
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
int row_size, col_size;
void input() {
	cin >> col_size >> row_size;
	for (int i = 1; i <= col_size; i++) {
		for (int j = 1; j <= row_size; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
}
int dfs(int y, int x) {
	if (y == col_size && x == row_size) {
		return 1;
	}
	int& cnt = dp[y][x];
	if (cnt != -1) return cnt;
	cnt = 0;
	for (int i = 0; i < 4; i++) {
		int movex = x + dirX[i];
		int movey = y + dirY[i];
		if (movex > 0 && movey > 0 && movex <= row_size && movey <= col_size && map[y][x] > map[movey][movex]) {
			cnt += dfs(movey, movex);
		}
	}
	return cnt;
}
int main() {
	input();
	dp[col_size][row_size] = 1;
	int answer = dfs(1, 1);
	cout << answer;
}