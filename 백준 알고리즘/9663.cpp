#include <iostream>
using namespace std;
int n, answer = 0;
int map[16];
bool promising(int num){
	bool flag = true;
	int i = 1;
	while(i<num && flag){
		if(map[i] == map[num] || abs(map[i]-map[num]) == num - i)
			flag = false;
		i++;
	}
	return flag;
}
void dfs(int num){
	if(promising(num)){
		if(num == n)
			answer++;
		else{
			for(int i = 1; i <= n; i++){
				map[num + 1] = i;
				dfs(num+1);
			}
		}
	}
}
int main(){
	cin >> n;

	dfs(0);
	cout << answer;
}