#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int max_num = -1;
	for (int i = 1; i <= b; i++) {
		int tmp = a * i;
		int num = 0;
		while (tmp) {
			num = num * 10 + tmp % 10;
			tmp /= 10;
		}
		max_num = max(num, max_num);
	}
	cout << max_num;
}