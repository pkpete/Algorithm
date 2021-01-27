#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
int map[51][51];
int cmap[51][51];
bool check[51][51];
int n, l, r, cnt_break, answer = 0;
void input() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			cmap[i][j] = map[i][j];
		}
	}
}

bool valid(int y, int x) {
	if (y >= 0 && x >= 0 && x < n && y < n)
		return true;
	else return false;
}

void bfs(int y, int x) {
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int sum = 0;
	bool no_move = true;
	while (!q.empty()) {
		int currentx = q.front().first;
		int currenty = q.front().second;
		int current_num = map[currenty][currentx];
		q.pop();
		v.push_back(make_pair(currentx, currenty));
		sum += current_num;
		for (int i = 0; i < 4; i++) {
			int movex = currentx + dirX[i];
			int movey = currenty + dirY[i];
			int move_num = map[movey][movex];
			int num = abs(current_num - move_num);
			if (valid(movey, movex) && num >= l && num <= r && !check[movey][movex]) {
				check[movey][movex] = true;
				q.push(make_pair(movex, movey));
				no_move = false;
			}
		}
	}
	if (no_move) {
		cnt_break++;
	}
	int num = sum / v.size();
	for (int i = 0; i < v.size(); i++) {
		cmap[v[i].second][v[i].first] = num;
	}
}

void clear_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
			map[i][j] = cmap[i][j];
		}
	}
}

int main() {
	input();
	while (1) {
		cnt_break = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					check[i][j] = true;
					bfs(i, j);
				}
			}
		}
		if (cnt_break == n*n)
			break;
		clear_map();
		answer++;
	}
	cout << answer;
}