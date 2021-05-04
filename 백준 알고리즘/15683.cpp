#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct cctv{
	int type, x, y;
	cctv(int a, int b, int c):type(a), x(b), y(c){}
};
int map[8][8];
int check[8][8];
vector<cctv> v;
vector<int> dir;
int col_size, row_size, answer = 100;
int dirX[4] = {1,0,-1,0};	//동남서북
int dirY[4] = {0,1,0,-1};
void input(){
	cin >> col_size >> row_size;
	for(int i = 0; i < col_size; i++){
		for(int j = 0; j < row_size; j++){
			cin >> map[i][j];
			check[i][j] = map[i][j];
			if(map[i][j] >= 1 && map[i][j] <= 5)
				v.push_back(cctv(map[i][j], j, i));
		}
	}
	dir = vector<int>(v.size());
}
void clear_map(){
	for(int i = 0; i < col_size; i++)
		for(int j = 0; j < row_size; j++)
			check[i][j] = map[i][j];
}
void count_space(){
	int cnt = 0;
	for(int i = 0; i < col_size; i++){
		for(int j = 0; j < row_size; j++){
			if(check[i][j] == 0)
				cnt++;
		}
	}
	if(answer > cnt)
		answer = cnt;
}
void check_map(int x, int y, int index){
	int movex = x + dirX[index];
	int movey = y + dirY[index];
	while(movey>=0&&movex>=0&&movey<col_size&&movex<row_size&&map[movey][movex] !=6){
		check[movey][movex]=1;
		movex += dirX[index];
		movey += dirY[index];
	}
}
void cctv_start(int index){
	int direction = dir[index];
	int x = v[index].x;
	int y = v[index].y;
	int type = v[index].type;
	if(type == 1){
		check_map(x,y,direction);
	}
	else if(type == 2){
		if(direction == 0){//동서
			check_map(x,y,0);
			check_map(x,y,2);
		}
		else{//남북
			check_map(x,y,1);
			check_map(x,y,3);
		}
	}
	else if(type == 3){
		check_map(x,y,(direction+1)%4);
		check_map(x,y,direction);
	}
	else if(type == 4){
		check_map(x,y,(direction+1)%4);
		check_map(x,y,direction);
		check_map(x,y,(direction+3)%4);
	}
	else{
		check_map(x,y,0);
		check_map(x,y,1);
		check_map(x,y,2);
		check_map(x,y,3);
	}
}
void dfs(int cnt){
	if(cnt == v.size()){
		for(int i = 0; i < v.size(); i++){
			cctv_start(i);
		}
		count_space();
		clear_map();
		return;
	}
	int x = v[cnt].x;
	int y = v[cnt].y;
	int type = v[cnt].type;
	if(type == 5){	//방향 1개만 있음
		dir[cnt] = -1;
		dfs(cnt+1);
	}
	else if(type == 2){	//방향 2개있음
		for(int i = 0; i < 2; i++){
			dir[cnt] = i;
			dfs(cnt+1);
		}
	}
	else{
		for(int i = 0; i < 4; i++){	
			dir[cnt] = i;
			dfs(cnt+1);
		}
	}
	
}
int main(){
	input();
	
	dfs(0);

	cout << answer;
}