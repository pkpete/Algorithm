#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
	1.	보석 정보를 입력 받고, 보석의 무게순으로 정렬한다.(오름차순)
		가방 무게 정보를 입력 받고, 무게순으로 정렬한다.(오름차순)
	
	2.	1)	가방의 개수 만큼 반복문을 돈다.
		2)	해당 가방이 허용할 수 있는 보석을 모두 우선순위 큐에 넣는다.	(보석의 가격만 넣는다)
		3)	우선순위 큐의 top()이 가장 비싼 보석임으로 answer변수에 더하고 pop()한다.
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
	//무게 순으로 정렬(오름차순)
	sort(jewel.begin(), jewel.end());

	for (int i = 0; i < k; i++) {
		int weight;
		cin >> weight;
		bag.push_back({ weight, 0 });
	}
	//무게 순으로 정렬(오름차순)
	sort(bag.begin(), bag.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	priority_queue<int> pq;	//보석의 가격을 저장할 우선순위 큐
	int index = 0;
	long long answer = 0;
	for (int i = 0; i < bag.size(); i++) {
		while (index < jewel.size() && bag[i].first >= jewel[index].first) {	// 해당 가방에 넣을 수 있는 보석
			pq.push(jewel[index++].second);		// 우선순위 큐에 해당 보석의 가격을 저장한다.
		}
		if (!pq.empty()) {
			answer += pq.top();		//	가장 비싼 가격을 answer변수에 저장
			pq.pop();
		}
	}
	cout << answer;

}