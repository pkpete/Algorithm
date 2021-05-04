#include <iostream>
using namespace std;

int arr[50][50];
int visit[50][50];
int count;
int width, hight, num;
int moveX[4] = {0,0,-1,1};
int moveY[4] = {1,-1,0,0};

int inArea(int x, int y){
	if(x >= 0 && y >= 0 && x < width && y < hight)
		return 1;
	else return 0;
}

void dfs(int x, int y){
	visit[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + moveX[i];
		int ny = y + moveY[i];
		if(inArea(nx, ny) == 1 && arr[nx][ny] == 1 && visit[nx][ny] == 0){
			dfs(nx,ny);
		}
	}
}

void Testcase(){
	cin >> width >> hight >> num;
	for(int k = 0; k < num; k++){
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;		
	}
	for(int i = 0; i < width; i++)
		for(int j = 0; j < hight; j++){
			if(arr[i][j] == 1 && visit[i][j] == 0){
				dfs(i,j);
				count++;
			}
		}
}

void RestArr(){
	for(int i = 0; i < 50; i++)
		for(int j = 0; j < 50; j++){
			arr[i][j] = 0;
			visit[i][j] = 0;
		}
}

int main(){
	int testcase;
	cin >> testcase;
	for(int i = 0; i < testcase; i++){
		Testcase();
		RestArr();
		cout << count << endl;
		count = 0;
	}
}