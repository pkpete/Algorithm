#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, b, c; cin >> n;
	vector<int> ppl(n);
	for (int i = 0; i < n; i++) {
		cin >> ppl[i];
	}
	cin >> b >> c;
	
	long answer = n;
	for (int i = 0; i < n; i++) {
		ppl[i] -= b;
		if (ppl[i] > 0) {
			if (ppl[i] % c == 0)
				answer += ppl[i] / c;
			else
				answer += ppl[i] / c + 1;
		}
	}

	cout << answer;
}