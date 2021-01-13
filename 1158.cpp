#include <iostream>
#include <queue>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for(int i = 1; i <= n; i++)
		q.push(i);
	int cnt = 0;
	cout << "<";
	while(q.size() != 1){
		cnt++;
		int tmp = q.front();
		q.pop();
		if(cnt == k){ 
			cout << tmp << ", ";
			cnt = 0;
		}
		else
			q.push(tmp);
	}
	cout << q.front() << ">";
}