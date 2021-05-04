#include <iostream>
#include <vector>
using namespace std;
int map[251][251];
int check[251][251];
int dirX[8] = {0,1,1,1,0,-1,-1,-1};
int dirY[8] = {-1,-1,0,1,1,1,0,-1};
int m, n;
int cnt = 1;
vector<pair<int, int>> v;

bool in_map(int y, int x) {
	if (y >= 0 && x >= 0 && y < m && x < n)
		return true;
	else return false;
}

void dfs(int y, int x, int tmp) {
	if (check[y][x] != 0)
		return;
	check[y][x] = cnt;
	for (int i = 0; i < 8; i++) {
		int movex = x + dirX[i];
		int movey = y + dirY[i];
		if (in_map(movey, movex), map[movey][movex] == 1 && check[movey][movex] == 0) {
			dfs(movey, movex,tmp+1);
		}
	}
	if (tmp == 0)
		cnt++;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		dfs(v[i].first, v[i].second, 0);
	}

	cout << cnt-1;
}