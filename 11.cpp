#include <iostream>
using namespace std;
int main(){
	int n, cnt = 0;
	cin >> n;
	for(int i = 0; i <= n; i++){
		int tmp = i;
		while(tmp > 0){
			cnt++;
			tmp /= 10;
		}
	}
	cout << cnt;
}