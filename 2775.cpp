#include <iostream>
using namespace std;
int map[15][15];
int main() {
	for (int i = 0; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			if (i == 0) map[i][j] = j;
			else {
				map[i][j] = map[i][j - 1] + map[i - 1][j];
			}
		}
	}
	int testcase;
	cin >> testcase;
	while (testcase > 0) {
		int k, n;
		cin >> k >> n;	//kÃş nÈ£
		cout << map[k][n] << endl;
		testcase--;
	}
}