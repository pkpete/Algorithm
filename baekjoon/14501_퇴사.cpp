#include <iostream>
#include <algorithm>
using namespace std;
int time[20];
int price[20];
int answer = 0;
int n;

void dfs(int day, int sum){
	answer = max(answer, sum);
	if (day == n + 1)
		return;
	if (day + time[day] <= n + 1)
		dfs(day + time[day], sum + price[day]);
	if (day + 1 <= n)
		dfs(day + 1, sum);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> price[i];
	}

	dfs(1, 0);
	cout << answer;
}