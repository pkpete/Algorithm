#include <iostream>
#include <vector>
using namespace std;
int n, m;
bool map[10][10];
bool make_friend[10];
int count_pair() {
	int free = -1;
	for (int i = 0; i < n; i++) {
		if (!make_friend[i]) {
			free = i; 
			break;
		}
	}
	//기저 사례 : 모든 학생이 짝을 찾았으면 1가지 방법을 찾았으니 종료한다.
	if (free == -1) return 1;
	int cnt = 0;
	//이 학생과 짝지을 학생 결정
	for (int i = free + 1; i < n; i++) {
		if (!make_friend[i] && map[free][i]) {
			make_friend[free] = make_friend[i] = true;
			cnt += count_pair();
			make_friend[free] = make_friend[i] = false;
		}
	}
	return cnt;
}

void set_map() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = false;
		}
		make_friend[i] = false;
	}
}

int main() {
	int t;
	cin >> t;
	while (t > 0) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			map[a][b] = map[b][a] = true;
		}
		cout << count_pair() << endl;
		set_map();
		t--;
	}
}