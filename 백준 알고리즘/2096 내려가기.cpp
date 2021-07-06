#include <iostream>
#include <algorithm>
using namespace std;
int a,b,c, max_dp[3], min_dp[3], n;
int main() {
	cin >> n;
	cin >> max_dp[0] >> max_dp[1] >> max_dp[2];
	
	for (int i = 0; i < 3; i++) {
		min_dp[i] = max_dp[i];
	}

	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		int tmp0 = max_dp[0], tmp2 = max_dp[2];
		max_dp[0] = max(max_dp[0], max_dp[1]) + a;
		max_dp[2] = max(max_dp[1], max_dp[2]) + c;
		max_dp[1] = max(max(tmp0, max_dp[1]), tmp2) + b;

		tmp0 = min_dp[0], tmp2 = min_dp[2];
		min_dp[0] = min(min_dp[0], min_dp[1]) + a;
		min_dp[2] = min(min_dp[1], min_dp[2]) + c;
		min_dp[1] = min(min(tmp0, min_dp[1]), tmp2) + b;
	}

	cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << " " << min(min(min_dp[0], min_dp[1]), min_dp[2]);
}