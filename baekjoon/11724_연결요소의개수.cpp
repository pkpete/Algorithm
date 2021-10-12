#include <iostream>
#include <vector>
using namespace std;
vector<int> arr[1001];
bool visit[1001];

void dfs(int idx) {
	for (int i = 0; i < arr[idx].size(); i++) {
		if (!visit[arr[idx][i]]) {
			visit[arr[idx][i]] = true;
			dfs(arr[idx][i]);
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
}