#include <iostream>
#include <vector>
using namespace std;
int map[101][101];
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,-1,0,1 };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<int> dir;
		dir.push_back(d);
		for (int j = 0; j < g; j++) {
			vector<int> tmp = dir;
			for (int k = tmp.size() - 1; k >= 0; k--) {
				dir.push_back((tmp[k] + 1) % 4);
			}
		}
		map[y][x] = 1;
		for (int j = 0; j < dir.size(); j++) {
			x += dirX[dir[j]];
			y += dirY[dir[j]];
			if (x >= 0 && y >= 0 && x < 101 && y < 101)
				map[y][x] = 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (map[i][j] && map[i][j + 1] && map[i - 1][j] && map[i - 1][j + 1]) {
				cnt++;
			}
		}
	}
	cout << cnt;
}