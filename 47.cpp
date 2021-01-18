#include <iostream>
using namespace std;
int map[51][51];
int dirX[4] = {1,-1,0,0};
int dirY[4] = {0,0,1,-1};
int answer = 0;
int n;
void check(int y, int x){
	for(int i = 0; i < 4; i++){
		int movex = x + dirX[i];
		int movey = y + dirY[i];
		if(x>=0&&y>=0&&x<n&&y<n){
			if(map[movey][movex] >= map[y][x])
				return;
		}
	}
	//cout << map[y][x] << "\n";
	answer++;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> map[i][j];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			check(i,j);
	}
	cout << answer;
}