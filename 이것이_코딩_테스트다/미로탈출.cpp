#include <iostream>
#include <queue>
using namespace std;
int n, m;
int dirx[4] = { 0,1,0,-1 };
int diry[4] = { -1,0,1,0 }; 
int map[201][201];
int main() {
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == n-1 && x == m-1) break;
		for (int i = 0; i < 4; i++) {
			int movey = y + diry[i], movex = x + dirx[i];
			if (movey >= 0 && movex >= 0 && movey < n && movex < m && map[movey][movex] == 1) {
				q.push({ movey,movex });
				map[movey][movex] = map[y][x] + 1;
			}	
		}
	}

	cout << map[n-1][m-1];

}