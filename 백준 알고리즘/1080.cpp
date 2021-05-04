#include <iostream>
using namespace std;
int a[51][51];
int b[51][51];
void change(int y, int x) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			if (a[i][j] == 1) {
				a[i][j] = 0;
			}
			else
				a[i][j] = 1;
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			a[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			b[i][j] = str[j] - '0';
		}
	}

	int cnt = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = 0; j < m-2; j++) {
			if (a[i][j] != b[i][j]) {
				cnt++;
				change(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] != b[i][j]) {
				cnt = -1;
				break;
			}

	cout << cnt << "\n";
}