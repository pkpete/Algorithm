#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	deque<char> dq, dq2;
	vector<char> v;
	for(int i = 0; i < str.size(); i++)
		dq.push_back(str[i]);
	
	string a, b;
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> a;
		if(a == "L"){
			if(!dq.empty()){
				char tmp = dq.back();
				dq.pop_back();
				dq2.push_front(tmp);
			}
		}
		else if(a == "D"){
			if(!dq2.empty()){
				char tmp = dq2.front();
				dq2.pop_front();
				dq.push_back(tmp);
			}
		}
		else if(a == "B"){
			if(!dq.empty()){
				dq.pop_back();
			}
		}
		else{
			cin >> b;
			dq.push_back(b[0]);
		}
	}
	while(!dq.empty()){
		cout << dq.front();
		dq.pop_front();
	}
	while(!dq2.empty()){
		cout << dq2.front();
		dq2.pop_front();
	}
}