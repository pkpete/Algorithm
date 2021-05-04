#include <iostream>
using namespace std;
int main(){
	int n, answer = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		int num, cnt = 0;
		cin >> num;
		for(int j = 2; j <= num; j++){
			if(num%j == 0) cnt++;
		}
		if(cnt ==1) answer++;
	}
	cout << answer;
}