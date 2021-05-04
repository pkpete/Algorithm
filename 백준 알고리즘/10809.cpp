#include <iostream>
#include <string>
using namespace std;

int main(){
	int arr[26];
	for(int i = 0; i < 26; i++)
		arr[i] = -1;

	string str; // a=49 z=74
	cin >> str;
	for(int i = 0; i < str.size(); i++){
		if(arr[str[i]-'0'-49] == -1){
			arr[str[i]-'0'-49] = i;
		}
	}

	for(int i = 0; i < 26; i++)
		cout << arr[i] << " ";
}