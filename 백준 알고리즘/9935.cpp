#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
	string str, bomb;
	cin >> str >> bomb;
	string answer = "";
	int index = bomb.size() - 1;
	for(int i = 0; i < str.size(); i++){
		answer.push_back(str[i]);
		if(str[i] == bomb[index]){	// ´Ü¾î°¡ ÆøÅºÀÇ ¸¶Áö¸· ´Ü¾î¶û °°À»¶§
			if(answer.size() >= bomb.size()){
				int cnt = 1;
				for(int j = index - 1; j >= 0; j--){
					if(bomb[j] == answer[answer.size()-1-cnt]){
						cnt++;
					}
				}
				if(cnt == bomb.size()){
					for(int j = 0; j < bomb.size(); j++){
						answer.pop_back();
					}
				}
			}
		}
	}
	if(answer.empty())
		cout << "FRULA";
	else cout << answer;
}