#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end(), cmp);
	int tmp = arr[0];
	int cnt = 1;
	for(int i = 1; i < n; i++){
		if(tmp == arr[i]) continue;
		else {
			cnt++;
			tmp = arr[i];
		}
		if(cnt == 3){
			cout << arr[i];
			break;
		}
	}
}