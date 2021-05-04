#include <iostream>
#include <queue>
using namespace std;
int map[1001][1001];
int check[1001][1001];
int dirX[4] = {1,-1,0,0};
int dirY[4] = {0,0,1,-1};
struct tomato{
	int x,y,count;
	tomato(int a, int b,int c):x(a), y(b), count(c){}
};
queue<tomato> q;
int main(){
	int row, col;
	cin >> row >> col;
	bool fin = true;
	for(int i = 1; i <= col; i++)
		for(int j = 1; j <= row; j++){
			cin >> map[i][j];
			if(map[i][j] == 1){
				q.push(tomato(j,i,0));
			}
			else if(map[i][j] == 0)
				fin = false;
		}

	if(fin){
		cout << 0;
		return 0;
	}

	int cnt;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		cnt = q.front().count;
		q.pop();
		for(int i = 0 ; i < 4; i++){
			int movex = x + dirX[i];
			int movey = y + dirY[i];
			if(movey > 0 && movex > 0 && movey <= col && movex <= row){
				if(map[movey][movex] == 0 && check[movey][movex] == 0){
					check[movey][movex] = 1;
					map[movey][movex] = 1;
					q.push(tomato(movex, movey, cnt+1));
				}
			}
		}
	}

	for(int i = 1; i <= col; i++)
		for(int j = 1; j <= row; j++)
			if(map[i][j] == 0){
				cout << -1;
				return 0;
			}
	cout << cnt;		
}