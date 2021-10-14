#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000;
int map[101][101];
int n, m, arrive, visit;	//회사 개수, 경로 개수, 도착지, 방문지
int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			map[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	cin >> arrive >> visit;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}
	if (map[1][visit] + map[visit][arrive] >= INF) cout << -1;
	else cout << map[1][visit] + map[visit][arrive];

}