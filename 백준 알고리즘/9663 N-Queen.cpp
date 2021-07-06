//#include <iostream>
//#include <math.h>
//using namespace std;
//int map[16], n, answer = 0;
//
//bool promising(int num) {
//	bool flag = true;
//	int i = 1;
//	while (i < num && flag) {
//		if (map[i] == map[num] || abs(map[i] - map[num]) == num - i)
//			flag = false;
//		i++;
//	}
//	return flag;
//}
//
//void dfs(int num) {
//	if (promising(num)) {
//		if (num == n)
//			answer++;
//		else {
//			for (int i = 1; i <= n; i++) {
//				map[num + 1] = i;
//				dfs(num + 1);
//			}
//		}
//	}
//	
//}
//
//int main() {
//	cin >> n;
//
//	dfs(0);
//	cout << answer;
//}

#include <iostream>
#include <math.h>
using namespace std;
int n, answer = 0;
int map[16];

bool promising(int cnt) {
	bool flag = true;
	int i = 1;
	while (i < cnt && flag) {
		if (map[i] == map[cnt] || abs(map[i] - map[cnt]) == cnt - i) {
			flag = false;
		}
		i++;
	}

	return flag;
}

void nqueen(int cnt) {
	if (promising(cnt)) {
		if (cnt == n) {
			answer++;
			return;
		}
		else {
			for (int i = 1; i <= n; i++) {
				map[cnt + 1] = i;
				nqueen(cnt + 1);
			}
		}
	}
}

int main() {
	cin >> n;
	nqueen(0);
	cout << answer;
}