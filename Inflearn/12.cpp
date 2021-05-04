#include <iostream>
using namespace std;
int main(){
	int n, sum = 0, cnt = 1, digit= 9, res = 0;
	cin >> n;
	while(sum+digit < n){
		sum += digit;
		res += cnt*digit;
		cnt++;
		digit *= 10;
	}
	res += (n-sum)*cnt;
	cout << res;
}