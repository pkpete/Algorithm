#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int left = 0, right = arr[n - 1];
	int answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int length = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid)
				length += arr[i] - mid;
		}
		if (length < m) {
			right = mid - 1;
		}
		else if (m <= length) {
			left = mid + 1;
			answer = max(answer, mid);
		}
	}
	cout << answer;
}