#include <iostream>
#include <queue>
using namespace std;

bool visit[101];	// True이면 방문한 컴퓨터, False이면 아직 방문하지 않은 컴퓨터
int map[101][101];	// 컴퓨터 사이의 관계

int main() {
	int n, networks;
	cin >> n >> networks;

	for (int i = 0; i < networks; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	queue<int> q;
	q.push(1);
	visit[1] = true;
	int cnt = 0;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		// 바이러스로 부터 감염된 컴퓨터와 연결된 컴퓨터 확인
		for (int i = 1; i <= n; i++) {
			// 아직 방문하지 않은 컴퓨터
			if (map[tmp][i] == 1 && !visit[i]) {
				visit[i] = true;
				q.push(i);
				cnt++;
			}
		}
	}
	cout << cnt;
}