#include <iostream>
#include <deque>
#include <string>
using namespace std;
deque<char> dq;
int main(){
	int n, k; string str;
	cin >> n >> k >> str;

	for(int i = 0; i < str.size(); i++){
		while(k>0 && !dq.empty() && dq.back() < str[i]){
			dq.pop_back();
			k--;
		}
		dq.push_back(str[i]);
	}
	for(int i = 0; i < dq.size()-k; i++){
		cout << dq[i];
	}
}