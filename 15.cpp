#include <iostream>
using namespace std;
int arr[200001];
int main(){
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		for(int j = i; j <= n; j = j+i){
			if(j%i==0)
				arr[j]++;
		}
	}
	int cnt = 0;
	for(int i = 2; i<= n; i++)
		if(arr[i] == 1) cnt++;
	cout << cnt;
}