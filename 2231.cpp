#include <iostream>
using namespace std;
int main(){
	int n;
	int sum, tmp;
	cin >> n;
	for(int i = 1; i < n; i++){
		sum = i;
		tmp = i;
		while(tmp>0){
			sum += tmp % 10;
			tmp /= 10;
		}
		if(sum == n){
			cout << i;
			return 0;
		}
	}
	cout << 0;
}