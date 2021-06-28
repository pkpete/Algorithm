#include <iostream>
using namespace std;

bool check[1001];
int num[4] = { 1,5,10,50 };
void make_num(int size,  int cnt, int sum, int index) {
	if (cnt == size) {
		check[sum] = true;
		return;
	}

	for (int i = index; i < 4; i++) {
		make_num(size, cnt + 1, sum + num[i], i);
	}
}

int main() {
	int n;
	cin >> n;
	make_num(n, 0, 0, 0);

	int answer = 0;
	for (int i = 0; i < 1001; i++) {
		if (check[i])
			answer++;
	}
	cout << answer;
	
}