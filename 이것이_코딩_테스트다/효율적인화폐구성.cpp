#include <iostream>
#include <vector>
using namespace std;
int dp[10001];
int money[101];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}

	for (int i = 1; i <= m; i++) {
		dp[i] = 10005;
	}

	for (int i = 0; i < n; i++) {
		for (int j = money[i]; j <= m; j ++) {
			if (dp[j - money[i]] != 10005) {
				dp[j] = min(dp[j], dp[j - money[i]] + 1);
			}
		}
	}
	if (dp[m] == 10005) cout << -1;
	else cout << dp[m];
}