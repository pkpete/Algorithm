#include <iostream>
using namespace std;
int n, m;
int arr[8];
void DFS(int num){
	if(num == m){
		for(int i = 0; i < num; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	else{
		for(int i = 1; i <= n; i++){
			arr[num] = i;
			DFS(num + 1);
		}
	}
}

int main(){
	cin >> n >> m;
	
	DFS(0);
}