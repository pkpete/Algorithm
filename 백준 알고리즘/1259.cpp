#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string str, tmp;
	cin >> str;
	while(str != "0"){
		tmp = str;
		reverse(str.begin(),str.end());
		if(str == tmp){
			cout << "yes" << "\n";
		}
		else
			cout << "no" << "\n";
		cin >> str;
	}
}