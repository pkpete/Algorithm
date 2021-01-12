#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> check(n+1, 0);
	for(int i = 2; i <= n; i++){
		int tmp = i;
		int j = 2;
		while(1){
			if(tmp%j==0){
				check[j]++;
				tmp /= j;
			}
			else j++;
			if(tmp == 1) break;
		}
	}
	cout << n << "! = ";
	for(int i = 2; i <= n; i++)
		if(check[i] != 0) cout << check[i] << " ";
}