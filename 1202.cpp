#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int, int>> jewel;
vector<pair<int, int>> bag;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int weight, cost;
		cin >> weight >> cost;
		jewel.push_back({ weight, cost });
	}
	//무게 순으로 정렬
	sort(jewel.begin(), jewel.end());

	for (int i = 0; i < k; i++) {
		int weight;
		cin >> weight;
		bag.push_back({ weight, 0 });
	}
	sort(bag.begin(), bag.end());

	priority_queue<int> pq;
	int index = 0;
	long long answer = 0;
	for (int i = 0; i < bag.size(); i++) {
		while (index < jewel.size() && bag[i].first >= jewel[index].first) {
			pq.push(jewel[index++].second);
		}
		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer;

}