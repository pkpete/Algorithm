#include <iostream>
using namespace std;
int map[130][130];
int white = 0, blue = 0;
int n;
void divide(int x, int y, int x2, int y2){
	int countWhite = 0, countBlue = 0;
	for(int i = y; i <= y2; i++){
		for(int j = x; j <= x2; j++){
			if(map[i][j] == 1) countBlue++;
			else countWhite++;
		}
	}
	if(countBlue == 0) white++;
	else if(countWhite == 0) blue++;
	else{
		divide(x,y,(x+x2)/2,(y+y2)/2);
		divide((x+x2)/2 + 1,y, x2, (y+y2)/2); 
		divide(x, (y+y2)/2+1, (x+x2)/2, y2);
		divide((x+x2)/2+1, (y+y2)/2+1, x2, y2);
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> map[i][j];
		}
	}
	divide(1,1,n,n);
	cout << white << endl << blue << endl;
}