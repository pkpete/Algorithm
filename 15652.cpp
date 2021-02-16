#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n, m;
void dfs(int index, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = index; i <= n; i++) {
		v[cnt] = i;
		dfs(i, cnt + 1);
	}
}
int main() {
	cin >> n >> m;
	v.resize(m);
	for (int i = 1; i <= n; i++) {
		v[0] = i;
		dfs(i, 1);
	}
}