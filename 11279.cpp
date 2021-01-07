#include <iostream>
#include <queue>
using namespace std;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int num;
	cin >> num;
	priority_queue<int> pq;
	for(int i = 0; i < num; i++){
		int x;
		cin >> x;
		if(x==0){
			if(pq.empty())
				cout << 0 << "\n";
			else{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else{
			pq.push(x);
		}
	}
}