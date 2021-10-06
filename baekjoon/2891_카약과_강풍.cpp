#include <iostream>
using namespace std;
int team[12];
int main() {
	int n, s, r;
	cin >> n >> s >> r;
	for (int i = 1; i <= n; i++)
		team[i] = 1;

	for (int i = 0; i < s; i++) {
		int tmp;
		cin >> tmp;
		team[tmp] -= 1;
	}
	for (int i = 0; i < r; i++) {
		int tmp;
		cin >> tmp;
		team[tmp] += 1;
	}

	for (int i = 1; i <= n; i++) {
		if (team[i] == 0) {
			if (team[i - 1] == 2) {
				team[i - 1] -= 1;
				team[i] += 1;
			}
			else if(team[i+1] == 2){
				team[i + 1] -= 1;
				team[i] += 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (team[i] == 0)
			cnt++;
	}
	cout << cnt;
}