#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.first <= b.first.first) {
		if (a.first.first == b.first.first) {
			if (a.first.second < b.first.second) {
				return true;
			}
			else return false;
		}
		else return true;
	}
	else return false;
}
int n, m, gas, current_x, current_y;
int map[21][21];
bool check[21][21];
int cnt = 0;
vector<pair<int, int>> destination;

void clear_check() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			check[i][j] = false;
		}
	}
}

bool in_map(int y, int x) {
	if (y > 0 && x > 0 && y <= n && x <= n)
		return true;
	else return false;
}

void input() {
	cin >> n >> m >> gas;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				map[i][j] = -1;
		}
	}
	cin >> current_y >> current_x;

	for (int i = 1; i <= m; i++) {
		int startx, starty, endx, endy;
		cin >> starty >> startx >> endy >> endx;
		map[starty][startx] = i;
		destination.push_back(make_pair(endy, endx));
	}
}

int to_destination(int num) {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(current_y, current_x), 0));
	int distx = destination[num].second;
	int disty = destination[num].first;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int move = q.front().second;
		q.pop();
		if (y == disty && x == distx) {	// µµÂøÁö
			if (gas < move) {
				return -1;
			}
			else {
				gas += move;
				current_x = x;
				current_y = y;
				return 1;
			}
		}
		for (int i = 0; i < 4; i++) {
			int movex = x + dirX[i];
			int movey = y + dirY[i];
			if (in_map(movey, movex) && !check[movey][movex] && map[movey][movex] != -1) {
				check[movey][movex] = true;
				q.push(make_pair(make_pair(movey, movex), move + 1));
			}
		}
	}
	return -1;
}

int find_client() {
	vector<pair<pair<int, int>, int>> tmp;
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(current_y, current_x), 0));
	int min_dist = 400;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int move = q.front().second;
		q.pop();
		if (move > min_dist) break;
		if (map[y][x] > 0 && min_dist >= move) {
			if (gas < move)
				return -1;
			min_dist = move;
			tmp.push_back(make_pair(make_pair(y, x), map[y][x]));
		}
		for (int i = 0; i < 4; i++) {
			int movex = x + dirX[i];
			int movey = y + dirY[i];
			if (in_map(movey, movex) && !check[movey][movex] && map[movey][movex] != -1) {
				check[movey][movex] = true;
				q.push(make_pair(make_pair(movey, movex), move + 1));
			}
		}
	}
	if (tmp.size() == 0) return -1;
	else {
		sort(tmp.begin(), tmp.end(), cmp);
		map[tmp[0].first.first][tmp[0].first.second] = 0;
		current_y = tmp[0].first.first;
		current_x = tmp[0].first.second;
		gas -= min_dist;
		return tmp[0].second - 1;
	}
}

int main() {
	input();

	while (1) {
		if (cnt == m) break;

		check[current_y][current_x] = true;

		int num = find_client();

		clear_check();

		if (num == -1) {
			cout << -1;
			return 0;
		}
		else {
			check[current_y][current_x] = true;
			int tmp = to_destination(num);
			if (tmp == -1) {
				cout << -1;
				return 0;
			}
			else
				cnt++;
		}

		clear_check();
	}
	cout << gas << "\n";
}	