#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[21][21];
int dirX[4] = {1,-1,0,0}; //µ¿¼­ºÏ³²
int dirY[4] = {0,0,-1,1};
int dice[6];

void move_dice(int num){
	switch(num){	//µ¿ ¼­ ºÏ ³²
	case 1: 
		swap(dice[0],dice[5]);
		swap(dice[3],dice[4]);
		swap(dice[0],dice[3]);
		break;
	case 2:
		swap(dice[0],dice[4]);
		swap(dice[0],dice[3]);
		swap(dice[0],dice[5]);
		break;
	case 3:
		swap(dice[0],dice[1]);
		swap(dice[0],dice[3]);
		swap(dice[0],dice[2]);
		break;
	case 4: 
		swap(dice[0],dice[2]);
		swap(dice[0],dice[3]);
		swap(dice[0],dice[1]);
		break;
	}
}

int main(){
	int col_size, row_size, x, y, num_of_instruct;
	cin >> col_size >> row_size >> y >> x >> num_of_instruct;
	for(int i = 0; i < col_size; i++){
		for(int j = 0; j < row_size; j++){
			cin >> map[i][j];
		}
	}
	vector<int> arr(num_of_instruct);
	for(int i = 0; i < num_of_instruct; i++)
		cin >> arr[i];

	for(int i = 0 ; i < num_of_instruct; i++){
		int num = arr[i]-1;
		int movex = x + dirX[num];
		int movey = y + dirY[num];
		if(movex>=0 && movey>=0 && movex<row_size && movey<col_size){
			x = movex;
			y = movey;
			move_dice(num+1);
			if(map[movey][movex] == 0){
				map[movey][movex] = dice[3];
			}
			else{
				dice[3] = map[movey][movex];
				map[movey][movex] = 0;
			}
			cout << dice[0]<< "\n";
		}
	}
}