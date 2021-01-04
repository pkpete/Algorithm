#include <iostream>
using namespace std;
int count0 = 0, count1 = 0, count_1 = 0;
int map[2187][2187];
void divide(int x, int y, int size){
	int cnt0 = 0, cnt1 = 0, cnt_1 = 0;
	for(int i = y; i < y+size; i++){
		for(int j = x; j < x+size; j++){
			if(map[i][j] == -1) cnt_1++;
			else if(map[i][j] == 0) cnt0++;
			else cnt1++;
		}
	}
	if(cnt_1 == 0 && cnt0 == 0) count1++;
	else if(cnt_1 == 0 && cnt1 == 0) count0++;
	else if(cnt1 == 0 && cnt0 == 0)count_1++;
	else{
		for(int i = 0; i < 3; i ++)
			for(int j = 0; j < 3; j++)
				divide(x+i*(size/3), y+j*(size/3),size/3);
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++)
		for(int j = 0 ; j < n; j++)
			cin >> map[i][j];
	divide(0,0,n);
	cout << count_1 << endl << count0 << endl << count1;
}