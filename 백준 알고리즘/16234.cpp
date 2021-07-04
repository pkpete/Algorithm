#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int n, l, r;
int map[50][50];
bool check_map[50][50];
int cnt = 0;

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

void clear() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			check_map[i][j] = false;
}
bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check_map[i][j])
				return true;
		}
	}
	return false;
}
bool in_map(int y, int x) {
	if (y >= 0 && x >= 0 && y < n && x < n)
		return true;
	return false;
}

void bfs(int y, int x) {
	
	vector<pair<int, int>> country;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int cury = q.front().first;
		int curx = q.front().second;
		check_map[cury][curx] = true;
		int ppl = map[cury][curx];
		country.push_back(make_pair(cury, curx));
		q.pop();

		for (int i = 0; i < 4; i++) {
			int movey = cury + dirY[i];
			int movex = curx + dirX[i];
			int move_ppl = map[movey][movex];
			if (in_map(movey, movex) && !check_map[movey][movex]) {
				if (abs(move_ppl - ppl) >= l && abs(move_ppl - ppl) <= r) {
					check_map[movey][movex] = true;
					q.push(make_pair(movey, movex));
				}
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < country.size(); i++) {
		sum += map[country[i].first][country[i].second];
	}

	int num = sum / country.size();

	for (int i = 0; i < country.size(); i++) {
		map[country[i].first][country[i].second] = num;
	}

	if (country.size() == 1)
		check_map[y][x] = false;
}

int main() {

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(!check_map[i][j])
					bfs(i, j);
			}
		}

		if (!check())
			break;

		clear();
		cnt++;
	}

	cout << cnt;

}