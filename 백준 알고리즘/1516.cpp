#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int building_time[501];
int before_build[501];
int answer[501];
vector<int> arr[501];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t, tmp;
		cin >> t >> tmp;
		building_time[i] = t;
		while (1) {
			if (tmp == -1)
				break;
			arr[tmp].push_back(i);	// i�� ���� ���ؼ� tmp�� ����ߵ�
			before_build[i]++;
			cin >> tmp;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (before_build[i] == 0) {	//���� ������ ������
			q.push(i);
			answer[i] = building_time[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < arr[cur].size(); i++) {
			int next = arr[cur][i];
			before_build[next]--;
			answer[next] = max(answer[next], answer[cur] + building_time[next]);
			if (before_build[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << answer[i] << "\n";
	}
}