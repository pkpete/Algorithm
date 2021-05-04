#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	cin >> n;
	int num = 666;
	int count = 0;
	while(1){
		string s = to_string(num);
		if(s.find("666") != -1)
			count++;
		if(count == n)
			break;
		num++;
	}
	cout << num;
}