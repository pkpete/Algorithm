#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int aws = 0, acc = 0;
	for (int i = 0; i < n; i++) {
		acc += v[i];
		aws += acc;
	}

	cout << aws;

}