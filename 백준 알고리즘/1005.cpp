#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;	//건물 갯수, 건설 순서 규칙 갯수
int build_time[1001];
int before[1001];
int answer[1001];
vector<int> building[1001];
vector<int> tmp;

void clear_arr() {
	memset(build_time, 0, sizeof(build_time));
	memset(before, 0, sizeof(before));
	memset(answer, 0, sizeof(answer));
	for (int i = 0; i < 1001; i++) {
		building[i].clear();
	}
}

void input() {
	int test;
	cin >> test;
	while (test--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> build_time[i];	//건물 건설 시간
		}
		for (int i = 0; i < k; i++) {	//first를 지어야 second 지을 수 있음
			int first, second;
			cin >> first >> second;
			before[second]++;
			building[first].push_back(second);
		}

		int w;
		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; i++) {	// 전에 지을 건물이 없으면 큐에 집어 넣어
			if (before[i] == 0) {
				q.push(i);
				answer[i] = build_time[i];
			}
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < building[cur].size(); i++) {
				int next = building[cur][i];
				before[next]--;
				answer[next] = max(answer[next], answer[cur] + build_time[next]);
				if (before[next] == 0) {
					q.push(next);
				}
			}
		}

		cout << answer[w] << "\n";

		clear_arr();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
}