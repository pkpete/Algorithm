#include <iostream>
using namespace std;
int dp[1001];
int main(){
	int n;
	cin >> n;
	int num, num2;
	for(int i = 1; i <= 1000; i++){
		dp[i] = dp[i-1]+i;
	}
	for(int i = 0 ; i< n; i++){
		cin >> num >> num2;
		if(dp[num] == num2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}