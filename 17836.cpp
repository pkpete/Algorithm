#include <iostream>
#include <queue>
using namespace std;
int map[102][102];
int check[102][102][2];	//0Àº ¸¶¹ýºÀ ¹ÌÈ¹µæ / 1Àº ¸¶¹ýºÀ È¹µæ
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };
int col_size, row_size, t, magicy, magicx;
queue<pair<pair<int, int>, int>> q;

void input() {
	cin >> col_size >> row_size >> t;
	for (int i = 1; i <= col_size; i++) {
		for (int j = 1; j <= row_size; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				magicy = i;
				magicx = j;
			}
		}
	}
}

int main() {
	input();
	q.push(make_pair(make_pair(1, 1), 0));
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int type = q.front().second;
		q.pop();

		if (x == row_size && y == col_size) {
			if (check[y][x][type] <= t)
				cout << check[y][x][type] << "\n";
			else
				cout << "Fail" << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int movex = x + dirX[i];
			int movey = y + dirY[i];
			if (movex > 0 && movey > 0 && movex <= row_size && movey <= col_size) {
				if (type == 0 && map[movey][movex] != 1 && check[movey][movex][0] == 0) {
					if (movey == magicy && movex == magicx) {
						check[movey][movex][1] = check[y][x][0] + 1;
						q.push(make_pair(make_pair(movex, movey), 1));
					}
					else {
						check[movey][movex][0] = check[y][x][0] + 1;
						q.push(make_pair(make_pair(movex, movey), 0));
					}
				}
				else if (type == 1 && check[movey][movex][1] == 0) {
					check[movey][movex][1] = check[y][x][1] + 1;
					q.push(make_pair(make_pair(movex, movey), 1));
				}
			}
		}
	}
	cout << "Fail" << "\n";
}