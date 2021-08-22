#include <iostream>
#include <algorithm>
using namespace std;
int card[1001][6];
void select_card(int n, int index, int cnt, int sum) {
	if (cnt == 3) {
		card[n][5] = max(card[n][5], sum%10);
		return;
	}
	for (int i = index; i < 5; i++) {
		select_card(n, i + 1, cnt + 1, sum + card[n][i]);
	}
}

int main() {
	int n, answer = 0, max_num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++)
			cin >> card[i][j];
		select_card(i,0,0,0);
		if (max_num <= card[i][5]) {
			answer = i + 1;
			max_num = card[i][5];
		}
	}
	cout << answer;
}