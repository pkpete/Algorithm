#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
	string str;
	cin >> str;
	stack<int> st;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '('){
			st.push(1);
		}else{
			st.pop();
		}
	}
	if(st.size()==0){
		cout << "YES";
	}else
		cout << "NO";

}