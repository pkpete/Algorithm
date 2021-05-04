#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;
deque<int> wheel[4];
int check[4];
string str;
int k;
vector<pair<int,int>> arr;

void rotate_wheel(int index, int dir){
	check[index] = 1;
	int left = wheel[index][6];
	int right = wheel[index][2];
	if(index-1>=0 && check[index-1]==0){
		if(wheel[index-1][2]!=left)
			rotate_wheel(index-1, dir*(-1));
	}
	if(index+1<4 && check[index+1] == 0){
		if(wheel[index+1][6]!=right)
			rotate_wheel(index+1, dir*(-1));
	}
	if(dir==1){
		int tmp = wheel[index].back();
		wheel[index].pop_back();
		wheel[index].push_front(tmp);
	}
	else{
		int tmp = wheel[index].front();
		wheel[index].pop_front();
		wheel[index].push_back(tmp);
	}
}

void input(){
	for(int i = 0; i < 4; i++){
		cin >> str;
		for(int j = 0; j < str.size(); j++){
			int num = str[j]-'0';
			wheel[i].push_back(num);
		}
	}
	cin >> k;
	arr = vector<pair<int,int>> (k);
	for(int i = 0; i < k; i++){
		cin >> arr[i].first >> arr[i].second;
		rotate_wheel(arr[i].first-1, arr[i].second);
		for(int j = 0; j < 4; j++)
			check[j] = 0;
	}
}

int main(){

	input();
	int sum = 0;
	for(int i = 0; i < 4; i++){
		if(wheel[i][0] == 1){
			if(i==0) sum++;
			else if(i==1) sum += 2;
			else if(i==2) sum += 4;
			else sum += 8;
		}
	}
	cout << sum;
}