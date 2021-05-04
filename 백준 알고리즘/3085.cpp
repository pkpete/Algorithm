#include <iostream>
#include <algorithm>
using namespace std;
char map[51][51];	// °íÁ¤
char cmap[51][51];
bool check[51][51];
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
int n, answer = 0;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j];
			cmap[i][j] = map[i][j];
		}
	}
}

bool in_map(int y, int x) {
	if (y >= 0 && x >= 0 && y < n && x < n)
		return true;
	else return false;
}

void count_candy() {
	// count row
	for (int i = 0; i < n; i++) {
		char before = map[i][0];
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (map[i][j] == before) {
				cnt++;
			}
			else {
				before = map[i][j];
				cnt = 1;
			}
			answer = max(answer, cnt);
		}
	}

	for (int i = 0; i < n; i++) {
		char before = map[0][i];
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (map[j][i] == before) {
				cnt++;
			}
			else {
				before = map[j][i];
				cnt = 1;
			}
			answer = max(answer, cnt);
		}
	}
}

void swap_candy(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int movex = x + dirX[i];
		int movey = y + dirY[i];
		if (in_map(movey, movex) && !check[movey][movex] && map[y][x] != map[movey][movex]) {
			swap(map[y][x], map[movey][movex]);
			count_candy();
			swap(map[y][x], map[movey][movex]);
		}
	}
}

int main() {
	input();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			swap_candy(i, j);
			check[i][j] = true;
		}
	}
	cout << answer;
}