#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[26];
int n;
vector<string> v;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	for (int i = 0; i < v.size(); i++) {
		int num = 1;
		for (int j = v[i].size() - 1; j >= 0; j--) {
			arr[v[i][j] - 'A'] += num;
			num *= 10;
		}
	}
	sort(arr, arr + 26);
	int num = 9;
	int sum = 0;
	for (int i = 25; i >= 0; i--) {
		if (arr[i] == 0) break;
		sum += arr[i] * num--;
	}
	cout << sum;

}