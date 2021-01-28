#include <iostream>
using namespace std;
int n, k;
int arr[31][31];
void input() {
	cin >> n >> k;
}
int main() {
	input();

	for (int i = 1; i <= n; i++) {
		arr[i][1] = 1;
		arr[i][i] = 1;
		for (int j = 2; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	cout << arr[n][k];
}