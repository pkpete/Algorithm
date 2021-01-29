#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[101];
int dist[101];
int a, b;
void input() {
	int n, c;
	cin >> n >> a >> b >> c;
	for (int i = 0; i < c; i++) {
		int parent, child;
		cin >> parent >> child;
		v[parent].push_back(child);
		v[child].push_back(parent);
	}
}
int main() {
	input();
	queue<int> q;
	q.push(a);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == b) {
			cout << dist[b];
			return 0;
		}
		int size = v[x].size();
		for (int i = 0; i < size; i++) {
			int y = v[x][i];
			if (dist[y] == 0) {
				q.push(y);
				dist[y] = dist[x] + 1;
			}
		}
	}
	cout << -1;
}