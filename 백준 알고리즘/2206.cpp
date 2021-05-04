#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int map[1001][1001];
int check[1001][1001][2];
int dirX[4] = {1,-1,0,0};	//동서남북
int dirY[4] = {0,0,1,-1};
int col_size, row_size;
struct wall{
	int x, y, cnt_break;
	wall(int a, int b, int c):x(a), y(b), cnt_break(c){}
};
queue<wall> q;
void input(){
	cin >> col_size >> row_size;
	string str;
	for(int i = 1; i <= col_size; i++){
		cin >> str;
		for(int j = 0; j < str.size(); j++){
			map[i][j+1] = str[j]-'0';
		}
	}
}
bool inmap(int y, int x){
	if(y>=1&&y<=col_size&&x>=1&&x<=row_size)
		return true;
	else return false;
}
int main(){
	input();
	q.push(wall(1,1,0));
	check[1][1][0] = 1;//y,x,벽 뚫기 가능
	while(!q.empty()){
		wall current = q.front();
		q.pop();
		if(current.x == row_size && current.y == col_size){
			cout << check[current.y][current.x][current.cnt_break];
			return 0;
		}
		for(int i = 0; i < 4; i++){
			int movex = current.x + dirX[i];
			int movey = current.y + dirY[i];
			if(inmap(movey,movex) && map[movey][movex] == 0 && check[movey][movex][current.cnt_break] == 0){	// 벽이 없고, 첫 방문
				check[movey][movex][current.cnt_break] = check[current.y][current.x][current.cnt_break]+1;
				q.push(wall(movex,movey,current.cnt_break));
			}
			else if(inmap(movey,movex) && map[movey][movex] == 1 && current.cnt_break == 0){
				check[movey][movex][current.cnt_break+1] = check[current.y][current.x][current.cnt_break]+1;
				q.push(wall(movex,movey,current.cnt_break+1));
			}
		}
	}
	cout << -1;
}