#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m, k; cin >> n >> m >> k;	// 참가자, 장르, 합격자
	vector<vector<float>> arr(n + 1);
	vector<float> answer;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int k;
			float s;
			cin >> k >> s;
			arr[k].push_back(s);
		}
	}

	for (int i = 1; i < n + 1; i++) {
		sort(arr[i].begin(), arr[i].end());
		reverse(arr[i].begin(), arr[i].end());
		answer.push_back(arr[i][0]);
	}

	sort(answer.begin(), answer.end());
	reverse(answer.begin(), answer.end());
	float cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += answer[i];
	}
	printf("%.1f", cnt);
}