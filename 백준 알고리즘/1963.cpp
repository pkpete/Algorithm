#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
int arr[10000];
int check[10000];
vector<int> v;
int a, b;
void prime_num() {
	for (int i = 2; i < 10000; i++) {
		if (arr[i] == 0) {
			if (i >= 1000) {
				v.push_back(i);
			}
			for (int j = i * 2; j < 10000; j = j + i) {
				arr[j] = 1;
				check[j] = 1;
			}
		}
	}
}
void solve() {
	check[a] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(a, 0));
	while (!q.empty()) {
		int top = q.front().first;
		int cnt = q.front().second;
		if (top == b) {
			cout << cnt << "\n";
			return;
		}
		else {
			int num1 = 10, num2 = 1;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					int tmp = (top / num1) * num1 + (top % num2);
					if (i == 3 && j == 0) continue;
					tmp = tmp + (num2 * j);
					if (arr[tmp] == 0 && check[tmp] == 0) {
						check[tmp] = 1;
						q.push(make_pair(tmp, cnt + 1));
					}
				}
				num1 *= 10;
				num2 *= 10;
			}
		}
		q.pop();
	}
	cout << "Impossible" << "\n";
}
int main() {
	prime_num();
	int testcase;
	cin >> testcase;
	while (testcase > 0) {
		cin >> a >> b;
		solve();
		for (int i = 0; i < v.size(); i++) {
			check[v[i]] = 0;
		}
		testcase--;
	}
}