#include <iostream>
#include <vector>
using namespace std;
int arr[10001];
int main() {
	for (int i = 1; i < 10001; i++) {
		int num = i;
		int tmp = i;
		while (num > 0) {
			tmp += num % 10;
			num /= 10;
		}
		arr[tmp] = 1;
	}
	for (int i = 1; i < 10001; i++) {
		if (arr[i] == 0)
			cout << i << "\n";
	}
}