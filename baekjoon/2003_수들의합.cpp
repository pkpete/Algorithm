#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int left = 0;
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		while (sum > m) {
			sum -= arr[left++];
		}
		if (sum == m)
			cnt++;
	}
	cout << cnt;
}