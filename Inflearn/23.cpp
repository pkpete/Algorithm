#include<iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
	int n, max = -1;
	cin >> n;
	//vector<int> arr(n);
	stack<int> st;
	int len, num;
	for(int i = 0; i < n; i++){
		cin >> num;
		len = 0;
		if(st.empty())
			st.push(num);
		else{
			if(st.top() <= num){
				st.push(num);
			}
			else{
				while(!st.empty()){
					len++;
					st.pop();
				}
				st.push(num);
			}
			if(len > max) max = len;
		}
	}
	if(max == 0){
		cout << n;
	}
	else
		cout << max;
}