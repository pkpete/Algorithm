#include <iostream>
#include <queue>
using namespace std;
int main(){
	priority_queue<int, vector<int>, greater<int>> pq;
	int n, m, num;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		pq.push(num);
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> num;
		pq.push(num);
	}
	while(!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
}