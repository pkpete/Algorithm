#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[501][501];
bool check[501][501];
int dirY[4] = { 0,0,1,-1 };
int dirX[4] = { 1,-1,0,0 };
int cnt = 0, pic_size = 0;
int n, m;

bool in_map(int y, int x) {
	if (y >= 0 && y < n && x >= 0 && x < m)
		return true;
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && !check[i][j]) {
				cnt++;
				int tmp = 0;
				queue<pair<int, int>> q;
				q.push({ i,j });
				check[i][j] = true;
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					tmp++;
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int movey = y + dirY[dir], movex = x + dirX[dir];
						if (map[movey][movex] == 1 && !check[movey][movex] && in_map(movey, movex)) {
							q.push({ movey,movex });
							check[movey][movex] = true;
						}
					}
				}
				pic_size = max(pic_size, tmp);
			}
		}
	}
	cout << cnt << " " << pic_size;
}