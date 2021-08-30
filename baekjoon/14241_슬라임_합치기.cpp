#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int n;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	int answer = 0;
	while (!pq.empty()) {
		int first = pq.top(); pq.pop();
		if (pq.empty()) break;
		int second = pq.top(); pq.pop();
		answer += first * second;
		pq.push(first + second);
	}
	cout << answer;
}