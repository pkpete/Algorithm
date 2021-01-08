#include <iostream>
#include <queue>
using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x==0){
			if(pq.empty())
				cout << 0 << "\n";
			else{
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else{
			pq.push(make_pair(abs(x),x));
		}
	}
}