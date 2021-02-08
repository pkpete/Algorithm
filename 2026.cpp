#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k, n, f;
int num_friend[901];
bool is_friend[901][901];
bool select_friend[901];

void input() {
	cin >> k >> n >> f;
	for (int i = 0; i < f; i++) {
		int a, b;
		cin >> a >> b;
		is_friend[a][b] = is_friend[b][a] = true;
		num_friend[a]++;
		num_friend[b]++;
	}
}

bool check_friend(int num) {
	for (int i = 1; i <= n; i++) {
		if (select_friend[i]) {
			if (!is_friend[i][num]) return false;
		}
	}
	return true;
}

void make_friend(int cnt) {
	if (cnt == k) {
		for (int i = 1; i <= n; i++) {
			if (select_friend[i])
				cout << i << "\n";
		}
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		if (!select_friend[i] && check_friend(i)) {
			select_friend[i] = true;
			make_friend(cnt + 1);
			select_friend[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	input();
	for (int i = 1; i <= n; i++) {
		if (num_friend[i] >= k-1) {
			select_friend[i] = true;
			make_friend(1);
			select_friend[i] = false;
		}
	}
	cout << -1 << "\n";
}