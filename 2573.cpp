#include <iostream>
#include <queue>
using namespace std;
int map[301][301];
int cmap[301][301];
int check[301][301];
int col, row, cnt_year = 0;
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
void input() {
	cin >> col >> row;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin >> map[i][j];
			cmap[i][j] = map[i][j];
		}
	}
}

bool valid(int y, int x) {
	if (x >= 0 && y >= 0 && x < row && y < col)
		return true;
	else return false;
}

void clear() {
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			check[i][j] = 0;
		}
	}
}

void cnt_island(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int currentx = q.front().first;
		int currenty = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int movex = currentx + dirX[i];
			int movey = currenty + dirY[i];
			if (valid(movey, movex) && map[movey][movex] != 0 && check[movey][movex] == 0) {
				check[movey][movex] = 1;
				q.push(make_pair(movex, movey));
			}
		}
	}
}

int cnt_island() {
	int cnt = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] != 0 && check[i][j] == 0) {
				cnt++;
				check[i][j] = 1;
				cnt_island(i, j);
			}
		}
	}
	return cnt;
}

void melt(int y, int x) {
	int cnt_water = 0;
	for (int i = 0; i < 4; i++) {
		int movex = x + dirX[i];
		int movey = y + dirY[i];
		if (valid(movey, movex) && map[movey][movex] == 0)
			cnt_water++;
	}
	int num = map[y][x] - cnt_water;
	if (num < 0)
		num = 0;
	cmap[y][x] = num;
}

void copy_map() {
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			map[i][j] = cmap[i][j];
		}
	}
}

int main() {
	input();

	int island;

	while (1) {
		island = cnt_island();
		if (island == 0 || island > 1)
			break;
		else {
			for (int i = 0; i < col; i++) {
				for (int j = 0; j < row; j++) {
					if (map[i][j] != 0) {
						melt(i, j);
					}
				}
			}
		}
		cnt_year++;
		copy_map();
		clear();
	}
	if (island == 0)
		cout << 0 << "\n";
	else cout << cnt_year << "\n";
}