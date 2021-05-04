#include <iostream>
#include <deque>
using namespace std;
struct direction{
	int x;
	char c;
};
direction arr[101];
int map[102][102];
int check[102][102];
int dirX[4]={1,0,-1,0};	//동남서북
int dirY[4]={0,1,0,-1};

int main(){
	int board_size, num_of_apple, change_dir;
	cin >> board_size >> num_of_apple;
	for(int i = 0 ; i < num_of_apple; i++){
		int row, col;
		cin >> row >> col;
		map[row][col] = 1;	// apple = 1
	}
	cin >> change_dir;
	for(int i = 0 ; i < change_dir; i++){
		int x; char c;
		cin >> x >> c;
		arr[i].x = x;
		arr[i].c = c;
	}
	int time = 1, l = 0;
	int dir = 0;
	deque<pair<int,int>> snake;
	snake.push_back(make_pair(1,1));
	check[1][1] = 1;
	while(1){
		int snake_tail_x = snake.front().first;
		int snake_tail_y = snake.front().second;
		int snake_head_x = snake.back().first + dirX[dir];
		int snake_head_y = snake.back().second + dirY[dir];

		//뱀의 머리가 보드 크기에 닿으면
		if(snake_head_x > board_size || snake_head_y > board_size || snake_head_x < 1 || snake_head_y < 1)
			break;
		//뱀이 자기 몸에 닿으면
		if(check[snake_head_y][snake_head_x] == 1)
			break;
		else check[snake_head_y][snake_head_x] = 1;

		//사과가 있으면 몸의 길이 길어짐
		if(map[snake_head_y][snake_head_x] == 1){
			snake.push_back(make_pair(snake_head_x, snake_head_y));
			map[snake_head_y][snake_head_x] = 0;
		}
		else{	//아무것도 없으면
			snake.pop_front();
			check[snake_tail_y][snake_tail_x] = 0;
			snake.push_back(make_pair(snake_head_x, snake_head_y));
		}

		int change_time = arr[l].x;
		char change_dir = arr[l].c;
		if(change_time == time){
			l++;
			if(change_dir == 'L'){//왼쪽으로
				dir = (dir + 3) % 4;
			}
			else if(change_dir =='D'){//오른쪽으로
				dir = (dir + 1) % 4;
			}
		}
		
		time++;
	}
	cout << time;
}