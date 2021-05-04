#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
bool finish = false;
int arr[80];
void dfs(int cnt){
	for(int i = 1; i <= cnt/2; i++){
		if(equal(arr+cnt-i, arr+cnt, arr+cnt-i*2))
			return;
	}
	if(cnt == n){
		for(int i = 0; i < n; i++){
			cout << arr[i];
		}
		exit(0);
	}
	for(int i = 1; i <= 3; i++){
		arr[cnt] = i;
		dfs(cnt+1);
	}
	

}
int main(){
	cin >> n;
	dfs(0);
}