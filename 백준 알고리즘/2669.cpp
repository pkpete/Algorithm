#include <iostream>
using namespace std;
int map[101][101];
int main(){
	int x1, y1, x2, y2;
	for(int i = 0; i < 4; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i = x1; i < x2; i++)
			for(int j = y1; j < y2; j++)
				map[i][j]++;
	}
	int cnt=0;
	for(int i = 0; i < 101; i++)
		for(int j = 0; j < 101; j++)
			if(map[i][j]>0) cnt++;
	cout << cnt;
}