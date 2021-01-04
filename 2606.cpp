#include <iostream>
#include <queue>
using namespace std;
int visit[101];
int computer[101][101];
queue<int> q;

int main(){
	int n, link;
	cin >> n >> link;
	int a, b;
	for(int i = 0; i < link; i++){
		cin >> a >> b;
		computer[a][b] = computer[b][a] = 1;
	}
	visit[1] = 1;
	int count = 0;
	q.push(1);
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(int i = 1; i <= n; i++){
			if(computer[tmp][i] == 1 && visit[i] == 0){
				visit[i] = 1;
				count++;
				q.push(i);
			}
		}
	}
	cout << count;
}