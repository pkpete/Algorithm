#include <iostream>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int cnt=0, answer=0, num;
	for(int i = 0; i < n; i++){
		cin >> num;
		if(num > m){
			cnt++;
			if(answer < cnt)
				answer = cnt;
		}else cnt = 0;
	}
	cout << answer;
}