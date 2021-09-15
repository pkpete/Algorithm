#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, m, answer = -1;
	cin >> n >> m;
	vector<int> arr(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[j];
		sort(arr.begin(), arr.end());
		answer = max(answer, arr[0]);
	}
	cout << answer;	
}