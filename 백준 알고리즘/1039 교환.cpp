#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int answer = -1;
int main() {
	string str; int k;
	cin >> str >> k;

	queue<pair<int, string>> q;
	q.push(make_pair(0, str));
	while (!q.empty()) {
		int qsize = q.size();
		set<string> visit;
		for (int l = 0; l < qsize; l++) {
			string num = q.front().second;
			int cnt = q.front().first;
			q.pop();
			if (cnt == k) {
				answer = max(answer, stoi(num));
				continue;
			}
			for (int i = 0; i < num.size() - 1; i++) {
				for (int j = i + 1; j < num.size(); j++) {
					if (i == 0 && num[j] == '0') continue;
					swap(num[i], num[j]);
					if (visit.find(num) == visit.end()) {
						visit.insert(num);
						q.push(make_pair(cnt + 1, num));
					}
					swap(num[i], num[j]);
				}
			}

		}
		/*set<string> visit;
		int cnt = q.front().first;
		string num = q.front().second;
		q.pop();
		if (cnt == k) {
			answer = max(answer, stoi(num));
			continue;
		}

		for (int i = 0; i < num.size()-1; i++) {
			for (int j = i + 1; j < num.size(); j++) {
				if (i == 0 && num[j] == '0') continue;
				swap(num[i], num[j]);
				if (visit.find(num) == visit.end()) {
					visit.insert(num);
					q.push(make_pair(cnt + 1, num));
				}
				
				swap(num[i], num[j]);
			}
		}*/
	}
	cout << answer;
} 