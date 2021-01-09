#include <iostream>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;
	int num = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i]-'0' >=0 && s[i]-'0'<= 9){
			num = num*10 + s[i]-'0';
		}
	}
	cout << num << "\n";
	int cnt = 0;
	for(int i = 1; i <= num; i++){
		if(num % i == 0)
			cnt++;
	}
	cout << cnt;
}