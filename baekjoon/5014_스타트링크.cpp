#include <iostream>
#include <queue>
using namespace std;
bool stairs[1000001];
int main() {
	int f, cur, target, u, d;	
	cin >> f >> cur >> target >> u >> d;
	queue<pair<int,int>> q;
	q.push({ cur, 0 });
	stairs[cur] = true;
	while (!q.empty()) {
		int floor = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (floor == target) {
			cout << cnt;
			return 0;
		}
		if ((floor + u <= f) && !stairs[floor + u]) {
			stairs[floor + u] = true;
			q.push({ floor + u, cnt + 1 });
		}
		if ((floor - d >= 1) && !stairs[floor - d]) {
			stairs[floor - d] = true;
			q.push({ floor - d, cnt + 1 });
		}
	}
	cout << "use the stairs";
}