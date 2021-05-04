#include <iostream>
#include <stack>
using namespace std;
int main(){
	int n, num;
	cin >> n;
	stack<int> st;
	for(int i = 0; i < n; i++){
		cin >> num;
		if(st.empty())
			st.push(num);
		else{
			if(st.top() <= num){
				while(!st.empty() && st.top() <= num){
					st.pop();
				}
			}
			st.push(num);
		}
	}
	st.pop();
	cout << st.size() << endl;	
}