#include <iostream>
using namespace std;
int arr[50001];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j= j+i){
			arr[j]++;
		}
	}
	for(int i = 1; i <= n; i++)
		cout << arr[i] << " ";
}