#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	queue<int> q;
	for(int i = 0; i < n; i++){
		cin >> s;
		if(s.compare("push") == 0){
			int num;
			cin >> num;
			q.push(num);
		}
		else if(s.compare("pop") == 0){
			if(q.empty()){
				cout << -1 << "\n";
			}else{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if(s.compare("size") == 0){
			cout << q.size() << "\n";
		}
		else if(s.compare("empty") == 0){
			cout << q.empty() << "\n";
		}
		else if(s.compare("front") == 0){
			if(q.empty()){
				cout << -1 << "\n";
			}else{
				cout << q.front() << "\n";
			}
		}
		else if(s.compare("back") == 0){
			if(q.empty()){
				cout << -1 << "\n";
			}else{
				cout << q.back() << "\n";
			}
		}
	}
}