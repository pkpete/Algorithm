#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
	알고리즘 :
	1. 정답을 사전식으로 출력하기 위해서 입력 받는 알파벳을 정렬한다.
	2. 입력이 15보다 작거나 같음으로 비밀번호의 길이가 'l'인 모든 비밀 번호를 찾는다.
	3. 비밀번호 중 모음이 1개 자음이 2개 이상인 비밀번호만 answer에 넣는다.
*/
vector<char> abc;	// 입력 받은 알파벳
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
		if (vowel >= 1 && consonant >= 2) {	//모음이 1개 이상 && 자음이 2개 이상인 단어만 answer에 넣는다.
			answer.push_back(pw);
		}
		return;
	}
	else {
		//모음 자음의 개수 파악하기
		for (int i = index; i < abc.size(); i++) {
			bool isvowel = false;
			for (int j = 0; j < 5; j++) {
				if (arr[j] == abc[i]) {	//모음
					vowel++;
					isvowel = true;
					break;
				}
			}
			if (!isvowel)	//자음
				consonant++;

			pw.push_back(abc[i]);
			create_pw(i + 1, cnt + 1);

			if (isvowel)	//모음 제거
				vowel--;
			else
				consonant--;	//자음 제거
			pw.pop_back();
		}
	}
}

int main() {
	input();
	create_pw(0, 0);	// 모든 비밀번호 생성
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}