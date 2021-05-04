#include <iostream>
#include <string>
using namespace std;
int arr[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
int main() {
	string str;
	cin >> str;
	int sum = str.size();
	for (int i = 0; i < str.size(); i++) {
		sum += arr[str[i] - 'A'];
	}
	cout << sum;
}