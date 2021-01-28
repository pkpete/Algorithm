#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int node, dist = 0, far_node;
vector<pair<int, int>> graph[10001];
bool visit[10001];
void input() {
	cin >> node;
	for (int i = 0; i < node-1; i++) {
		int parent, child, weight;
		cin >> parent >> child >> weight;
		graph[parent].push_back(make_pair(child, weight));
		graph[child].push_back(make_pair(parent, weight));
	}
}

void dfs(int node, int weight) {
	if (visit[node]) {
		return;
	}

	visit[node] = true;

	if (weight > dist) {
		dist = weight;
		far_node = node;
	}

	for (int i = 0; i < graph[node].size(); i++) {
		dfs(graph[node][i].first, weight + graph[node][i].second);
	}

}

int main() {
	input();

	dfs(1, 0);

	memset(visit, false, sizeof(visit));

	dfs(far_node, 0);
	
	cout << dist << "\n";
}