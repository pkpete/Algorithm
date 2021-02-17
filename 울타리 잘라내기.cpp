#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve(int left, int right, vector<int> fence) {
	if (left == right) {
		return fence[left];
	}
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid, fence), solve(mid + 1, right, fence));
	int lo = mid, hi = mid + 1;
	int height = min(fence[mid], fence[mid + 1]);
	ret = max(ret, height * 2);
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || fence[lo - 1] < fence[hi + 1])) {
			++hi;
			height = min(height, fence[hi]);
		}
		else {
			--lo; 
			height = min(height, fence[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> fence;
		fence.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> fence[i];
		}
		cout << solve(0, n - 1, fence) << "\n";
	}
}