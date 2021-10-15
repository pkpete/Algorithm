#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int node[100001];

int find_parent(int a) {
	if (node[a] == a) return a;
	else return node[a] = find_parent(node[a]);
}

void union_node(int a, int b) {
	int a_p = find_parent(a);
	int b_p = find_parent(b);
	if (a_p < b_p)
		node[b_p] = a_p;
	else
		node[a_p] = b_p;
}

int main() {
	int n, m;
	priority_queue<pair<int, pair<int, int>>> pq;	// cost, a->b
	vector<int> answer;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		node[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ -c, {a,b} });
	}
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second.first;
		int next = pq.top().second.second;
		pq.pop();
		int a = find_parent(cur);
		int b = find_parent(next);
		if (a != b) {
			union_node(a, b);
			answer.push_back(-cost);
		}
	}
	sort(answer.begin(), answer.end());
	int sum = 0;
	for (int i = 0; i < answer.size() - 1; i++) {
		sum += answer[i];
	}
	cout << sum;
}