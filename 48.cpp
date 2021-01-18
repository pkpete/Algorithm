#include <iostream>
using namespace std;
int map[9][9];
int main(){
	int sum = 0;
	for(int i = 0; i < 9; i++){
		sum = 0;
		for(int j = 0; j < 9; j++){
			cin >> map[i][j];
			sum += map[i][j];
		}
		int avg = sum / 9;
		int remain = sum % 9;
		int diff = 1000000000;
		int num;
		if(remain >= 5) avg++;
		for(int j = 0; j < 9; j++){
			int tmp = abs(avg-map[i][j]);
			if(tmp < diff){
				diff = tmp;
				num = map[i][j];
			}
		}
		cout << avg << " " << num << endl;
	}

}