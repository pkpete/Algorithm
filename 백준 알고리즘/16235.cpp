#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[11][11];
int nutrition[11][11];
vector<int> tree_map[11][11];
int map_size, m, year;
int dirX[8] = { 0,1,1,1,0,-1,-1,-1 };
int dirY[8] = { -1,-1,0,1,1,1,0,-1 };

void input() {
	cin >> map_size >> m >> year;
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			cin >> nutrition[i][j];
			map[i][j] = 5;	// 처음 양분은 5
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> y >> x >> z;
		tree_map[y][x].push_back(z);
	}
}

bool in_map(int y, int x) {
	if (y > 0 && x > 0 && x <= map_size && y <= map_size)
		return true;
	else return false;
}

void winter() {
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			map[i][j] = map[i][j] + nutrition[i][j];
		}
	}
}

void spring_summer() {
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			vector<int> tmp;
			int dead = 0;
			if (tree_map[i][j].size() > 0) {
				sort(tree_map[i][j].begin(), tree_map[i][j].end());
				for (int k = 0; k < tree_map[i][j].size(); k++) {
					if (map[i][j] >= tree_map[i][j][k]) {
						map[i][j] -= tree_map[i][j][k];
						tmp.push_back(tree_map[i][j][k]+1);
					}
					else {
						dead += (tree_map[i][j][k] / 2);
					}
				}
				tree_map[i][j].clear();
				for (int k = 0; k < tmp.size(); k++) {
					tree_map[i][j].push_back(tmp[k]);
				}
				map[i][j] += dead;
			}
		}
	}
}

void fall() {
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			if (tree_map[i][j].size() > 0) {
				for (int k = 0; k < tree_map[i][j].size(); k++) {
					if (tree_map[i][j][k] % 5 == 0) {
						for (int l = 0; l < 8; l++) {
							int mx = j + dirX[l];
							int my = i + dirY[l];
							if (in_map(my, mx)) {
								tree_map[my][mx].push_back(1);
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	while (year > 0) {
		spring_summer();
		fall();
		winter();
		year--;
	}

	int cnt = 0;
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			cnt += tree_map[i][j].size();
		}
	}
	cout << cnt << "\n";
}