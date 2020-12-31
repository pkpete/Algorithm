#include <iostream>
using namespace std;
int arr[101];
int check[101];
int card[3];
int n, m, answer = 0;
void DFS(int count){
	if(count == 3){
		int sum = 0;
		for(int i = 0; i < 3; i++){
			sum += card[i];
		}
		if(sum == m){
			answer = sum;
			return;
		}
		else if(sum < m && sum > answer){
			answer = sum;
			return;
		}
	}
	else{
		for(int i = 0; i < n; i++){
			if(check[i] != 1){
				check[i] = 1;
				card[count] = arr[i];
				DFS(count+1);
				check[i] = 0;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	DFS(0);
	cout << answer;
}