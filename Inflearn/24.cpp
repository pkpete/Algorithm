#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> arr(n), check(n, 0);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = n-1; i > 0; i--){
		int tmp = abs(arr[i]-arr[i-1]);
		if(tmp > n){
			cout << "NO"; return 0;
		}
		check[tmp] = 1;
	}
	for(int i = 1; i < n; i++){
		if(check[i] == 0){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}