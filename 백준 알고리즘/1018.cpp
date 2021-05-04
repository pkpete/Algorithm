#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string chess[50];
string white[8] = { "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
					};
string black[8] = { "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
					};
int checkWhite(int y, int x){
	int count = 0;
	for(int i = y; i < y+8; i++)
		for(int j = x; j < x+8; j++)
			if(chess[i][j] != white[i-y][j-x]) count++;
	return count;
}
int checkBlack(int y, int x){
	int count = 0;
	for(int i = y; i < y+8; i++)
		for(int j = x; j < x+8; j++)
			if(chess[i][j] != black[i-y][j-x]) count++;
	return count;
}
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> chess[i];
	}
	int answer = 100;

	for(int i = 0; i <= n-8; i++){
		for(int j = 0; j <= m-8; j++){
			answer = min(answer, min(checkWhite(i,j), checkBlack(i,j)));
		}
	}
	cout << answer;
}