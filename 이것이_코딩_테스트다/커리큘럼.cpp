#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int times[501];
vector<int> graph[501];
int indegree[501];
int n; // 노드의 개수

void topology() {
	vector<int> result(501);
	for (int i = 1; i <= n; i++) {
		result[i] = times[i];
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);
			indegree[graph[now][i]]--;
			if (indegree[graph[now][i]] == 0)
				q.push(graph[now][i]);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << "\n";
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		times[i] = t;
		while (1) {
			int before;
			cin >> before;
			if (before == -1) break;
			indegree[i]++;
			graph[before].push_back(i);
		}
	}

	topology();
}