#include <iostream>
#include <algorithm>
using namespace std;
int map[702][702];
int dp[702][702];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> map[i][j];

			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
		}
	}
	int a, b;
	cin >> a >> b;
	int answer = -1;
	for (int i = a; i <= h; i++) {
		for (int j = b; j <= w; j++) {
			answer = max(answer, dp[i][j] - dp[i - a][j] - dp[i][j - b] + dp[i - a][j - b]);
		}
	}
	cout << answer;
}