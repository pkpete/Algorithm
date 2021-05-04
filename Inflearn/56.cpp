#include <iostream>
using namespace std;
void recursion(int n) {
	if (n == 1) {
		cout << n << " ";
		return;
	}
	recursion(n - 1);
	cout << n << " ";
}
int main() {
	int n;
	cin >> n;
	recursion(n);
}