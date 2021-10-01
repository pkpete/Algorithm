#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int MAX = 10000;
int visit[MAX];
int main() {
	int testcase; cin >> testcase;
	while (testcase--) {

		for (int i = 0; i < MAX; i++)
			visit[i] = 0;

		int a, b; 
		cin >> a >> b;

		queue<pair<int, string>> q;
		visit[a] = 1;
		q.push({ a, "" });

		while (!q.empty()) {
			int num = q.front().first;
			string answer = q.front().second;
			q.pop();

			if (b == num) {
				cout << answer << endl;
				break;
			}

			// D
			int tmp = (num * 2) % MAX;
			if (visit[tmp] == 0) {
				visit[tmp] = 1;
				q.push({ tmp, answer + "D" });
			}

			// S
			tmp = num - 1;
			if (tmp < 0) tmp = 9999;
			if (visit[tmp] == 0) {
				visit[tmp] = 1;
				q.push({ tmp, answer + "S" });
			}

			// L
			tmp = (num % 1000) * 10 + (num / 1000);
			if (visit[tmp] == 0) {
				visit[tmp] = 1;
				q.push({ tmp, answer + "L" });
			}

			//R
			tmp = (num % 10) * 1000 + (num / 10);
			if (visit[tmp] == 0) {
				visit[tmp] = 1;
				q.push({ tmp, answer + "R" });
			}
		}
	}
}