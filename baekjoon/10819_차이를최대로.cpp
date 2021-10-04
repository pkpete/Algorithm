#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int answer = 0;
bool visit[10];
void dfs(vector<int> arr, int cur, int sum, int idx, int depth) {
	if (depth == arr.size()) {
		answer = max(answer, sum);
		return;
	}
	for (int i = 0; i < arr.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(arr, arr[i], sum + abs(cur - arr[i]), i, depth + 1);
			visit[i] = false;
		}
	}
}


int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		visit[i] = true;
		dfs(arr, arr[i], 0, i, 1);
		visit[i] = false;
	}
	cout << answer;
}