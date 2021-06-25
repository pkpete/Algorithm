#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	reverse(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += k / v[i];
		k %= v[i];
	}

	cout << cnt;
}