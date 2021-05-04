#include <iostream>
#include <math.h>
using namespace std;
int main() {
	long long n;
	cin >> n;
	for (int i = 0; i < 31; i++) {
		if (n == pow(2.0, i)) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}