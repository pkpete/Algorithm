#include <iostream>
using namespace std;
int arr[101];
int digit_sum(int x){
	int sum = 0;
	while(x>0){
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
int main(){
	int n; cin >> n;
	int sum = 0, answer;
	for(int i = 0; i< n; i++){
		cin >> arr[i];
		int tmp = digit_sum(arr[i]);
		if(tmp >= sum){
			if(tmp == sum){
				if(arr[i] > answer)
					answer = arr[i];
			}
			else{
				answer = arr[i];
			}
			sum = tmp;
		}
	}
	cout << answer;
}