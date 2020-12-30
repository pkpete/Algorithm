#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<char> st;
bool before = false;
int main(){
	string s;
	cin >> s;
	int result = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '('){
			st.push('(');
			before = true;
			
		}else if(s[i] == ')'){
			if(before){ // 직전에 '('이면 레이저를 표현
				st.pop();
				result = result + st.size();
			}else{
				st.pop();
				result++;
			}
			before = false;
		}
	}
	cout << result;
}