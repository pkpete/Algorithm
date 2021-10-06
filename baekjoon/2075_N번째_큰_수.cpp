#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n * n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(-tmp);
		if (pq.size() > n) {
			pq.pop();
		}
	}
	cout << -pq.top();
	/*vector<int> arr(n*n), answer;

	for (int i = 0; i < n*n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	cout << arr[n - 1];*/
}