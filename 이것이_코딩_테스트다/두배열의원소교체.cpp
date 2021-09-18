#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a, b;
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			if (i == 0)
				a.push_back(tmp);
			else
				b.push_back(tmp);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (k && a[i] < b[i]) {
			answer += b[i];
			k--;
		}
		else {
			answer += a[i];
		}
	}

	cout << answer;
}