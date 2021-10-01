#include <iostream>
#include <algorithm>
using namespace std;
int map[11][11];
int visit[11];
int n;
int answer = -1;

void DFS(int home, int cur, int cost, int cnt) {
	if (answer != -1 && cost >= answer)
		return;
	if (cnt == n + 1 && home == cur) {
		if (answer == -1)
			answer = cost;
		else
			answer = min(answer, cost);
		return;
	}

	if (cnt == n) {
		if (map[cur][home] != 0)
			DFS(home, home, cost + map[cur][home], cnt + 1);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visit[i] == 0 && map[cur][i] != 0) {
			visit[i] = 1;
			DFS(home, i, cost + map[cur][i], cnt + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> map[i][j];
	
	for (int i = 0; i < n; i++) {
		visit[i] = 1;
		DFS(i, i, 0, 1);
		visit[i] = 0;
	}
	cout << answer;
}