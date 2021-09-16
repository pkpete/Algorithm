#include <iostream>
using namespace std;
int dirx[8] = { -1,1,2,2,1,-1,-2,-2 };
int diry[8] = { -2,-2,-1,1,2,2,1,-1 };
int main() {
	string s;
	cin >> s;
	int y = s[1] - '1', x = s[0] - 'a';
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int movex = x + dirx[i];
		int movey = y + diry[i];
		if (movex >= 0 && movex < 8 && movey >= 0 && movey < 8)
			cnt++;
	}
	cout << cnt;
}