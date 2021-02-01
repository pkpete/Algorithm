#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];
int r, c, k;	//map[r][c] = k가 되기 위한 최소 시간
int row_size, col_size;
int arr[101];

void clear_arr() {
	for (int i = 0; i < 101; i++)
		arr[i] = 0;
}

void input() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}
	row_size = 3;
	col_size = 3;
}

bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.second <= b.second) {
		if (a.second == b.second) {	//등장 횟수가 같을 때
			if (a.first < b.first)
				return true;
			else return false;
		}
		return true;
	}
	return false;
}

int main() {
	input();

	int time = 0;
	while (1) {
		if (time > 100) {
			time = -1;
			break;
		}
		if (map[r][c] == k)
			break;
		if (col_size >= row_size) {// R연산 행의 개수가 더 많으면
			for (int i = 1; i <= col_size; i++) {

				vector<pair<int, int>> tmp;
				clear_arr();

				for (int j = 1; j <= row_size; j++) {	//각각의 수 등장 횟수
					arr[map[i][j]]++;	
				}

				for (int j = 1; j < 101; j++) {
					if (arr[j] > 0) {
						tmp.push_back(make_pair(j, arr[j]));	//숫자, 등장횟수
					}
				}

				sort(tmp.begin(), tmp.end(), cmp);
				
				for (int j = 1; j <= row_size; j++) {	//배열 초기화
					map[i][j] = 0;
				}

				int index = 0;
				for (int j = 1; j <= tmp.size() * 2; j = j + 2) {	// 배열에 다시 넣기
					map[i][j] = tmp[index].first;
					map[i][j + 1] = tmp[index++].second;
 				}

				if (tmp.size() * 2 > row_size)
					row_size = tmp.size() * 2;
				if (row_size > 100)
					row_size = 100;
			}

		}
		else {// C 연산
			for (int i = 1; i <= row_size; i++) {

				vector<pair<int, int>> tmp;
				clear_arr();
				for (int j = 1; j <= col_size; j++) {	//각각의 수 등장 횟수
					arr[map[j][i]]++;	
				}

				for (int j = 1; j < 101; j++) {
					if (arr[j] > 0) {
						tmp.push_back(make_pair(j, arr[j]));	//숫자, 등장횟수
					}
				}
				sort(tmp.begin(), tmp.end(), cmp);

				for (int j = 1; j <= col_size; j++) {
					map[j][i] = 0;
				}

				int index = 0;
				for (int j = 1; j <= tmp.size() * 2; j = j + 2) {
					map[j][i] = tmp[index].first;
					map[j + 1][i] = tmp[index++].second;
				}

				if (tmp.size() * 2 > col_size)
					col_size = tmp.size() * 2;
				if (col_size > 100)
					col_size = 100;
			
			}
		}
		time++;
	}

	cout << time;
}