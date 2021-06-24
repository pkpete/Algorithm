#include <iostream>
#include <vector>
using namespace std;

int answer[6];

void choose_num(vector<int> v, int index, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << answer[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = index; i < v.size(); i++) {
		answer[cnt] = v[i];
		choose_num(v, i + 1, cnt + 1);
	}
}

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		choose_num(v, 0, 0);
		cout <<  endl;

	}
}