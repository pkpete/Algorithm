#include <iostream>
#include <algorithm>
using namespace std;
int house[1001][3];
int dp[1001][3];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 3; j++)
			cin >> house[i][j];
	for(int i = 1; i <= n; i++){
		dp[i][0] = house[i][0] + min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = house[i][1] + min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = house[i][2] + min(dp[i-1][0], dp[i-1][1]);
	}
	int answer = min(dp[n][0], dp[n][1]);
	cout << min(answer, dp[n][2]);
}