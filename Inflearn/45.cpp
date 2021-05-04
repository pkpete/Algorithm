#include <iostream>
#include <queue>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for(int i = 0; i < n; i++){
		q.push(i+1);
	}
	int tmp, cnt=0;
	while(!q.empty()){
		cnt++;
		tmp = q.front();
		q.pop();
		if(cnt == k){
			cnt = 0;
		}
		else{
			q.push(tmp);
		}
	}
	cout << tmp;
}