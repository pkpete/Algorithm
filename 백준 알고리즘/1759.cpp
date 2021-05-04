#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
	�˰��� :
	1. ������ ���������� ����ϱ� ���ؼ� �Է� �޴� ���ĺ��� �����Ѵ�.
	2. �Է��� 15���� �۰ų� �������� ��й�ȣ�� ���̰� 'l'�� ��� ��� ��ȣ�� ã�´�.
	3. ��й�ȣ �� ������ 1�� ������ 2�� �̻��� ��й�ȣ�� answer�� �ִ´�.
*/
vector<char> abc;	// �Է� ���� ���ĺ�
vector<string> answer;
char arr[5] = { 'a','e','i','o','u' };
string pw;
int vowel = 0;	//����
int consonant = 0;	//����
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
		if (vowel >= 1 && consonant >= 2) {	//������ 1�� �̻� && ������ 2�� �̻��� �ܾ answer�� �ִ´�.
			answer.push_back(pw);
		}
		return;
	}
	else {
		//���� ������ ���� �ľ��ϱ�
		for (int i = index; i < abc.size(); i++) {
			bool isvowel = false;
			for (int j = 0; j < 5; j++) {
				if (arr[j] == abc[i]) {	//����
					vowel++;
					isvowel = true;
					break;
				}
			}
			if (!isvowel)	//����
				consonant++;

			pw.push_back(abc[i]);
			create_pw(i + 1, cnt + 1);

			if (isvowel)	//���� ����
				vowel--;
			else
				consonant--;	//���� ����
			pw.pop_back();
		}
	}
}

int main() {
	input();
	create_pw(0, 0);	// ��� ��й�ȣ ����
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}