#include <iostream>
using namespace std;
int ppl[100001];
int find_parent(int a) {
	if (a == ppl[a]) return a;
	else return ppl[a] = find_parent(ppl[a]);
}

void union_team(int a, int b) {
	int a_parent = find_parent(a);
	int b_parent = find_parent(b);
	if (a_parent < b_parent)
		ppl[b_parent] = a_parent;
	else
		ppl[a_parent] = b_parent;
}
int main() {
	int n, m;	
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		ppl[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int tmp, a, b;
		cin >> tmp >> a >> b;
		if (tmp == 0) {
			union_team(a, b);
		}
		else if (tmp == 1) {
			int a_parent = find_parent(a);
			int b_parent = find_parent(b);
			if (a_parent == b_parent)
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
}