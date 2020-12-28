#include <iostream>
using namespace std;

int dp[41][2];

int main(){
	int testcase;
	int n;
	cin >> testcase;
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for(int i=0; i<testcase; i++){
		cin >> n;
		for(int j=2; j<=n; j++){
			for(int k=0; k<=1; k++)
				dp[j][k] = dp[j-1][k] + dp[j-2][k];
		}
		cout << dp[n][0] << " " << dp[n][1] << "\n";
	}
}
