#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<char> abc;
vector<string> answer;
char arr[5] = { 'a','e','i','o','u' };
string pw;
int vowel = 0;	//모음
int consonant = 0;	//자음
int l, c;
void input() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char c;
		cin >> c;
		abc.push_back(c);
	}
	sort(abc.begin(), abc.end());
}

void create_pw(int index, int cnt) {
	if (cnt == l) {
		if (vowel >= 1 && consonant >= 2) {
			answer.push_back(pw);
		}
		return;
	}
	else {
		for (int i = index; i < abc.size(); i++) {
			bool isvowel = false;
			for (int j = 0; j < 5; j++) {
				if (arr[j] == abc[i]) {
					vowel++;
					isvowel = true;
					break;
				}
			}
			if (!isvowel)
				consonant++;
			pw.push_back(abc[i]);
			create_pw(i + 1, cnt + 1);
			if (isvowel)
				vowel--;
			else
				consonant--;
			pw.pop_back();
		}
	}
}

int main() {
	input();
	create_pw(0, 0);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}