#include <iostream>
using namespace std;
int main(){
	int testcase, n;
	int arr[11] = {0, };
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	cin >> testcase;
	for(int i=0; i<testcase; i++){
		cin >> n;
		for(int j=4; j<=n; j++){
			arr[j] = arr[j-1] + arr[j-2] + arr[j-3];
		}
		cout << arr[n] << "\n";
	}
}