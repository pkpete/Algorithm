#include <iostream>
#include <string>
#include <queue>
using namespace std;
int map[101][101];
int check[101][101];
int dirY[4] = {0,0,1,-1};
int dirX[4] = {1,-1,0,0};
queue<pair<int, pair<int,int>>> q;
int main(){
	int n, m;
	cin >> n >> m;
	string s;
	for(int i = 1 ; i <= n; i++){
		cin >> s;
		for(int j = 0; j < m; j++)
			map[i][j+1] = s[j] - '0';
	}
	q.push(make_pair(1, make_pair(1,1)));
	check[1][1]=1;
	while(!q.empty()){
		int count = q.front().first;
		int y = q.front().second.second;
		int x = q.front().second.first;
		q.pop();
		if(y == n && x == m){
			cout << count;
			return 0;
		}
		for(int i = 0 ; i < 4; i++){
			int movey = y+dirY[i];
			int movex = x+dirX[i];
			if(movey>0 && movey<=n && movex>0 && movex<=m)
				if(map[movey][movex] == 1 && check[movey][movex] == 0){
					q.push(make_pair(count+1,make_pair(movex,movey)));
					check[movey][movex] = 1;
				}
		}
	}

}