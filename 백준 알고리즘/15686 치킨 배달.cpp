#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int map[51][51];
int answer = 1000000;
int n, m;
vector<pair<int, int>> city, chicken;
vector<int> choose;
vector<int> min_distance;

void clear() {
	for (int i = 0; i < min_distance.size(); i++) {
		min_distance[i] = 10000;
	}
}

int calculate() {
	int len = 0;
	for (int i = 0; i < m; i++) {
		int index = choose[i];
		int chickeny = chicken[index].first;
		int chickenx = chicken[index].second;
		for (int j = 0; j < city.size(); j++) {
			int cityy = city[j].first;
			int cityx = city[j].second;
			int tmp = abs(cityy - chickeny) + abs(cityx - chickenx);
			min_distance[j] = min(min_distance[j], tmp);
		}
	}

	for (int i = 0; i < min_distance.size(); i++) {
		len += min_distance[i];
	}
	return len;
}

void dfs(int index, int size) {
	if (size == m) {
		clear();
		int len = calculate();
		answer = min(answer, len);
		return;
	}
	for (int i = index; i < chicken.size(); i++) {
		choose[size] = i;
		dfs(i + 1, size + 1);
	}
}

int main() {
	cin >> n >> m;
	choose = vector<int>(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				city.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	min_distance = vector<int>(city.size());
	dfs(0, 0);
	cout << answer;
}