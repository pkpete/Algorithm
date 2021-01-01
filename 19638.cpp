#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n, h, t;	//ÀÎ±¸¼ö, ¼¾Æ¼ÀÇ Å°, »Ð¸ÁÄ¡ È½¼ö
	cin >> n >> h >> t;
	int height;
	priority_queue<int> pq;
	for(int i = 0; i < n; i++){
		cin >> height;
		pq.push(height);
	}

	int count = 0;
	for(int i = 0; i < t; i++){
		if(h > pq.top()){
			cout << "YES\n" << count;
			return 0;
		}
		else if(pq.top()>1){
			int tallest = pq.top();
			pq.pop();
			pq.push(tallest/2);
			count++;
		}
	}
	if(h > pq.top())
		cout << "YES\n" << count;
	else
		cout << "NO\n" << pq.top();
}