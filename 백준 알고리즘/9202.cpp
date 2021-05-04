#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
char map[4][4][30];
bool visit[4][4];
int n_word, n_board;
vector<string> word;
void input() {
	cin >> n_word;
	for (int i = 0; i < n_word; i++) {
		string str;
		cin >> str;
		word.push_back(str);
	}
	cin >> n_board;
	for (int i = 0; i < n_board; i++) {
		for (int j = 0; j < 4; j++) {
			string str;
			cin >> str;
			for (int k = 0; k < 4; k++) {
				map[j][k][i] = str[k];
			}
		}
	}
}

bool in_map(int y, int x) {
	if (y >= 0 && x >= 0 && y < 4 && x < 4)
		return true;
	return false;
}

bool find_word(int y, int x, string str, int board) {
	
	if (str[0] != map[y][x][board]) return false;
	visit[y][x] = true;
	if (str.size() == 1)
		return true;

	for (int i = 0; i < 8; i++) {
		int movex = x + dx[i], movey = y + dy[i];
		if (in_map(movey, movex) && !visit[movey][movex] && find_word(movey, movex, str.substr(1), board)) {
			return true;
		}
	}
	visit[y][x] = false;
	return false;
}

bool cmp(string a, string b) {
	if (a.size() >= b.size()) {
		if (a.size() > b.size())
			return true;
		else {
			for (int i = 0; i < a.size(); i++) {
				if (a[i] < b[i])
					return true;
				else if (a[i] > b[i])
					return false;
			}
		}
	}
	return false;
}

void set_visit() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			visit[i][j] = false;
}

int main() {
	input();
	for (int i = 0; i < n_board; i++) {
		vector<string> answer;
		for (int j = 0; j < n_word; j++) {
			bool found = false;
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					set_visit();
					if (find_word(k, l, word[j], i)) {
						answer.push_back(word[j]);
						found = true;
						break;
					}
				}
				if (found)
					break;
			}
		}
		int point = 0;
		
		sort(answer.begin(), answer.end(), cmp);
		for (int i = 0; i < answer.size(); i++) {
			//cout << answer[i] << " ";
			switch (answer[i].size()) {
			case 1:
			case 2: point += 0; break;
			case 3:
			case 4:	point += 1; break;
			case 5: point += 2; break;
			case 6:	point += 3; break;
			case 7:	point += 5; break;
			case 8:	point += 11; break;
			}
		}
		//cout << endl;
		cout << point << " " << answer[0] << " " << answer.size() << "\n";
	}

}