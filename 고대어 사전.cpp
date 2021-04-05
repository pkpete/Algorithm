#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> visit, order;

void makeGraph(const vector<string>& words) {
	graph = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); j++) {
		int i = j - 1;	// j의 직전 단어
		for (int k = 0; k < words[i].size(); k++) {
			if (words[i][k] != words[j][k]) {
				int tmp1 = words[i][k] - 'a';
				int tmp2 = words[j][k] - 'a';
				graph[tmp1][tmp2] = 1;
				break;
			}
		}
	}
}

void dfs(int current) {
	visit[current] = 1;
	for (int i = 0; i < graph.size(); i++) {
		if (graph[current][i] && !visit[i])
			dfs(i);
	}
	order.push_back(current);
}

vector<int> topologicalSort() {
	int m = graph.size();
	visit = vector<int>(m, 0);
	order.clear();

	for (int i = 0; i < m; i++) {
		if (!visit[i])
			dfs(i);
	}

	reverse(order.begin(), order.end());

	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			if (graph[order[j]][order[i]])
				return vector<int>();
		}
	}

	return order;
}


void input() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n;
		cin >> n;
		vector<string> words(n);
		for (int i = 0; i < n; i++) {
			cin >> words[i];
		}
		makeGraph(words);

		vector<int> orders = topologicalSort();

		if (orders.empty())
			cout << "INVALID HYPOTHESIS\n";
		else {
			for (int i = 0; i < orders.size(); i++)
				cout << (char)(orders[i] + 'a');
		}
	}
}

int main() {
	input();
}