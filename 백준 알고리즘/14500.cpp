#include <iostream>
using namespace std;
int row_size, col_size;
int map[501][501];
int check[501][501];
int answer = -1;
int arr[4];
int dirX[4] = {1,-1,0,0};	//µ¿¼­³²ºÏ
int dirY[4] = {0,0,1,-1};

void find(int y, int x, int cnt){
	if(cnt == 4){
		int sum = 0;
		for(int i = 0; i < 4; i++){
			sum += arr[i];
		}
		if(sum > answer) answer = sum;
	}
	else{
		for(int i = 0; i < 4; i++){
			int movex = x + dirX[i];
			int movey = y + dirY[i];
			if(movex>0 && movey>0 && movex<=row_size && movey<=col_size){
				if(check[movey][movex] == 0){
					check[movey][movex] = 1;
					arr[cnt] = map[movey][movex];
					find(movey, movex, cnt+1);
					find(y,x,cnt+1);
					check[movey][movex] = 0;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> col_size >> row_size;

	for(int i = 1; i <= col_size; i++){
		for(int j = 1; j <= row_size; j++){
			cin >> map[i][j];
		}
	}

	for(int i = 1; i <= col_size; i++)
		for(int j = 1; j <= row_size; j++){
			arr[0] = map[i][j];
			check[i][j] = 1;
			find(i,j,1);
			check[i][j] = 0;
		}

	cout << answer;
}