#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dirx[4] = { 1,0,-1,0 };
int diry[4] = { 0,1,0,-1 };
int n, max_height = -1, min_height = 101, answer = 0;
int map[101][101];
bool visit[101][101];
void clear_map() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visit[i][j] = false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			min_height = min(min_height, map[i][j]);
			max_height = max(max_height, map[i][j]);
		}

	for (int i = min_height-1; i <= max_height; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!visit[j][k] && map[j][k] > i) {
					cnt++;
					visit[j][k] = true;
					queue<pair<int, int>> q;
					q.push({ j,k });
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						for (int a = 0; a < 4; a++) {
							int movey = y + diry[a], movex = x + dirx[a];
							if (movey >= 0 && movex >= 0 && movey < n && movex < n && map[movey][movex] > i && !visit[movey][movex]) {
								visit[movey][movex] = true;
								q.push({ movey, movex });
							}
						}
					}
				}
			}
		}
		answer = max(answer, cnt);
		clear_map();
	}
	cout << answer;
}