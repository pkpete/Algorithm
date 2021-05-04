/*
	N���� �����߰� �־��� ��, �� �ߵ��� ����Ͽ� ������ �� ���� ���� ���� ���� �� �ּڰ��� ���Ͻÿ�.
	
	-> �˰���
	1. ���� �ߵ��� ������������ ����.
	2-1 ���� ���� ���� �߰� ���� ���� ���� ũ�� ������ �� ����
	2-2 ���� ���� ���� �߰� ���� ���� ���� �۰ų� ������ ���� ����
	3. ������ ���� ���Ը� ���� ���Կ� ���ϰ� ���� ���� ��.

	ex)
	���ĵ� ��			:	1 1 2 3 6 7 30
	���� ����(����)	:	1 2 3 5 8 14 21	(30 > 21�̹Ƿ� ���� ���� �Ұ�)

	ex)
	���ĵ� ��			:	1 2 3 4
	���� ����(����)	:	1 2 4 7 11 (11���� �Ұ�)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> weight;
void input() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		weight.push_back(tmp);
	}
	sort(weight.begin(), weight.end());
}

int main() {
	input();
	int answer = 1;
	for (int i = 0; i < weight.size(); i++) {
		if (weight[i] > answer)
			break;
		answer += weight[i];
	}
	cout << answer;
}