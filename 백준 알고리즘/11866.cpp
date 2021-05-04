#include <iostream>
#include <queue>
using namespace std;
int main(){
	int n, k;
	queue<int> q;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		q.push(i);
	printf("<");
	int cnt = 1;
	while(q.size() != 1){
		if(cnt == k){
			printf("%d, ", q.front());
			q.pop();
			cnt = 1;
		}
		else{
			int tmp = q.front();
			q.pop();
			q.push(tmp);
			cnt++;
		}
	}
	printf("%d>", q.front());
}