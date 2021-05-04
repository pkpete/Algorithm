#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int count(int len){
	int cnt=1, x = v[0];
	for(int i = 0; i < v.size(); i++){
		if(v[i] - x >= len){
			cnt++;
			x = v[i];
		}
	}
	return cnt;
}
int main(){
	int n, c;
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int left = 1, right = v[n-1], mid, answer;
	while(left <= right){
		mid = (left+right)/2;
		if(count(mid) >= c){
			answer = mid;
			left = mid +1;
		}
		else
			right = mid - 1;
	}
	cout << answer;
}