#include <iostream>
#include <string>
using namespace std;
int map[65][65];

void divide(int x1, int y1, int x2, int y2){
	
	int count0 = 0, count1 = 0;
	for(int i = y1; i <= y2; i++){
		for(int j = x1; j <= x2; j++){
			if(map[i][j] == 1) count1++;
			else count0++;
		}
	}
	if(count0 == 0) cout << 1;
	else if(count1 == 0) cout << 0;
	else{
		cout << "(";
		divide(x1,y1,(x1+x2)/2, (y1+y2)/2);
		divide((x1+x2)/2+1, y1, x2, (y1+y2)/2);
		divide(x1, (y1+y2)/2+1, (x1+x2)/2, y2);
		divide((x1+x2)/2+1, (y1+y2)/2+1, x2, y2);
		cout << ")";
	}

	
}
int main(){
	int n;
	cin >> n;
	string s;
	for(int i = 0 ; i < n; i++){
		cin >> s;
		for(int j = 0; j < n; j++){
			map[i+1][j+1] = s[j] - '0';
		}
	}
	divide(1,1,n,n);
}