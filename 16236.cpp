#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
int shark_size = 2;
int eat_fish = 0;
int shark_x, shark_y;
int map[21][21];
bool check[21][21];
int n;
int t = 0;

bool in_map(int y, int x) {
	if (y > 0 && x > 0 && x <= n && y <= n)
		return true;
	else return false;
}
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark_y = i;
				shark_x = j;
				map[i][j] = 0;
			}
		}
	}
}
void clear_check() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			check[i][j] = false;
		}
	}
}
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first <= b.first) {
		if (a.first == b.first) {
			if (a.second < b.second)
				return true;
			else return false;
		}
		return true;
	}
	return false;
}
int find_fish() {
	queue<pair<pair<int, int>, int>> q; 
	vector<pair<int, int>> tmp;
	q.push(make_pair(make_pair(shark_y, shark_x), 0));
	check[shark_y][shark_x] = true;
	int min_dist = 401;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (map[y][x] > 0 && map[y][x] < 7 && min_dist >= cnt && shark_size > map[y][x]) {
			min_dist = cnt;
			tmp.push_back(make_pair(y, x));
		}
		for (int i = 0; i < 4; i++) {
			int movex = x + dirX[i];
			int movey = y + dirY[i];
			if (in_map(movey, movex) && !check[movey][movex] && shark_size >= map[movey][movex]) {
				check[movey][movex] = true;
				q.push(make_pair(make_pair(movey, movex), cnt + 1));
			}
		}
	}
	if (tmp.size() == 0) { return 0; }
	else {
		t += min_dist;
		sort(tmp.begin(), tmp.end(), cmp);
		map[tmp[0].first][tmp[0].second] = 0;
		shark_x = tmp[0].second;
		shark_y = tmp[0].first;
		eat_fish++;
		return 1;
	}
}
int main() {
	input();
	while (1) {
		clear_check();
		int tmp = find_fish(); //자기보다 작은 물고기 찾기, 가장 가까운거 찾기
		if (tmp == 0)
			break;
		if (eat_fish == shark_size) {
			shark_size++;
			eat_fish = 0;
		}
	}
	cout << t;
}