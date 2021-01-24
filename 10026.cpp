#include <iostream>
#include <queue>
using namespace std;

int n, check[101][101];
char map[101][101], cmap[101][101];
int dirI[4] = { 0,0,1,-1 };
int dirJ[4] = { 1,-1,0,0 };
int cntNormal = 0, cntEye = 0;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				cmap[i][j] = 'G';
			}
			else
				cmap[i][j] = map[i][j];
		}
}
void DFS(int row, int collumn, int num) {
	if (num == 0) {
		char temp = map[row][collumn];
		for (int i = 0; i < 4; i++) {
			int moveI = row + dirI[i];
			int moveJ = collumn + dirJ[i];
			if (map[moveI][moveJ] == temp && check[moveI][moveJ] == 0 && moveI > 0 && moveJ > 0 && moveI <= n && moveJ <= n) {
				check[moveI][moveJ] = 1;
				DFS(moveI, moveJ, num);
			}
		}
	}
	else {
		char temp = cmap[row][collumn];
		for (int i = 0; i < 4; i++) {
			int moveI = row + dirI[i];
			int moveJ = collumn + dirJ[i];
			if (cmap[moveI][moveJ] == temp && check[moveI][moveJ] == 0 && moveI > 0 && moveJ > 0 && moveI <= n && moveJ <= n) {
				check[moveI][moveJ] = 1;
				DFS(moveI, moveJ, num);
			}
		}
	}
}
void normalEye() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check[i][j] == 0) {
				check[i][j] = 1;
				DFS(i, j, 0);
				cntNormal++;
			}
		}
	}
}

void redEye() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check[i][j] == 0) {
				check[i][j] = 1;
				DFS(i, j, 1);
				cntEye++;
			}
		}
	}
}

void reset() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			check[i][j] = 0;
}
int main() {

	input();

	normalEye();

	reset();

	redEye();

	cout << cntNormal << " " << cntEye;
}