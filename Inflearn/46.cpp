#include <iostream>
#include <queue>
using namespace std;
queue<pair<int,int>> time;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		time.push(make_pair(num,i+1));
	}
	int k, cnt = 0;
	cin >> k;
	while(!time.empty()){
		if(cnt == k)
			break;
		pair<int,int> tmp = time.front();
		time.pop();
		if(tmp.first - 1 != 0)
			time.push(make_pair(tmp.first-1, tmp.second));
		cnt++;
	}
	if(!time.empty())
		cout << time.front().second;
	else cout << -1;

}