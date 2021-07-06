#include <iostream>
#include <vector>
using namespace std;
long n, m, sum = 0;
int cnt = 0;
vector<int> v;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}

	int front = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		while (sum > m) {
			sum -= v[front++];
		}
		if (sum == m) cnt++;
	}

	cout << cnt;
}