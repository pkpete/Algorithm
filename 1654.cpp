#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int main(){
	int k, n; long long answer = -1;
	cin >> k >> n;
	for(int i = 0; i < k; i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	long long left = 1, right = arr[k-1], mid;
	if(n==0){
		cout << right;
		return 1;
	}
	while(left<=right){
		mid=(left+right)/2;
		int cnt = 0;
		for(int i = 0; i < k; i++){
			cnt += arr[i] / mid;
		}
		if(cnt >= n){
			if(answer < mid)
				answer = mid;
			left = mid + 1;
		}
		else if(cnt < n){
			right = mid - 1;
		}
	}
	cout << answer;
}