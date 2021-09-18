#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, string>> arr(n);
	string name;
	int score;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		cout << arr[i].second << " ";
	}
}