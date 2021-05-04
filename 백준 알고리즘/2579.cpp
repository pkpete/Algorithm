#include <iostream>
#include <algorithm>
using namespace std;
int stairs[301];
int dp[301];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> stairs[i];
	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	for(int i = 3; i <=n; i++){
		dp[i] = stairs[i] + max(dp[i-2], stairs[i-1] + dp[i-3]);
	}
	cout << dp[n];
}