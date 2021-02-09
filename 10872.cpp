#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int sum = 1;
	for (int i = n; i > 0; i--) {
		sum = sum * i;
	}
	cout << sum;
}