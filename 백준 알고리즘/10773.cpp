#include <iostream>
#include <stack>
using namespace std;
int main(){
	int k, n;
	cin >> k;
	stack<int> st;
	int sum = 0;
	for(int i = 0 ; i < k; i++){
		cin >> n;
		if(n==0){
			int tmp = st.top();
			st.pop();
			sum -= tmp;
		}
		else{
			st.push(n);
			sum += n;
		}
	}
	cout << sum;
}