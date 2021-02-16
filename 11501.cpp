#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t) {
		int n, sum = 0;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int max_num = v[n - 1];
		long long profit = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (v[i] >= max_num) {
				max_num = v[i];
			}
			else {
				profit += (max_num - v[i]);
			}
		}
		cout << profit << "\n";
		t--;
	}
}