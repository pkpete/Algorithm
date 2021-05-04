#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	long long tot = 0; int max_num = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		tot += a;
		max_num = max(max_num, a);
	}
	if (max_num <= (tot - max_num)) {
		cout << (tot & 1);
	}
	else {
		cout << max_num - (tot - max_num);
	}
}