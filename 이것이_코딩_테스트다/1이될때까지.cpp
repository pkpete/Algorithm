#include <iostream>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int answer = 0;
	while (1) {
		if (n == 1)
			break;
		if (n % k == 0) {
			n /= k;
		}
		else n--;
		answer++;
	}
	cout << answer;
}