#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[100001];
bool check[100001];
int main() {
	int n, k;
	cin >> n >> k;
	queue<pair<int, int>> q;
	q.push(make_pair(0, n));
	
	while (!q.empty()) {
		int cnt = q.front().first;
		int cur = q.front().second;
		check[cur] = true;
		q.pop();
		if (cur == k) {
			cout << cnt;
			return 0;
		}
		int move = cur - 1;
		if (move >= 0 && move < 100001 && !check[move])
			q.push(make_pair(cnt + 1, move));
		
		move = cur + 1;
		if (move >= 0 && move < 100001 && !check[move])
			q.push(make_pair(cnt + 1, move));
		
		move = 2 * cur;
		if (move >= 0 && move < 100001 && !check[move])
			q.push(make_pair(cnt + 1, move));
	}

}