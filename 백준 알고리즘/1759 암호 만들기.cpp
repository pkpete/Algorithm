#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int l, c;
vector<string> word, answer;
string moeum = "aeiou";

void make_password(int idx, int cnt, string pw) {
	if (cnt == l) {
		int cnt_moeum = 0, cnt_jaeum = pw.size();
		for (int i = 0; i < pw.size(); i++) {
			for (int j = 0; j < moeum.size(); j++) {
				if (pw[i] == moeum[j]) {
					cnt_moeum++;
					cnt_jaeum--;
					break;
				}
			}
		}
		if (cnt_moeum >= 1 && cnt_jaeum >= 2) {
			answer.push_back(pw);
		}
		return;
	}
	for (int i = idx; i < word.size(); i++) {
		make_password(i + 1, cnt + 1, pw + word[i]);
	}
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		string str;
		cin >> str;
		word.push_back(str);
	}

	sort(word.begin(), word.end());

	string tmp = "";
	make_password(0, 0, tmp);

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
}