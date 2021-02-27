#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;	//�ǹ� ����, �Ǽ� ���� ��Ģ ����
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
			cin >> build_time[i];	//�ǹ� �Ǽ� �ð�
		}
		for (int i = 0; i < k; i++) {	//first�� ����� second ���� �� ����
			int first, second;
			cin >> first >> second;
			before[second]++;
			building[first].push_back(second);
		}

		int w;
		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; i++) {	// ���� ���� �ǹ��� ������ ť�� ���� �־�
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