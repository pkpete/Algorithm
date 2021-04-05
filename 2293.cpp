#include <iostream>
using namespace std;
/*
	동전 1 2 5로 10 만들기
		0 1 2 3 4 5 6 7 8 9 10
	1:	  1 1 1 1 1 1 1 1 1  1		(1로 만들 수 있는)
	2:    1 2 2 3 3 4 4 5 5  6		(1,2로 만들 수 있는)
	5:	  1 2 2 3 4 5 6 6 8 10		(1,2,5로 만들 수 있는)
*/
int arr[101], dp[10001];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - arr[i]];
		}
	}
	cout << dp[k];
}