#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];
int dp[101];
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = max(arr[2], dp[1]);
	for (int i = 3; i <= n; i++) {
		dp[i] = arr[i] + max(dp[i - 2], dp[i - 3]);
	}
	cout << dp[n];
}