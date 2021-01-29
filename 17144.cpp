#include <iostream>
#include <vector>

using namespace std;

int col, row, t, map[51][51], cmap[51][51];
int ans = 0;
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
vector<pair<int, int>> aircon;	// 공기 청정기 좌표 (y, x)

void input() {
	cin >> col >> row >> t;
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				aircon.push_back(make_pair(i, j));
				cmap[i][j] = map[i][j];
			}
		}
	}
}

void cnt_dust() {
	for (int i = 1; i <= col; i++)
		for (int j = 1; j <= row; j++)
			if (map[i][j] > 0)
				ans += map[i][j];
}

void copy_map() {
	for (int i = 1; i <= col; i++)
		for (int j = 1; j <= row; j++) {
			map[i][j] = cmap[i][j];
			if (cmap[i][j] != -1)
				cmap[i][j] = 0; // cmap초기화
		}
}

bool in_map(int y, int x) {
	if (y > 0 && x > 0 && x <= row && y <= col)
		return true;
	else return false;
}

void spread_dust(int y, int x) {
	int narea = 0;
	for (int i = 0; i < 4; i++) {
		int movex = x + dirX[i];
		int movey = y + dirY[i];
		if (in_map(movey, movex) && map[movey][movex] != -1) {
			narea++;
			cmap[movey][movex] = cmap[movey][movex] + (map[y][x] / 5);
		}
	}
	cmap[y][x] = cmap[y][x] + (map[y][x] - ((map[y][x] / 5) * narea));
}

void start_aircon(int y, int x, int index) {
	if (index == 0) {	//반시계
		for (int i = 1; i <= y; i++) {
			for (int j = 1; j <= row; j++) {
				if (map[i][j] != -1) {
					if (j == 1) {
						if (i + 1 != y)
							cmap[i + 1][j] = map[i][j];	// 아래로
					}
					else if (i == 1)
						cmap[i][j - 1] = map[i][j]; // 왼쪽으로
					else if (j == row)
						cmap[i - 1][j] = map[i][j];	//위로
					else if (i == y)
						cmap[i][j + 1] = map[i][j];	//오른쪽으로
					else
						cmap[i][j] = map[i][j];
				}
			}
		}
	}
	else {	//시계
		for (int i = col; i >= y; i--) {
			for (int j = 1; j <= row; j++) {
				if (map[i][j] != -1) {
					if (j == 1) {
						if (i - 1 != y)
							cmap[i - 1][j] = map[i][j];	//위로
					}
					else if (i == col)
						cmap[i][j - 1] = map[i][j];	// 왼쪽으로
					else if (j == row)
						cmap[i + 1][j] = map[i][j];	//아래로
					else if (i == y)
						cmap[i][j + 1] = map[i][j];	//오른쪽으로
					else
						cmap[i][j] = map[i][j];
				}
			}
		}
	}
}

int main() {

	input();

	while (1) {
		if (t == 0)	
			break;
		//미세먼지 확산
		for (int i = 1; i <= col; i++) {
			for (int j = 1; j <= row; j++) {
				if (map[i][j] > 0) {
					spread_dust(i,j);
				}
			}
		}
		copy_map();

		// 공기청정기 작동
		for (int i = 0; i < aircon.size(); i++) {
			start_aircon(aircon[i].first, aircon[i].second, i);	//에어컨 위치 좌표
		}
		copy_map();
		t--;
	}

	cnt_dust();

	cout << ans << "\n";
}