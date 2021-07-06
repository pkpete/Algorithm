#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long x, y;
	cin >> x >> y;
	long long answer = 1000000000;
	int z = y * 100 / x ;

	if (z >= 99) {
		cout << -1;
		return 0;
	}

	long long left = 0, right = 1000000000;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long nx = x + mid;
		long long ny = y + mid;
		int nz = ny * 100 / nx;
		if (nz > z) {
			answer = min(answer, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << answer;
}