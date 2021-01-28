#include <iostream>
using namespace std;
int n;
int arr[10001];
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		for (int j = start; j < end; j++) {
			arr[j] = 1;
		}
	}
}
int main() {
	input();
	int answer = 0;
	bool line = false;
	for (int i = 1; i < 10001; i++) {
		if (arr[i] == 1)
			answer++;
	}
	cout << answer << "\n";
}