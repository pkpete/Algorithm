#include <iostream>
#include <queue>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testcase;
	cin >> testcase;
	for(int i = 0; i < testcase; i++){
		int files, index, cnt = 1;
		cin >> files >> index;
		priority_queue<int> pq;
		queue<pair<int,int>> q;
		for(int j = 0; j < files; j++){
			int priority;
			cin >> priority;
			q.push(make_pair(j, priority));
			pq.push(priority);
		}
		while(!q.empty()){
			int p = pq.top();
			while(p != q.front().second){
				pair<int,int> tmp = q.front();
				q.pop();
				q.push(tmp);
			}
			if(q.front().first == index){
				cout << cnt << "\n";
				break;
			}
			pq.pop();
			q.pop();
			cnt++;
		}
		
	}
}