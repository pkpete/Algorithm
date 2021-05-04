#include <iostream>
#include <queue>
using namespace std;
const int MAX = 101;
int map[MAX][MAX][MAX];
int check[MAX][MAX][MAX];
int dirX[6] = {1,-1,0,0,0,0};//동서남북위아래
int dirY[6] = {0,0,1,-1,0,0};
int dirZ[6] = {0,0,0,0,1,-1};
struct tomato{
	int x,y,z,count;
	tomato(int a, int b,int c,int d):x(a), y(b), z(c), count(d){}
};
int main(){
	int row, col, height;
	cin >> row >> col >> height;
	bool fin = true;
	queue<tomato> q;
	for(int k = 1; k <= height; k++)
		for(int i = 1; i <= col; i++)
			for(int j = 1; j <= row; j++){
				cin >> map[i][j][k];
				if(map[i][j][k] == 1)
					q.push(tomato(j,i,k,0));
				else if(map[i][j][k] == 0)
					fin = false;
			}

	if(fin){ cout << 0; return 0;}
	int cnt;
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		cnt = q.front().count;
		q.pop();
		for(int i = 0 ; i < 6; i++){
			int movex = x + dirX[i];
			int movey = y + dirY[i];
			int movez = z + dirZ[i];
			if(movey > 0 && movex > 0 && movey <= col && movex <= row && movez>0 && movez<=height){
				if(map[movey][movex][movez] == 0 && check[movey][movex][movez] == 0){
					check[movey][movex][movez] = 1;
					map[movey][movex][movez] = 1;
					q.push(tomato(movex, movey, movez, cnt+1));
				}
			}
		}
	}
	for(int k = 1; k <= height; k++)
		for(int i = 1; i <= col; i++)
			for(int j = 1; j <= row; j++)
				if(map[i][j][k] == 0){
					cout << -1;
					return 0;
				}
	cout << cnt;
}