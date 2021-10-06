#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;
vector<pair<int, int>> graph[20001];	// first : arrive, second : cost
int answer[20001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq; // first : depart, second : cost
	pq.push({ 0, start });
	answer[start] = 0;
	while (!pq.empty()) {
		int cur_cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();


		for (int i = 0; i < graph[cur].size(); i++) {
			int arrive = graph[cur][i].first;
			int c = graph[cur][i].second;
			int cost = cur_cost + c;
			if (cost < answer[arrive]) {
				answer[arrive] = cost;
				pq.push({ -cost, arrive });
			}
		}
	}
}
int main() {
	int V, E, K;
	scanf("%d%d%d", &V, &E, &K);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		graph[u].push_back({ v, w });
	}
	for (int i = 0; i <= V; i++)
		answer[i] = INF;

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (answer[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", answer[i]);
	}
}