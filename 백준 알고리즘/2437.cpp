/*
	N개의 저울추가 주어질 때, 이 추들을 사용하여 측정할 수 없는 양의 정수 무게 중 최솟값을 구하시오.
	
	-> 알고리즘
	1. 무게 추들을 오름차순으로 정렬.
	2-1 가장 낮은 무게 추가 비교할 무게 보다 크면 측정할 수 없음
	2-2 가장 낮은 무게 추가 비교할 무게 보다 작거나 같으면 측정 가능
	3. 측정한 추의 무게를 비교할 무게에 더하고 다음 무게 비교.

	ex)
	정렬된 추			:	1 1 2 3 6 7 30
	비교할 무게(누적)	:	1 2 3 5 8 14 21	(30 > 21이므로 무게 측정 불가)

	ex)
	정렬된 추			:	1 2 3 4
	비교할 무게(누적)	:	1 2 4 7 11 (11측정 불가)
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