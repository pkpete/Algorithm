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
		if(st.empty()){ //�ʱ�
			st.push(make_pair(num, i));
		}else{
			int top_of_stack = st.top().first;
			if(top_of_stack > num){ // ���� ���� ���� ���� ���� ���� ������
				st.push(make_pair(num,i));
			}else{	// ���� ���� ���� ������ �� ���� ũ��
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