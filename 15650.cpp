#include <iostream>
using namespace std;
int n, m;
int arr[9];
void DFS(int num){
	if(num == m){
		for(int i = 0; i < num; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	else{
		if(num == 0)
			for(int i = 1; i <= n; i++){			
				arr[num] = i;
				DFS(num + 1);
			}
		else
			for(int i = arr[num-1] + 1; i <= n; i++){			
				arr[num] = i;
				DFS(num + 1);
			}
	}
}

int main(){
	cin >> n >> m;
	
	DFS(0);
}