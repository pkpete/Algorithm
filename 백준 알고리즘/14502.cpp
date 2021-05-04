#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[9][9];
int copy_map[9][9];
vector<pair<int,int>> zero, v;
queue<pair<int,int>> virus;
int count_zero;
int wall[3];
int answer = -1;
int row, col;
int dirX[4] = {1,-1,0,0};
int dirY[4] = {0,0,1,-1};

void spread_virus(){
	for(int i = 1; i<= col; i++)
		for(int j = 1; j<= row; j++)
			copy_map[i][j] = map[i][j];
	//벽 세우기
	for(int i = 0 ; i < 3; i++){
		int x = zero[wall[i]].first;
		int y = zero[wall[i]].second;
		copy_map[y][x] = 1;
	}
	//바이러스 위치 정보 큐에 담기
	for(int i = 0; i < v.size(); i++)
		virus.push(make_pair(v[i].first, v[i].second));
	//바이러스 퍼짐
	while(!virus.empty()){
		int x = virus.front().first;
		int y = virus.front().second;
		virus.pop();
		for(int i = 0; i < 4; i++){
			int movex = x + dirX[i];
			int movey = y + dirY[i];
			if(movex>0 && movey>0 && movex<=row && movey<=col){
				if(copy_map[movey][movex] == 0){
					copy_map[movey][movex] = 2;
					virus.push(make_pair(movex,movey));
				}
			}
		}
	}
	//안전영역 크기 세기
	int cnt = 0;
	for(int i = 1; i<= col; i++)
		for(int j = 1; j<= row; j++)
			if(copy_map[i][j] == 0) cnt++;
		
	if(cnt > answer)
		answer = cnt;
}

void make_wall(int index, int num_of_wall){
	if(num_of_wall == 3)
		spread_virus();
	else{
		for(int i = index; i < count_zero; i++){
			wall[num_of_wall] = i;
			make_wall(i+1, num_of_wall+1);
		}
	}
}

int main(){
	cin >> col >> row;
	for(int i = 1; i <= col; i++){
		for(int j =1; j<= row; j++){
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];

			if(map[i][j] == 0)	//벽을 세울 수 있는 위치
				zero.push_back(make_pair(j,i));
			else if(map[i][j] == 2)	//바이러스 위치
				v.push_back(make_pair(j,i));
		}
	}
	count_zero = zero.size();

	//벽만들기
	make_wall(0,0);
	cout << answer;
}