#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<long long> arr(n+1), prime;
	for(long long i = 2; i <= n; i++){
		if(arr[i] == 0){
			prime.push_back(i);
			for(long long j = i*2; j <= n; j=j+i){
				arr[j] = 1;
			}
		}
	}
	int cnt = 0;
	int left = 0, right = 0, sum = 0;
	while(1){
		if(sum >= n)
			sum -= prime[left++];
		else if(right == prime.size())
			break;
		else sum += prime[right++];

		if(sum == n)
			cnt++;
	}
	cout << cnt;
}