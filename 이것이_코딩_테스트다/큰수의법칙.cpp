#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	int answer = 0, cnt_k = 0;
	for (int i = 0; i < m; i++) {
		if (cnt_k == k) {
			cnt_k = 0;
			answer += arr[1];
			continue;
		}
		answer += arr[0];
		cnt_k++;
	}
	cout << answer;
}