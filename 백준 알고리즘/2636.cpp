#include <iostream>
#include <queue>
using namespace std;
int map[101][101];
bool visit[101][101];
int col, row;
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
void input() {
	cin >> col >> row;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin >> map[i][j];
		}
	}
}

bool in_map(int y, int x) {
	if (y >= 0 && x >= 0 && y < col && x < row)
		return true;
	else return false;
}

void spread_air() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visit[0][0] = true;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int movex = x + dirX[i];
			int movey = y + dirY[i];
			if (in_map(movey, movex) && map[movey][movex] != 1 && !visit[movey][movex]) {
				visit[movey][movex] = true;
				q.push(make_pair(movey, movex));
			}
			else if (map[movey][movex] == 1) {
				map[movey][movex] = 0;
				visit[movey][movex] = true;
			}
		}
	}
}

void clear_visit() {
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			visit[i][j] = false;
}

int cnt_cheeze() {
	int cnt = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] == 1)
				cnt++;
		}
	}
	return cnt;
}

int main() {
	input();

	int time = 0, cnt_size;

	while (1) {
		int ncheeze = cnt_cheeze();
		if (ncheeze == 0) 
			break;

		spread_air();

		clear_visit();
		cnt_size = ncheeze;
		time++;
	}
	cout << time << "\n" << cnt_size << "\n";
}