#include <iostream>
#include <vector>
using namespace std;
int arr[1000001];
vector<int> prime;
int main(){
	int n, cnt = 0;
	cin >> n;

	for(int i = 2; i <= 1000000; i++){
		if(arr[i] == 0){
			prime.push_back(i);
			for(int j = i*2; j <= 1000000; j = j + i){
				arr[j] = 1;
			}
		}
	}

	cout << prime[n-1];
}