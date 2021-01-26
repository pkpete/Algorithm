#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, money;
vector<int> city;

void input() {
	cin >> n;
	city = vector<int>(n);
	for (int i = 0; i < n; i++) 
		cin >> city[i];
	cin >> money;
	sort(city.begin(), city.end());
}

bool valid(int num) {
	int tmp = money;
	for (int i = 0; i < n; i++) {
		if (num >= city[i]) {
			tmp -= city[i];
		}
		else {
			tmp -= num;
		}
		if (tmp < 0) return false;
	}
	return true;
}

int main() {
	input();
	long long ans = -1;
	long long left = 0, right = city[city.size() - 1], mid;
	while (left <= right) {
		mid = (left + right) / 2;

		if (valid(mid)) {
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << "\n";
}