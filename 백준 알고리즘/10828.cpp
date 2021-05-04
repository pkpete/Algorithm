#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
	int n;
	cin >> n;
	string s;
	stack<int> st;
	for(int i = 0; i < n; i++){
		cin >> s;
		if(s.compare("push") == 0){
			int num;
			cin >> num;
			st.push(num);
		}
		else if(s.compare("pop") == 0){
			if(st.empty()){
				cout << -1 << endl;
			}else{
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if(s.compare("size") == 0){
			cout << st.size() << endl;
		}
		else if(s.compare("empty") == 0){
			cout << st.empty() << endl;
		}
		else if(s.compare("top") == 0){
			if(st.empty()){
				cout << -1 << endl;
			}else{
				cout << st.top() << endl;
			}
		}
	}
}