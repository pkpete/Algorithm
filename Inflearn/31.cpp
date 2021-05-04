#include <iostream>
#include <string>
using namespace std;
int main(){
	string str;
	cin >> str;
	int sum = 0, c, h;
	for(int i = 0; i < str.length(); i++){
		if(str[i]-'0' >= 0 && str[i] - '0' <= 9){
			sum = sum * 10 + (str[i]-'0');
		}
		else{
			if(sum ==0)
				c = 1;
			else{
				c = sum;
			}
			sum = 0;
		}
	}
	if(sum == 0) sum = 1;
	cout << 12*c + sum;
}