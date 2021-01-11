#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int max = -1000000;
	int sum = 0;
	for(int i = 0 ; i < k; i++){
		sum = sum + arr[i];
	}
	max = sum;
	for(int i = k; i < n; i++){
		sum = sum + (arr[i] - arr[i-k]);
		if(sum > max) max = sum;
	}
	cout << max;
}