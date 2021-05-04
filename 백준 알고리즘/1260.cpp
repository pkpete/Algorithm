#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001];
int visit[1001];

void DFS(int start, int node){
	cout << start << " ";
	visit[start] = 1;
	for(int i = 1; i <= node; i++){
		if((graph[start][i] == 1) && (visit[i] == 0))
			DFS(i, node);
	}
}

void BFS(int start, int node){
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	while(!q.empty()){
		int num = q.front();
		for(int i = 1; i <= node; i++)
			if((graph[num][i] == 1) && (visit[i] == 0)){
				q.push(i);
				visit[i] = 1;
			}
		q.pop();
		cout << num << " ";
	}
}

int main(){
	int node, edge, start;
	cin >> node >> edge >> start;
	int n, k;
	for(int i = 1; i <= edge; i++){
		cin >> n >> k;
		graph[n][k] = graph[k][n] = 1;
	}
	DFS(start, node);
	for(int i = 1; i <= node; i++)
		visit[i] = 0;
	cout << "\n";
	BFS(start, node);
}