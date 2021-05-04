#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int map[51][51], cmap[51][51];
bool visit[51][51];
int n, m;
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
int answer = 1000000000;
vector<pair<int, int>> virus;
int select_virus[10];
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));
		}
	}
}

void set_cmap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
			cmap[i][j] = map[i][j];
		}
	}
}
bool in_map(int y, int x) {
	if (y >= 0 && x >= 0 && x < n && y < n)
		return true;
	else return false;
}
void spread_virus() {
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < m; i++) {
		visit[virus[select_virus[i]].first][virus[select_virus[i]].second] = true;
		q.push(make_pair(make_pair(virus[select_virus[i]].first, virus[select_virus[i]].second), 0));
	}
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int movex = x + dirX[i];
			int movey = y + dirY[i];
			if (in_map(movey, movex) && map[movey][movex] != 1 && !visit[movey][movex]) {
				visit[movey][movex] = true;
				cmap[movey][movex] = cnt + 1;
				q.push(make_pair(make_pair(movey, movex), cnt+1));
			}
		}
	}
}
int count_time() {
	int t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && cmap[i][j] == 0)
				return -1;
			if (map[i][j] == 0 && t < cmap[i][j])
				t = cmap[i][j];
		}
	}
	return t;
}

void choose_virus(int index, int cnt) {
	if (cnt == m) {
		set_cmap();
		spread_virus();	
		int t = count_time();
		if (t != -1 && answer > t)
			answer = t;
	}
	else {
		for (int i = index; i < virus.size(); i++) {
			select_virus[cnt] = i;
			choose_virus(i + 1, cnt + 1);
		}
	}
}
int main() {
	input();
	choose_virus(0,0);
	if (answer == 1000000000)
		cout << -1;
	else cout << answer;
}