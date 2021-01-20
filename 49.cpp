#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[10][10];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		for(int j = 0; j < n; j++){
			map[j][i] = num;
		}
	}
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		for(int j = 0; j < n; j++){
			map[i][j] = min(map[i][j], num);
		}
	}
	int sum=0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			sum += map[i][j];
	cout << sum;
}