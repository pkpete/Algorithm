#include <iostream>
using namespace std;
int map[501][501];
int dp[501][501];
int n, answer = -1;
int dirX[4]={1,-1,0,0};
int dirY[4]={0,0,1,-1};
void input(){
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> map[i][j];
}
int dfs(int y, int x){
 	int &cnt = dp[y][x];
	if(cnt != 0) return cnt;
	cnt = 1;
	int tmp;
	for(int i = 0; i < 4; i++){
		int movex = x + dirX[i];
		int movey = y + dirY[i];
		if(movex>=0&&movex<n&&movey>=0&&movey<n&& map[y][x] < map[movey][movex]){
			tmp = 1 + dfs(movey, movex);
			if(tmp > cnt)
				cnt = tmp;
		}
	}
	return cnt;
}
int main(){
	input();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int tmp = dfs(i,j);
			if(tmp > answer)
				answer = tmp;
		}
	}
	cout << answer;
}