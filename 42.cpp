#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
void find(int x){
	int start = 0, end = arr.size()-1, mid;
	while(start <= end){
		mid = (start+end)/2;
		if(x==arr[mid]){
			cout << mid+1;
			return;
		}
		else if(x < arr[mid]){
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	find(m);
}