#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x, y;
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		x.push_back(tmp1);
		y.push_back(tmp2);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int mx = x[x.size() / 2], my = y[y.size() / 2];
	int answer = 0;
	for (int i = 0; i < m; i++) {
		answer += abs(mx - x[i]) + abs(my - y[i]);
	}
	cout << answer;
}