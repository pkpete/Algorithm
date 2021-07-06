#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, answer = 0;
vector<long long> tree;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		tree.push_back(tmp);
	}

	sort(tree.begin(), tree.end());

	long long left = 0, right = tree[tree.size() - 1];
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < tree[i]) {
				sum += tree[i] - mid;
			}
		}
		if (m <= sum) {
			answer = max(answer, mid);
			left = mid + 1;
		}
		else if(m > sum) {
			right = mid - 1;
		}
	}
	cout << answer;
}