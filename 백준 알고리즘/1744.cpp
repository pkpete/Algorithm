#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	int answer = 0;
	cin >> n;
	vector<int> pos, one, zero, neg;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 1) {
			pos.push_back(tmp);
		}
		else if (tmp == 1)
			one.push_back(1);
		else if (tmp == 0)
			zero.push_back(0);
		else
			neg.push_back(tmp);
	}

	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end());

	for (int i = 0; i < pos.size(); i = i + 2) {
		if (i + 1 < pos.size()) {
			answer = answer + (pos[i] * pos[i + 1]);
		}
		else
			answer += pos[i];
	}

	answer += one.size();

	for (int i = 0; i < neg.size(); i = i + 2) {
		if (i + 1 < neg.size()) {
			answer = answer + (neg[i] * neg[i + 1]);
		}
		else {
			if (zero.size() == 0) {
				answer += neg[i];
			}
		}
	}

	cout << answer << "\n";
}