#include <iostream>
using namespace std;
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
int map[51][51];
int t, m, n, k, cnt = 0;
bool check[51][51];
void clear_map() {
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++) {
			map[i][j] = 0;
			check[i][j] = false;
		}
}

bool in_map(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m)
		return true;
	return false;
}

void dfs(int y, int x) {
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int movex = x + dirX[i], movey = y + dirY[i];
		if (map[movey][movex] == 1 && !check[movey][movex] && in_map(movey, movex)) {
			dfs(movey, movex);
		}
	}
}

int main() {
	cin >> t;
	while (t) {
		t--;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && !check[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		clear_map();
		cnt = 0;
	}
}