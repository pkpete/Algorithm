#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[8][8];
int c_map[8][8];
int n, m, answer = 10000;
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };
vector<pair<int, pair<int, int>>> cctv;
vector<int> dir;
void clear_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c_map[i][j] = map[i][j];
		}
	}
}
int count_space() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c_map[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}
void activate(int direction, int y, int x) {
	int movey = y + dirY[direction];
	int movex = x + dirX[direction];
	while (movey >= 0 && movex >= 0 && movey < n && movex < m && c_map[movey][movex] != 6) {
		c_map[movey][movex] = 7;
		movey += dirY[direction];
		movex += dirX[direction];
	}
}
void start_cctv(int idx) {
	int direction = dir[idx];
	int type = cctv[idx].first;
	int y = cctv[idx].second.first;
	int x = cctv[idx].second.second;
	
	switch (type) {
	case 1:
		activate(direction, y, x);
		break;
	case 2:
		activate(direction, y, x);
		activate((direction + 2) % 4, y, x);
		break;
	case 3:
		activate(direction, y, x);
		activate((direction + 1) % 4, y, x);
		break;
	case 4:
		activate(direction, y, x);
		activate((direction + 1) % 4, y, x);
		activate((direction + 2) % 4, y, x);
		break;
	case 5:
		for (int i = 0; i < 4; i++)
			activate(i, y, x);
		break;
	}
	
}
void dfs(int idx) {
	if (idx == cctv.size()) {
		for (int i = 0; i < cctv.size(); i++) {
			start_cctv(i);
		}
		int cnt = count_space();
		answer = min(cnt, answer);
		clear_map();
		return;
	}
	int type = cctv[idx].first;
	int y = cctv[idx].second.first;
	int x = cctv[idx].second.second;
	
	if (type == 5) {
		dir[idx] = -1;
		dfs(idx + 1);
	}
	else if (type == 2) {
		for (int i = 0; i < 2; i++) {
			dir[idx] = i;
			dfs(idx + 1);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			dir[idx] = i;
			dfs(idx + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			c_map[i][j] = map[i][j];
			if (map[i][j] >= 1 && map[i][j] < 6) {
				cctv.push_back(make_pair(map[i][j], make_pair(i, j)));
			}
		}
	}
	dir = vector<int>(cctv.size());

	dfs(0);

	cout << answer;
}