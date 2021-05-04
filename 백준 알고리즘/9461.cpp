#include <iostream>
using namespace std;
long long dp[101];
int main(){
	int t, n;
	cin >> t;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 3; j <= n; j++){
			dp[j] = dp[j-2] + dp[j-3];
		}
		cout << dp[n] << "\n";
	}
}