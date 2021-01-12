#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int tmp;
	for(int i = 0; i< n; i++){
		if(i==0){
			cout << arr[i] << " ";
			tmp = arr[i];
		}
		else{
			if(tmp == arr[i]) continue;
			else {
				cout << arr[i] << " ";
				tmp = arr[i];
			}
		}
	}
}