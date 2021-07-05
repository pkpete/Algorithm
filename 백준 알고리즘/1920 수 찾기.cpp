#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	cin >> n;
	for (int i = 0; i < n; i++) {
		long tmp;
		cin >> tmp;
		int left = 0, right = v.size() - 1;
		bool found = false;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (tmp == v[mid]) {
				cout << 1 << "\n";
				found = true;
				break;
			}
			else if (tmp < v[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (!found)
			cout << 0 << "\n";
	}
}