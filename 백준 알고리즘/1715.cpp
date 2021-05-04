#include <iostream>
#include <queue>
using namespace std;
int main(){
	int num_of_cards;
	cin >> num_of_cards;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < num_of_cards; i++){
		int num;
		cin >> num;
		pq.push(num);
	}
	int sum = 0;
	int answer = 0;
	for(int i = 0; i < num_of_cards -1; i++){
		int tmp1 = pq.top();	//큐 내에 가장 작은 카드
		pq.pop();
		int tmp2 = pq.top();	//큐 내에 2번째 작은 카드
		pq.pop();
		sum = tmp1 + tmp2;
		answer += sum;
		pq.push(sum);
	}
	cout << answer;
}