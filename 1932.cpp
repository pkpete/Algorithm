#include <iostream>
#include <algorithm>
using namespace std;
int dp[501][501];
int main(){
	int n;
	int maxSum = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cin >> dp[i][j];
			if(j==1){
				dp[i][j] += dp[i-1][j];
			}
			else if(j==i){
				dp[i][j] += dp[i-1][j-1];
			}
			else{
				dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
			}
			if(maxSum < dp[i][j])
				maxSum = dp[i][j];
		}
	}
	cout << maxSum << endl;

}