#include <iostream>
using namespace std;
int n;
int arr[100];
void dfs(int cnt) {
	if (cnt == n + 1) {
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 1)
				cout << i << " ";
		}
		cout << "\n";
	}
	else {
		arr[cnt] = 1;
		dfs(cnt + 1);
		arr[cnt] = 0;
		dfs(cnt + 1);
	}

}
int main() {
	cin >> n;
	dfs(1);
}