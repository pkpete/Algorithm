#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, answer = -1;
int map[21][21], cmap[21][21];
int direction[5];	
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}
void set_cmap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cmap[i][j] = map[i][j];
		}
	}
}
void find_biggest_block() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(cmap[i][j], answer);
		}
	}
}
void move_cmap() {
	for (int i = 0; i < 5; i++) {
		int dir = direction[i];
		if (dir == 0) {	//왼쪽
			for (int j = 0; j < n; j++) {
				queue<int> q;
				for (int k = 0; k < n; k++) {
					if (cmap[j][k] != 0) {
						q.push(cmap[j][k]);
						cmap[j][k] = 0;
					}
				}
				int index = 0;
				while (!q.empty()) {
					int num = q.front();
					q.pop();
					if (cmap[j][index] == 0) {
						cmap[j][index] = num;
					}
					else if (cmap[j][index] == num) {
						cmap[j][index] *= 2;
						index++;
					}
					else {
						index++;
						cmap[j][index] = num;
					}
				}
			}
		}
		else if (dir == 1) {	//오른쪽
			for (int j = 0; j < n; j++) {
				queue<int> q;
				for (int k = n - 1; k >= 0; k--) {
					if (cmap[j][k] != 0) {
						q.push(cmap[j][k]);
						cmap[j][k] = 0;
					}
				}
				int index = n - 1;
				while (!q.empty()) {
					int num = q.front();
					q.pop();
					if (cmap[j][index] == 0) {
						cmap[j][index] = num;
					}
					else if (cmap[j][index] == num) {
						cmap[j][index] *= 2;
						index--;
					}
					else {
						index--;
						cmap[j][index] = num;
					}
				}
			}
		}
		else if (dir == 2) {	// 위쪽
			for (int j = 0; j < n; j++) {
				queue<int> q;
				for (int k = 0; k < n; k++) {
					if (cmap[k][j] != 0) {
						q.push(cmap[k][j]);
						cmap[k][j] = 0;
					}
				}
				int index = 0;
				while (!q.empty()) {
					int num = q.front();
					q.pop();
					if (cmap[index][j] == 0) {
						cmap[index][j] = num;
					}
					else if (cmap[index][j] == num) {
						cmap[index][j] *= 2;
						index++;
					}
					else {
						index++;
						cmap[index][j] = num;
					}
				}
			}
		}
		else if (dir == 3) {	// 아래쪽
			for (int j = 0; j < n; j++) {
				queue<int> q;
				for (int k = n - 1; k >= 0; k--) {
					if (cmap[k][j] != 0) {
						q.push(cmap[k][j]);
						cmap[k][j] = 0;
					}
				}
				int index = n - 1;
				while (!q.empty()) {
					int num = q.front();
					q.pop();
					if (cmap[index][j] == 0) {
						cmap[index][j] = num;
					}
					else if (cmap[index][j] == num) {
						cmap[index][j] *= 2;
						index--;
					}
					else {
						index--;
						cmap[index][j] = num;
					}
				}
			}
		}
		/*cout << endl;
		cout << dir << endl;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cout << cmap[j][k] << " ";
			}
			cout << endl;
		}*/
	}
}
void move_block(int cnt) {
	if (cnt == 5) {
		set_cmap();
		move_cmap();
		find_biggest_block();
		return;
	}
	for (int i = 0; i < 4; i++) {
		direction[cnt] = i;
		move_block(cnt + 1);
	}
}
int main() {
	input();
	move_block(0);
	cout << answer << "\n";
}