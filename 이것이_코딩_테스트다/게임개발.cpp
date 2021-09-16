#include <iostream>
using namespace std;

int n, m;
int map[51][51];
int dirx[4] = { 0,1,0,-1 };
int diry[4] = { -1,0,1,0 };

int main() {
	 cin >> n >> m;
	 int y, x, d; 
	 cin >> y >> x >> d;

	 for (int i = 0; i < n; i++) 
		 for (int j = 0; j < m; j++) 
			 cin >> map[i][j];

	 int cnt = 1;
	 map[y][x] = 2;
	 while (1) {
		 int i;
		 for (i = 0; i < 4; i++) {
			 d = (d + 3) % 4;
			 int movey = y + diry[d], movex = x + dirx[d];
			 if (movex >= 0 && movey >= 0 && movex < m && movey < n && map[movey][movex] == 0) {
				 y = movey, x = movex;
				 map[y][x] = 2;
				 cnt++;
				 break;
			 }
		 }
		 if (i == 4) {
			 int movey = y + diry[(d + 2) % 4], movex = x + dirx[(d + 2) % 4];
			 if (movex < 0 || movey < 0 || movex >= m || movey >= n || map[movey][movex] == 1) {
				 break;
			 }
			 y = movey, x = movex;
		 }
	 }
	 cout << cnt;
}