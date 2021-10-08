#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };
char map[1001][1001];
bool visit[1001][1001];
int w, h, tc, py, px;
bool fin;
deque<pair<int, int>> fire;
deque<pair<int, int>> position;

void clear_map() {
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			visit[i][j] = false;
}

bool in_map(int y, int x) {
	if (0 <= y && 0 <= x && y < h && x < w) return true;
	return false;
}

void input() {
	cin >> w >> h;
	string str;
	for (int i = 0; i < h; i++) {
		cin >> str;
		for (int j = 0; j < w; j++) {
			map[i][j] = str[j];
			if (str[j] == '*') {
				fire.push_back({ i,j });
			}
			else if (str[j] == '@') {
				visit[i][j] = true;
				position.push_back({ i,j });
			}
		}
	}
}

void spread_fire() {
	int l = fire.size();
	for (int i = 0; i < l; i++) {
		int cury = fire[0].first;
		int curx = fire[0].second;
		fire.pop_front();

		for (int j = 0; j < 4; j++) {
			int movey = cury + dirY[j], movex = curx + dirX[j];
			if (in_map(movey, movex) && map[movey][movex] != '#' && map[movey][movex] != '*') {
				map[movey][movex] = '*';
				fire.push_back({ movey,movex });
			}
		}
	}
}

void move_ppl() {
	int l = position.size();
	for (int i = 0; i < l; i++) {
		int cury = position[0].first;
		int curx = position[0].second;
		position.pop_front();

		for (int j = 0; j < 4; j++) {
			int movey = cury + dirY[j], movex = curx + dirX[j];
			if (in_map(movey, movex) && map[movey][movex] == '.' && !visit[movey][movex]) {
				visit[movey][movex] = true;
				position.push_back({ movey,movex });
			}
			if (!in_map(movey, movex)) {
				fin = true;
			}
		}
	}
}

int main() {
	cin >> tc;
	while (tc--) {
		input();
		clear_map();
		int cnt = 0;
		fin = false;
		while (1) {
			cnt++;
			spread_fire();
			move_ppl();
			if (fin) {
				cout << cnt << "\n";
				break;
			}
			if (position.empty()) {
				cout << "IMPOSSIBLE\n";
				break;
			}
		}
		fire.clear();
		position.clear();
	}
}