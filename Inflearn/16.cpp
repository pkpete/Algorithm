#include <iostream>
#include <string>
using namespace std;
int arr[75];
int main(){
	string str1, str2;
	cin >> str1 >> str2;	//a ~ z 49-74	A ~ Z 17-42
	if(str1.size() != str2.size()){
		cout << "NO";
		return 0;
	}else{
		for(int i = 0; i < str1.size(); i++){
			arr[str1[i]-'0']++;
			arr[str2[i]-'0']--;
		}
		for(int i = 17; i < 74; i++){
			if(arr[i] != 0){
				cout << "NO";
				return 0;
			}
		}
		cout << "YES";
	}

}