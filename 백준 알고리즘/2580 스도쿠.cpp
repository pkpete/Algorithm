#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> zero;
int map[10][10];

bool check(int y, int x, int num) {
	bool check_num[10];
	for (int i = 0; i < 10; i++)
		check_num[i] = false;

	for (int i = 0; i < 9; i++) {
		check_num[map[y][i]] = true;
		check_num[map[i][x]] = true;
	}

	int row = (x / 3) * 3;
	int col = (y / 3) * 3;
	for (int i = col; i < col + 3; i++) {
		for (int j = row; j < row + 3; j++) {
			check_num[map[i][j]] = true;
		}
	}
	if (!check_num[num]) return true;
	return false;
}

void sudoku(int cnt) {
	if (cnt == zero.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	int y = zero[cnt].first;
	int x = zero[cnt].second;
	for (int i = 0; i < 10; i++) {
		if (check(y, x, i)) {
			map[y][x] = i;
			sudoku(cnt + 1);
			map[y][x] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				zero.push_back(make_pair(i, j));
			}
		}
	}
	sudoku(0);
}
