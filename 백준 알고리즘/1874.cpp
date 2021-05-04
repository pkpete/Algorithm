#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<char> answer;
	stack<int> st;
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		st.push(i);
		answer.push_back('+');
		while(!st.empty()){
			if(v[cnt] != st.top()) break;
			else{
				st.pop();
				answer.push_back('-');
				cnt++;
			}
		}
	}
	if(st.empty()){
		for(int i = 0; i < answer.size(); i++)
			cout << answer[i] << "\n";
	}
	else cout << "NO";
}