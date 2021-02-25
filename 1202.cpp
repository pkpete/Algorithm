#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
	1.	���� ������ �Է� �ް�, ������ ���Լ����� �����Ѵ�.(��������)
		���� ���� ������ �Է� �ް�, ���Լ����� �����Ѵ�.(��������)
	
	2.	1)	������ ���� ��ŭ �ݺ����� ����.
		2)	�ش� ������ ����� �� �ִ� ������ ��� �켱���� ť�� �ִ´�.	(������ ���ݸ� �ִ´�)
		3)	�켱���� ť�� top()�� ���� ��� ���������� answer������ ���ϰ� pop()�Ѵ�.
*/
vector<pair<int, int>> jewel;
vector<pair<int, int>> bag;
int n, k;
void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int weight, cost;
		cin >> weight >> cost;
		jewel.push_back({ weight, cost });
	}
	//���� ������ ����(��������)
	sort(jewel.begin(), jewel.end());

	for (int i = 0; i < k; i++) {
		int weight;
		cin >> weight;
		bag.push_back({ weight, 0 });
	}
	//���� ������ ����(��������)
	sort(bag.begin(), bag.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	priority_queue<int> pq;	//������ ������ ������ �켱���� ť
	int index = 0;
	long long answer = 0;
	for (int i = 0; i < bag.size(); i++) {
		while (index < jewel.size() && bag[i].first >= jewel[index].first) {	// �ش� ���濡 ���� �� �ִ� ����
			pq.push(jewel[index++].second);		// �켱���� ť�� �ش� ������ ������ �����Ѵ�.
		}
		if (!pq.empty()) {
			answer += pq.top();		//	���� ��� ������ answer������ ����
			pq.pop();
		}
	}
	cout << answer;

}