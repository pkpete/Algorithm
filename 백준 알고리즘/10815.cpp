#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arr;
bool find(int x){
	int start = 0,end=arr.size()-1,mid=(start+end)/2,tmp;
	while(start<=end){
		tmp = arr[mid];
		if(x==tmp)
			return true;
		else if(x > tmp)
			start = mid+1;
		else
			end = mid-1;
		mid = (start+end)/2;
		
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n;
	arr = vector<int> (n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	cin >> m;
	vector<int> arr2(m);
	for(int i = 0; i < m; i++){
		cin >> arr2[i];
	}

	for(int i = 0; i < m; i++){
		cout << find(arr2[i]) << " ";
	}
}