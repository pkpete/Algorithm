#include <iostream>
using namespace std;

int col_size, row_size, cnt = 0;
int map[51][51];
int check[51][51];
int dirX[4] = {0,1,0,-1};	//북동남서
int dirY[4] = {-1,0,1,0};

bool in_map(int y, int x){
	if(y>=0 && x>=0 && y<col_size && x<row_size)
		return true;
	else return false;
}

void clean(int y, int x, int direction){
	check[y][x] = 1;
	cnt++;
	int move = direction; 
	for(int i = 0; i < 4; i++){
		move = (move+3) % 4; //방향 기준 왼쪽
		int movex = x + dirX[move];
		int movey = y + dirY[move];
		if(in_map(movey,movex) && map[movey][movex]==0 && check[movey][movex] == 0){ //움직이려는 방향이 지도 안에잇고 벽이 아니고 청소하지 않았으면
			clean(movey,movex,move);
			break;
		}
		if(i==3){
			move = (direction+2)%4;	// 후진
			movex = x + dirX[move];
			movey = y + dirY[move];
			if(map[movey][movex] == 1) break;
			if(in_map(movey,movex) && map[movey][movex]==0){
				i = -1;
				y = movey;
				x = movex;
				move=direction;
			}
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int y, x, direction;
	cin >> col_size >> row_size >> y >> x >> direction;

	for(int i = 0; i < col_size; i++)
		for(int j = 0; j < row_size; j++)
			cin >> map[i][j];
	clean(y,x, direction);
	cout << cnt;
}
