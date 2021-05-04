#include <iostream>
#include <string>
#include <queue>

using namespace std;

int col, row;
int map[51][51];
bool visit[51][51];
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
int answer = -1;

void input() {
	cin >> col >> row;
	for (int i = 0; i < col; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < row; j++) {
			if (str[j] == 'W') {
				map[i][j] = 0;
			}
			else if (str[j] == 'L') {
				map[i][j] = 1;	//À°Áö
			}
		}
	}
}

void clear_map() {
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			visit[i][j] = false;
		}
	}
}

bool in_map(int y, int x) {
	if (y >= 0 && x >= 0 && x < row && y < col)
		return true;
	else return false;
}

void bfs(int y, int x) {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(y, x), 0));
	while (!q.empty()) {
		int cx = q.front().first.second;
		int cy = q.front().first.first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mx = cx + dirX[i];
			int my = cy + dirY[i];
			if (in_map(my, mx) && map[my][mx] == 1 && !visit[my][mx] ) {
				visit[my][mx] = true;
				q.push(make_pair(make_pair(my, mx), cnt+1));
			}
		}
		if (answer < cnt) {
			answer = cnt;
		}
	}
}

int main() {
	input();

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] == 1) {
				visit[i][j] = true;
				bfs(i, j);
				clear_map();
			}
		}
	}
	cout << answer << "\n";
}