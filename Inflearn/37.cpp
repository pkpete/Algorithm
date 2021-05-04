#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int check[101];
int main(){
	int s, n, num;
	cin >> s >> n;
	stack<int> st;
	for(int i = 0; i < n; i++){
		cin >> num;
		st.push(num);
	}
	int cnt = 0;
	for(int i = 0; i < st.size(); i++){
		int tmp = st.top();
		st.pop();
		if(cnt == s) break;
		if(check[tmp] == 0){
			check[tmp] = 1;
			cout << tmp << " ";
			cnt++;
		}
	}
}