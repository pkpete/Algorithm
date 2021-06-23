#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[26][26], n;
bool check[26][26];
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };
vector<int> houses;

void input() {
	string str;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j] - '0';
		}
	}
}

void dfs(int y, int x, int &cnt) {
	cnt++;
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int movex = x + dirX[i];
		int movey = y + dirY[i];
		if (movex >= 0 && movey >= 0 && movex < n && movey < n && map[movey][movex] == 1 && !check[movey][movex]) {
			dfs(movey, movex, cnt);
		}
	}

}

void solve() {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (map[i][j] == 1 && !check[i][j]) {
				int cnt = 0;
				dfs(i, j, cnt);
				houses.push_back(cnt);
			}
}

int main() {
	
	input();
	solve();
	sort(houses.begin(), houses.end());

	cout << houses.size() << endl;
	for (int i = 0; i < houses.size(); i++)
		cout << houses[i] << endl;
}