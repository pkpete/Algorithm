#include <iostream>
#include <deque>
using namespace std;
int n, answer = 0;
deque<int> dq;
void dfs(int index, int sum){
	if(sum == n){
		cout << dq[0];
		for(int i = 1; i < dq.size(); i++){
			cout << "+" << dq[i];
		}
		cout << "=" << n << endl;
		answer++;
	}
	else{
		if(sum + index + 1 > n)
			return;
		dq.push_back(index+1);
		dfs(index+1, sum+index+1);
		dq.pop_back();
	}
}
int main(){
	cin >> n;
	for(int i = n/2; i > 0; i--){
		dq.push_back(i);
		dfs(i,i);
		dq.pop_back();
	}
	cout << answer << endl;
}