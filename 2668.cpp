#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr, check, answer;

void dfs(int start, int end){
	if(check[end]==1){
		if(start == end)
			answer.push_back(start);
	}
	else{
		check[end] = 1;
		dfs(start, arr[end]);
	}
}

int main(){
	int n;
	cin >> n;
	arr = vector<int>(n+1);
	check = vector<int>(n+1);

	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	
	for(int i = 1; i <= n; i++){
		check = vector<int> (n+1,0);
		dfs(i,i);
	}
	cout << answer.size() << "\n";
	for(int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";
}