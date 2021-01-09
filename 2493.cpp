#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	stack<pair<int,int>> st;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		if(i==0){
			v.push_back(0);
			st.push(make_pair(num,i+1));
		}
		else{
			if(num < st.top().first){		//현재 숫자가 스택에 있는 것보다 작음
				v.push_back(st.top().second);
				st.push(make_pair(num,i+1));	//다음에 오는 숫자가 내꺼 보다 작을 수 있음
			}
			else{
				while(st.size() > 0 && num > st.top().first){
					st.pop();
				}
				if(st.size()==0)
					v.push_back(0);
				else
					v.push_back(st.top().second);
				st.push(make_pair(num,i+1));
			}
		}
	}
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
}