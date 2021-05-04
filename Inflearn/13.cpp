#include <iostream>
#include <string>
using namespace std;
int arr[10];
int main(){
	string str;
	cin >> str;
	int num = 0, max_num = -1, max_index;
	for(int i = 0; i < str.size(); i++){
		num = str[i] - '0';
		arr[num]++;
	}
	for(int i = 0; i < 10; i++){
		if(max_num <= arr[i]){
			max_num = arr[i];
			max_index = i;
		}
	}
	cout << max_index;
}