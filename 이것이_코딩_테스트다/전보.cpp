#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int n, m, start; // 도시 개수, 통로 개수, 출발지
vector<int> answer;
vector<pair<int,int>> graph[30001];	// 도착지 cost

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;	// cost, 도착지
	pq.push({ -0, start });
	answer[start] = 0;
	while (!pq.empty()) {
		int time = -pq.top().first;
		int cur_city = pq.top().second;
		pq.pop();
		
		if (answer[cur_city] < time) continue;

		for (int i = 0; i < graph[cur_city].size(); i++) {
			int cost = graph[cur_city][i].second;
			int next_city = graph[cur_city][i].first;
			if (time + cost < answer[next_city]) {
				answer[next_city] = time + cost;
				pq.push({ -(time + cost), next_city });
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;
	answer = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		answer[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;	// a에서 b로 c시간 걸림
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	dijkstra(start);
	
	int cnt_town = 0;
	for (int i = 1; i <= n; i++) {
		if (answer[i] != INF && i != start)
			cnt_town++;
	}
	sort(answer.begin(), answer.end());
	cout << cnt_town << " " << answer[answer.size() - 1];
}