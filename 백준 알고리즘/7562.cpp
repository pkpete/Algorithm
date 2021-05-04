#include <iostream>
#include <queue>
using namespace std;
const int MAX = 301;

int check[MAX][MAX];
int size,a,b,c,d;
int dirX[8] = {1,2,2,1,-1,-2,-2,-1};
int dirY[8] = {-2,-1,1,2,2,1,-1,-2};

void clearMap(){
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			check[i][j] = 0;
}

void bfs(){
	queue<pair<int,int>> q;
	q.push(make_pair(a,b));
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x==c && y==d) break;
		for(int i = 0; i < 8; i++){
			int movex = x + dirX[i];
			int movey = y + dirY[i];
			if(movex >= 0 && movey >=0 && movex<size && movey<size){
				if(check[movey][movex] == 0){
					check[movey][movex] = check[y][x] + 1;
					q.push(make_pair(movex,movey));
				}
			}
		}
	}
	cout << check[d][c] << "\n";
} 

int main(){
	int testcase;
	cin >> testcase;
	for(int i = 0; i < testcase; i++){
		cin >> size;
		cin >> a >> b >> c >> d;
		bfs();
		clearMap();
	}
}