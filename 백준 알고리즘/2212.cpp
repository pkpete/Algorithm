#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> points;
vector<int> dist;
bool cmp(int a, int b) {
	if (a > b)
		return true;
	return false;
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		points.push_back(tmp);
	}
	sort(points.begin(), points.end());
	//points.erase(unique(points.begin(), points.end()), points.end());

	for (int i = 0; i < points.size()-1; i++) {
		int tmp = abs(points[i] - points[i + 1]);
		dist.push_back(tmp);
	}
	sort(dist.begin(), dist.end(), cmp);
	int sum = 0;
	for (int i = k-1; i < dist.size(); i++) {
		sum += dist[i];
	}
	cout << sum;
}