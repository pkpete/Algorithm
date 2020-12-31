#include <iostream>
using namespace std;
int n, m;
int arr[9];
int check[9];
void DFS(int num){
	if(num == m){
		for(int i = 0; i < num; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	else{
		for(int i = 1; i <= n; i++){
			if(check[i] != 1){
				check[i] = 1;
				arr[num] = i;
				DFS(num + 1);
				check[i] = 0;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	
	DFS(0);
}