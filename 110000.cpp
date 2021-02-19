#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	for (int i = 1; i < n; i++) {
		if (v[i].first < pq.top()) {	//���� ���� ���� �ð��� ���� ���� ������ �ð����� ���� �� ���ο� ���ǽ� ����
			pq.push(v[i].second);
		}
		else {	// ���� ���� ���� �ð��� ���� ���� ������ �ð����� ������ 
			pq.pop();
			pq.push(v[i].second);
		}
	}
	cout << pq.size() << "\n";
}