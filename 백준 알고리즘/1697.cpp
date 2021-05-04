#include <iostream>
#include <queue>
using namespace std;
int visit[100001];
int main(){
	int n, k;
	cin >> n >> k;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int position = q.front();
		q.pop();
		if(position == k)
			break;
		if(position-1>=0 && visit[position-1] == 0){
			q.push(position-1);
			visit[position-1] = visit[position] + 1;
		}
		if(position+1<=100000 && visit[position+1] == 0){
			q.push(position+1);
			visit[position+1]= visit[position] + 1;
		}
		if(position*2 <= 100000 && visit[position*2] == 0){
			q.push(position*2);
			visit[position*2]= visit[position] + 1;
		}
	}
	cout << visit[k];
}