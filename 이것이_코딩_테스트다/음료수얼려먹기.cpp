#include <iostream>
#include <queue>
using namespace std;
int n, m;
int map[1001][1001];
int dirx[4] = { 0,1,0,-1 };
int diry[4] = { -1,0,1,0 };

int main() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j]-'0';
		}
	}
	int cnt = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cnt++;
				map[i][j] = 1;
				q.push({ i,j });
				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int movey = y + diry[i];
						int movex = x + dirx[i];
						if (movey >= 0 && movex >= 0 && movey < n && movex < m && map[movey][movex] == 0) {
							q.push({ movey,movex });
							map[movey][movex] = 1;
						}
					}
				}
			}
		}
	}

	cout << cnt;
}