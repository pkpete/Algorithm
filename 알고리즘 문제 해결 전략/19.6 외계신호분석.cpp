#include <iostream>
#include <queue>
using namespace std;

int solve2(vector<int> signals, int k) {
	int answer = 0;
	int sum = signals[0];
	int tail = 0;
	for (int i = 0; i < signals.size(); i++) {
		while (sum < k && tail + 1 < signals.size()) {
			sum += signals[++tail];
		}
		if (sum == k) answer++;
		sum -= signals[i];
	}
	return answer;
}

int main() {
	vector<int> signals;
	for (int i = 0; i < 8; i++) {
		int n;
		cin >> n;
		signals.push_back(n);
	}
	cout << solve2(signals, 7);
}