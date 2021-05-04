#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*vector<pair<int, int>> v;
vector<int> answer;
int n;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first > b.first) {
		return true;
	}
	else if (a.first == b.first) {
		if (a.second > b.second) {
			return true;
		}
		return false;
	}
	return false;
}
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		v.push_back(make_pair(d, w));
	}
	sort(v.begin(), v.end(), cmp);
	answer = vector<int>(v[0].first);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	for (int i = answer.size() - 1; i >= 0; i--) {
		int index;
		for (int j = 0; j < v.size(); j++) {
			if (v[j].first < i + 1) {
				break;
			}
			if (answer[i] <= v[j].second) {
				answer[i] = v[j].second;
				index = j;
			}
		}
		v[index].second = 0;
	}
	int sum = 0;
	for (int i = 0; i < answer.size(); i++) {
		sum += answer[i];
	}
	cout << sum << "\n";
}*/
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second >= b.second)
		return true;
	return false;
}
int main() {
	int n, d, w;
	vector<pair<int, int>> v;
	int arr[1001] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> w;
		v.push_back(make_pair(d,w));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		int day = v[i].first;
		int score = v[i].second;
		while (day > 0) {
			if (arr[day] == 0) {
				break;
			}
			day--;
		}
		arr[day] = score;
	}
	int sum = 0;
	for (int i = 1; i < 1001; i++) {
		sum += arr[i];
	}
	cout << sum;
}