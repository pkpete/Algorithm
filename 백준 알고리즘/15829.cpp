#include <iostream>
#include <string>
using namespace std;
int main() {
	int l;
	cin >> l;
	string str;
	cin >> str;
	long long sum = 0;
	long long r = 1;
	for (int i = 0; i < str.size(); i++) {
		sum = (sum + (str[i] -'0'- 48) * r) % 1234567891;
		r = r * 31 % 1234567891;
	}
	cout << sum;
}