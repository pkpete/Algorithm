#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001], dp[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;
	int answer = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] <= dp[j])
				dp[i] = dp[j] + 1;
		}
		answer = max(answer, dp[i]);
	}
	cout << answer;
}