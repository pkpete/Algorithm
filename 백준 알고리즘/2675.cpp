#include <iostream>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int num;
		string str;
		cin >> num >> str;
		for(int j = 0; j < str.size(); j++){
			for(int k = 0; k < num; k++){
				cout << str[j];
			}
		}
		cout << "\n";
	}
}