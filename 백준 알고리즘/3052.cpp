#include <iostream>
using namespace std;
int arr[43];
int main(){
	int a, b;
	for(int i = 0; i < 10; i++){
		int num;
		cin >> num;
		arr[num%42] = 1;
	}
	int cnt = 0;
	for(int i = 0; i < 43; i++){
		if(arr[i] == 1)
			cnt++;
	}
	cout << cnt;
}