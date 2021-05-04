#include <iostream>
#include <vector>
using namespace std;

vector<string> words;
int graph[100][100];
int visit[100];
vector<int> answer;

void make_graph() {
	memset(graph, 0, sizeof(graph));
	
	int size = words.size();
	for (int i = 0; i < size; i++) {	//i의 끝이 j의 처음과 같아야됨
		for (int j = 0; j < size; j++) {
			if (i != j) {
				if (words[i][words[i].size() - 1] == words[j][0]) {
					graph[i][j] = 1;
				}
			}
		}
	}
}

void dfs(int index) {
	visit[index] = 1;
	for (int i = 0; i < words.size(); i++) {
		if (visit[i] == 0 && graph[index][i] == 1) {
			dfs(i);
		}
	}
	answer.push_back(index);
}

void circuit() {
	for (int i = 0; i < words.size(); i++) {
		answer.clear();
		memset(visit, 0, sizeof(visit));
		dfs(i);
		if (answer.size() == words.size()) {
			reverse(answer.begin(), answer.end());
			break;
		}
	}
}

int main() {
	int testcase, n;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		words = vector<string>(n);
		for (int i = 0; i < n; i++) {
			cin >> words[i];
		}
		make_graph();
		circuit();
		if (answer.size() == words.size()) {
			for (int i = 0; i < answer.size(); i++) {
				cout << words[answer[i]] << " ";
			}
			cout << "\n";
		}
		else {
			cout << "IMPOSSIBLE\n";
		}
	}
}