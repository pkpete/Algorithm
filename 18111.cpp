#include <iostream>
#include <algorithm>
using namespace std;
int map[501][501];
int check[501][501];
int n, m, b;
int make_flat(int floor) {
	int build = 0, remove = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int height = map[i][j] - floor;
			if (height > 0) remove += height;
			else if (height < 0) build -= height;
		}
	}
	int cnt = -1;
	if (remove + b >= build) {
		cnt = remove * 2 + build;
	}
	
	return cnt;
}
int main() {
	int min_num = 1000000000, max_num = -1;
	int time = 1000000000, floor;
	cin >> n >> m >> b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= 256; i++) {
		int tmp = make_flat(i);
		if (tmp != -1 && tmp <= time) {
			time = tmp;
			floor = i;
		}
	}
	
	cout << time << " " << floor;
}