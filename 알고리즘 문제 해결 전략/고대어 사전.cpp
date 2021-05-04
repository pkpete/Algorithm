#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<string> words;
int graph[26][26];
int visit[26];
string answer;

void make_graph() {
	memset(graph, 0, sizeof(graph));
	memset(visit, 0, sizeof(visit));
	answer = "";

	int len = words.size();
	for (int i = 0; i < len - 1; i++) {	
		int j = i + 1;
		for (int k = 0; k < words[i].size(); k++) {
			if (words[i][k] != words[j][k]) {
				graph[words[i][k] - 'a'][words[j][k] - 'a'] = 1;
				break;
			}
		}
	}
}

void dfs(int idx) {
	visit[idx] = 1;
	for (int i = 0; i < 26; i++) {
		if (visit[i] == 0 && graph[idx][i] == 1)
			dfs(i);
	}
	answer += idx + 'a';
}

void solve() {
	for (int i = 0; i < 26; i++) {
		if (visit[i] == 0)
			dfs(i);
	}
	reverse(answer.begin(), answer.end());
}

int main() {
	
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n;
		cin >> n;
		words = vector<string>(n);
		for (int i = 0; i < n; i++) {
			cin >> words[i];
		}
		make_graph();
		solve();
		bool dic = true;
		for (int i = 1; i < 26; i++) {
			for (int j = 0; j < i; j++) {
				if (graph[answer[i]-'a'][answer[j]-'a']) {
					cout << "INVALID HYPOTHESIS\n";
					dic = false;
					break;
				}
			}
			if (!dic)
				break;
		}
		if (dic) {
			cout << answer << "\n";
		}
		
	}
}

//vector<vector<int>> graph;
//vector<int> visit, order;
//
//void makeGraph(const vector<string>& words) {
//	graph = vector<vector<int>>(26, vector<int>(26, 0));
//	for (int j = 1; j < words.size(); j++) {
//		int i = j - 1;	// j의 직전 단어
//		for (int k = 0; k < words[i].size(); k++) {
//			if (words[i][k] != words[j][k]) {
//				int tmp1 = words[i][k] - 'a';
//				int tmp2 = words[j][k] - 'a';
//				graph[tmp1][tmp2] = 1;
//				break;
//			}
//		}
//	}
//}
//
//void dfs(int current) {
//	visit[current] = 1;
//	for (int i = 0; i < graph.size(); i++) {
//		if (graph[current][i] && !visit[i])
//			dfs(i);
//	}
//	order.push_back(current);
//}
//
//vector<int> topologicalSort() {
//	int m = graph.size();
//	visit = vector<int>(m, 0);
//	order.clear();
//
//	for (int i = 0; i < m; i++) {
//		if (!visit[i])
//			dfs(i);
//	}
//
//	reverse(order.begin(), order.end());
//
//	for (int i = 0; i < m; i++) {
//		for (int j = i + 1; j < m; j++) {
//			if (graph[order[j]][order[i]])
//				return vector<int>();
//		}
//	}
//
//	return order;
//}
//
//
//void input() {
//	int testcase;
//	cin >> testcase;
//	while (testcase--) {
//		int n;
//		cin >> n;
//		vector<string> words(n);
//		for (int i = 0; i < n; i++) {
//			cin >> words[i];
//		}
//		makeGraph(words);
//
//		vector<int> orders = topologicalSort();
//
//		if (orders.empty())
//			cout << "INVALID HYPOTHESIS\n";
//		else {
//			for (int i = 0; i < orders.size(); i++)
//				cout << (char)(orders[i] + 'a');
//		}
//	}
//}
//
//int main() {
//	input();
//}