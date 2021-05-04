#include <iostream>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for(int i = m; i <= n; i++){
		if(i%m==0)
			sum += i;
	}
	cout << sum;
}