#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// �Է� �޴� �κ�
// ����
// �δ����� �������� ������� Ȯ��
// �� ���� ��� �ִ��� Ȯ��
// Ž��
	// �δ����� �̵���Ŵ : �ֺ��� ��ĭ�� : BFS
		// �� �����̰� ������ �ȵ�
		// �������� ���� �� �����̸� �ȵ�
		// ������ �̵��� �������� ��
	// ���� �̵�
		// �ֺ��� ��ĭ�� �̵�
// �������
	// �δ����� �̵��Ҷ� ������ ���� ���� ������ ��� Ȯ��??

string map[52][52];
bool check[52][52];
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };
int r, c;
queue<pair<int, int>> water;

bool in_map(int y, int x) {
	if (y >= 0 && x >= 0 && y < r && x < c)
		return true;
	return false;
}

int main() {
	cin >> r >> c;
	int cury, curx;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			map[i][j] = str[j];
			if (map[i][j] == "S") {
				cury = i;
				curx = j;
			}
			else if (map[i][j] == "*") {
				water.push(make_pair(i, j));
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(cury, curx));
	check[cury][curx] = true;
	int cnt = 0;
	while (!q.empty()) {

		int water_size = water.size();
		// ��
		for (int i = 0; i < water_size; i++) {
			int y = water.front().first;
			int x = water.front().second;
			water.pop();
			for (int j = 0; j < 4; j++) {
				int movey = y + dirY[j];
				int movex = x + dirX[j];
				if (in_map(movey, movex) && map[movey][movex] == ".") {
					map[movey][movex] = "*";
					water.push(make_pair(movey, movex));
				}
			}
		}

		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int y = q.front().first;
			int x = q.front().second;
			if (map[y][x] == "D") {
				cout << cnt;
				return 0;
			}
			q.pop();
			for (int j = 0; j < 4; j++) {
				int movey = y + dirY[j];
				int movex = x + dirX[j];
				if (in_map(movey, movex) && map[movey][movex] != "*" && map[movey][movex] != "X" && !check[movey][movex]) {
					check[movey][movex] = true;
					q.push(make_pair(movey, movex));
				}
			}
		}
		cnt++;
	}

	cout << "KAKTUS";

}