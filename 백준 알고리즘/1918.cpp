#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<pair<char,int>> symbol;
int main(){
	string str;
	cin >> str;
	for(int i = 0; i < str.size(); i++){	//A 17 Z 42
		if(str[i]-'0'>=17 && str[i]-'0'<=42){
			cout << str[i];
		}
		else if(str[i] == ')'){
			while(symbol.top().first != '('){
				cout << symbol.top().first;
				symbol.pop();
			}
			symbol.pop();
		}
		else{
			if(!symbol.empty()){
				int rank = symbol.top().second;
				int cur_rank;
				if(str[i] == '-' || str[i] =='+'){	//���� 0 ���� ����
					cur_rank = 0;
					while(!symbol.empty() && rank != 2 && rank >= cur_rank){
						cout << symbol.top().first;
						symbol.pop();
						if(!symbol.empty())
							rank = symbol.top().second;
					}
				}
				else if(str[i] == '*' || str[i] == '/'){ // ���� 1 �߰�
					cur_rank = 1;
					if(rank == cur_rank){
						cout << symbol.top().first;
						symbol.pop();
					}
				}
				else{	//���� 2 ���� ����
					cur_rank = 2;
				}
				symbol.push(make_pair(str[i], cur_rank));
				
			}
			else{
				if(str[i] == '-' || str[i] =='+'){	//���� 0 ���� ����
					symbol.push(make_pair(str[i], 0));
				}
				else if(str[i] == '*' || str[i] == '/'){ // ���� 1 �߰�
					symbol.push(make_pair(str[i], 1));
				}
				else{	//���� 2 ���� ����
					symbol.push(make_pair(str[i], 2));
				}
			}
		}
	}
	while(!symbol.empty()){
		cout << symbol.top().first;
		symbol.pop();
	}

}