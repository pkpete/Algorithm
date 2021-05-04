#include <iostream>
using namespace std;
int map[21][21];
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
int check[26];
int col_size, row_size;
int answer = -1;
void input() {
	//A 17 Z 42
	string str;
	cin >> col_size >> row_size;
	for (int i = 1; i <= col_size; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			map[i][j + 1] = (str[j] - '0') - 17;
		}
	}
}

bool in_map(int y, int x) {
	if (y > 0 && x > 0 && x <= row_size && y <= col_size)
		return true;
	else return false;
}

void dfs(int y, int x, int cnt) {
	if (cnt > answer)
		answer = cnt;

	for (int i = 0; i < 4; i++) {
		int movex = x + dirX[i];
		int movey = y + dirY[i];
		if (in_map(movey, movex) && check[map[movey][movex]] == 0) {
			check[map[movey][movex]] = 1;
			dfs(movey, movex, cnt + 1);
			check[map[movey][movex]] = 0;
		}
	}
}

int main() {
	input();

	check[map[1][1]] = 1;
	dfs(1, 1, 1);

	cout << answer;
}