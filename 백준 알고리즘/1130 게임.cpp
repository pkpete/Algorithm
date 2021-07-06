//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int n, m;
//int map[51][51];
//bool check[51][51];
//int dp[51][51];
//int dirX[4] = { 1,0,-1,0 };
//int dirY[4] = { 0,1,0,-1 };
//
//void clear_dp() {
//	for (int i = 0; i < 51; i++) {
//		for (int j = 0; j < 51; j++) {
//			dp[i][j] = -1;
//		}
//	}
//}
//
//int dfs(int y, int x) {
//	
//	if (x<0 || y < 0 || y >= n || x >= m || map[y][x] == 0) return 0;
//	if (check[y][x]) {
//		cout << -1 << endl;
//		exit(0);
//	}
//	if (dp[y][x] != -1) return dp[y][x];
//
//	check[y][x] = true;
//	dp[y][x] = 0;
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dirX[i] * map[y][x];
//		int ny = y + dirY[i] * map[y][x];
//		dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
//	}
//	check[y][x] = false;
//	return dp[y][x];
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		string str;
//		cin >> str;
//		for (int j = 0; j < m; j++) {
//			if (str[j] == 'H') {
//				map[i][j] = 0;
//			}
//			else
//				map[i][j] = str[j] - '0';
//		}
//	}
//
//	clear_dp();
//	cout << dfs(0, 0);
//}

#include <iostream>
using namespace std;
int n, m;
char board[51][51];
int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 }, limit;
int jump[50][50];	// 시작부터 가장 많이 점프한 횟수
int answer;

void dfs(int y, int x, int cnt) {
	if (answer < cnt) answer = cnt;
	if (answer > limit) return;
	
	if (y < 0 || n <= y || x < 0 || m <= x || board[y][x] == 0) return;
	if (cnt <= jump[y][x]) return;
	jump[y][x] = cnt;

	int mul = board[y][x];
	for (int i = 0; i < 4; i++) {
		dfs(y + dy[i] * mul, x + dx[i] * mul, cnt + 1);
	}
}

int main() {
	cin >> n >> m;
	limit = n * m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			jump[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == 'H') {
				board[i][j] = 0;
			}
			else
				board[i][j] = str[j] - '0';
		}
	}
	dfs(0, 0, 0);
	if (answer > limit) answer = -1;
	cout << answer << endl;
}