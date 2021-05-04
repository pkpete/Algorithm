#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];
int col_size, row_size, k;
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
int cnt;
vector<int> area;

void input() {
	cin >> col_size >> row_size >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = col_size - y2; i < col_size - y1; i++) {
			for (int j = x1; j < x2; j++) {
				map[i][j] = -1;
			}
		}
	}
}

void dfs(int y, int x) {
	cnt++;
	for (int i = 0; i < 4; i++) {
		int movex = x + dirX[i];
		int movey = y + dirY[i];
		if (movex >= 0 && movey >= 0 && movex < row_size && movey < col_size && map[movey][movex] == 0) {
			map[movey][movex] = 1;
			dfs(movey, movex);
		}
	}
}

int main() {
	input();
	int cnt_area = 0;
	for (int i = 0; i < col_size; i++) {
		for (int j = 0; j < row_size; j++) {
			if (map[i][j] == 0) {
				cnt_area++;
				cnt = 0;
				map[i][j] = 1;
				dfs(i, j);
				area.push_back(cnt);
			}
		}
	}
	sort(area.begin(), area.end());
	cout << cnt_area << "\n";
	for (int i = 0; i < area.size(); i++)
		cout << area[i] << " ";
}