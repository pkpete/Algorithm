#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int map[26][26];
int check[26][26];
int cnt = 0;
vector<int> arr;

void dfs(int y, int x){
	check[y][x] = cnt;
	arr[cnt]++;
	if(map[y+1][x] == 1 && check[y+1][x] == 0)
		dfs(y+1,x);
	if(map[y-1][x] == 1 && check[y-1][x] == 0)
		dfs(y-1,x);
	if(map[y][x+1] == 1 && check[y][x+1] == 0)
		dfs(y,x+1);
	if(map[y][x-1] == 1 && check[y][x-1] == 0)
		dfs(y,x-1);
}

int main(){
	int n;
	string s;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s;
		for(int j = 0; j < s.length(); j++){
			map[i][j+1] = s[j] - '0';
		}
	}
	arr.push_back(0);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(map[i][j] == 1 && check[i][j] == 0){
				cnt++;
				arr.push_back(0);
				dfs(i,j);
			}
		}
	}
	cout << cnt << endl;
	sort(arr.begin(), arr.end());
	for(int i = 1; i <= cnt; i++)
		cout << arr[i] << endl;
}