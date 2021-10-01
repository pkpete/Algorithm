#include <iostream>
#include <algorithm>
using namespace std;

int w[101], v[101], dp[101][100001];

int main() {
	int n, k;	// 물건 개수, 버틸 수 있는 무게
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	// dp[i][j] == i번째 물건까지 담았을때, 담은 무게의 합이 j 일때의 가치 합
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	
	cout << dp[n][k];
}