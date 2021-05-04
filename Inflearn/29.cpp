#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int left, cur, right, k = 1;
	int cnt = 0;
	while(n > k){
		left = n / (k*10);
		cur = n / k % 10;
		right = n % k;
		if(cur > 3){
			cnt += (left+1) * k;
		}
		else if(cur < 3){
			cnt += left * k;
		}
		else{
			cnt += left * k + right + 1;
		}
		k *= 10;
	}
	cout << cnt;
}