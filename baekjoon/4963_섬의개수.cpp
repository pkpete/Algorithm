#include <iostream>
#include <queue>
using namespace std;
int dirx[8] = { 1,1,0,-1,-1,-1,0,1 };
int diry[8] = { 0,1,1,1,0,-1,-1,-1 };
int map[51][51];
bool visit[51][51];
int main() {
	while (1) {
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visit[i][j]) {
					cnt++;
					visit[i][j] = true;
					queue<pair<int, int>> q;
					q.push({ i,j });
					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						for (int k = 0; k < 8; k++) {
							int movey = y + diry[k], movex = x + dirx[k];
							if (movey >= 0 && movex >= 0 && movey < h && movex < w && !visit[movey][movex] && map[movey][movex] == 1) {
								visit[movey][movex] = true;
								q.push({ movey,movex });
							}
						}
					}
				}
			}
		}
		cout << cnt << "\n";
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				visit[i][j] = false;

	}
}