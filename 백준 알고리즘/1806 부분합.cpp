#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int n, s;
int main() {
	cin >> n >> s;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		sum += tmp;
		arr.push_back(tmp);
	}
	if (sum < s) {
		cout << 0;
		return 0;
	}
	int ptr = 0, answer = 100001;
	sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		while (sum >= s) {
			sum -= arr[ptr];
			answer = min(answer, i - ptr+1);
			ptr++;
		}
	}
	cout << answer;
}