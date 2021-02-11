#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> weight;
void input() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		weight.push_back(tmp);
	}
	sort(weight.begin(), weight.end());
}

int main() {
	input();
	int answer = 1;
	for (int i = 0; i < weight.size(); i++) {
		if (weight[i] > answer)
			break;
		answer += weight[i];
	}
	cout << answer;
}