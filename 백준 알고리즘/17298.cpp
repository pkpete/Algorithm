#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int arr[1000001];
int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int size, num;
	cin >> size;
	stack<pair<int,int>> st;
	for(int i = 0; i < size; i++){
		cin >> num;
		if(st.empty()){ //초기
			st.push(make_pair(num, i));
		}else{
			int top_of_stack = st.top().first;
			if(top_of_stack > num){ // 새로 들어온 수가 직전 숫자 보다 작으면
				st.push(make_pair(num,i));
			}else{	// 새로 들어온 수가 직전의 수 보다 크면
				while(!st.empty() && st.top().first < num){
					top_of_stack = st.top().first;
					int index = st.top().second;
					st.pop();
					arr[index] = num;
				}
				st.push(make_pair(num,i));
			}
		}
	}
	for(int i = 0 ; i < size; i++){
		if(arr[i] == 0) cout << -1 << " ";
		else cout << arr[i] << " ";
	}
}