#include <iostream>
#include <vector>
using namespace std;
vector<int> dice[10000];
vector<int> answer;
int max_num = -1;
int n;
void input() {
	cin >> n;
	answer = vector<int>(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			int tmp;
			cin >> tmp;
			dice[i].push_back(tmp);
		}
	}
}

int find_max_num(int a, int b) {
	int num = 6;
	if (num == a || num == b)
		num--;
	if (num == a || num == b)
		num--;
	return num;
}

void find_dice(int num, int cnt) {	//¾Æ·§¸é, Ãþ
	if (cnt == n) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += answer[i];
		}
		if (sum > max_num)
			max_num = sum;
	}
	else {
		int i;
		for (i = 0; i < 6; i++) {
			if (num == dice[cnt][i])
				break;
		}
		int tmp;	//À­¸é
		switch (i) {
		case 0: tmp = dice[cnt][5];
			break;
		case 1: tmp = dice[cnt][3];
			break;
		case 2: tmp = dice[cnt][4];
			break;
		case 3: tmp = dice[cnt][1];
			break;
		case 4: tmp = dice[cnt][2];
			break;
		case 5: tmp = dice[cnt][0];
			break;
		}
		answer[cnt] = find_max_num(tmp, num);
		find_dice(tmp, cnt+1);
	}
}

int main() {
	input();
	for (int i = 0; i < 6; i++) {
		int tmp;
		switch (i) {
		case 0: tmp = dice[0][5];
			break;
		case 1: tmp = dice[0][3];
			break;
		case 2: tmp = dice[0][4];
			break;
		case 3: tmp = dice[0][1];
			break;
		case 4: tmp = dice[0][2];
			break;
		case 5: tmp = dice[0][0];
			break;
		}
		answer[0] = find_max_num(tmp, dice[0][i]);
		find_dice(tmp, 1);
	}
	cout << max_num << "\n";
}