#include <iostream>
using namespace std;
int arr[201];
int find_parent(int x) {
	if (arr[x] == x)
		return x;
	return arr[x] = find_parent(arr[x]);
}
void Union(int x, int y) {
	int i = find_parent(x);
	int j = find_parent(y);
	arr[j] = i;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num) {	//서로 연결되어있어
				if (find_parent(i) != find_parent(j)) {
					Union(i, j);
				}
			}
		}
	}
	int num;
	cin >> num;
	int tmp = find_parent(num);
	for (int i = 1; i < m; i++) {
		cin >> num;
		if (tmp != find_parent(num)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
