#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> music;

bool func(int mid) {
	int sum = 0,  cnt = 1;;

	for (int i = 0; i < n; i++) {
		if (music[i] > mid) return false;
		sum += music[i];
		if (sum > mid) {
			sum = music[i];
			cnt++;
		}
	}
	return m >= cnt;
}

int main() {
	cin >> n >> m;
	music = vector<int>(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> music[i];
		sum += music[i];
	}
	int left = 1, right = sum, answer = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (func(mid)) {
			answer = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << answer;
}