#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;
vector<int> tree[MAX];
int parent[MAX];
void find_parent(int idx, int p) {
	parent[idx] = p;
	for (int i = 0; i < tree[idx].size(); i++) {
		int next = tree[idx][i];
		if (parent[next] == 0) {
			find_parent(tree[idx][i], idx);
		}
	}
}
int main(){
	int n; cin >> n;
	for (int i = 0; i < n-1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}
	find_parent(1, 1);
	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";
}