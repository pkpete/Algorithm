#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> wheel[4]; // 2 - (6, 2) - (6, 2) - 6
bool visit[4];

void turn(int idx, int dir) {
	int left = wheel[idx][6], right = wheel[idx][2];
	visit[idx] = true;
	if (dir == 1) { // right
		int back = wheel[idx][7];
		wheel[idx].pop_back();
		wheel[idx].push_front(back);
	}
	else if (dir == -1) { // left
		int front = wheel[idx][0];
		wheel[idx].pop_front();
		wheel[idx].push_back(front);
	}
	
	if (idx - 1 >= 0 && wheel[idx-1][2] != left && !visit[idx-1]) {	// ¿ŞÂÊ ¹ÙÄû¶û ±ØÀÌ ´Ù¸£¸é
		turn(idx - 1, dir * -1);
	}
	if (idx + 1 < 4 && wheel[idx+1][6] != right && !visit[idx+1]) { // ¿À¸¥ÂÊ ¹ÙÄû¶û ±ØÀÌ ´Ù¸£¸é
		turn(idx + 1, dir * -1);
	}

}



int main() {
	string s;
	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			wheel[i].push_back(s[j] - '0');
		}
	}

	int k; cin >> k;

	for (int i = 0; i < k; i++) {
		int cur, dir;
		cin >> cur >> dir;
		turn(cur - 1, dir);
		for (int j = 0; j < 4; j++)
			visit[j] = false;
	}
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1) {
			answer += pow(2, i);
		}
	}
	cout << answer;
}