#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, num; 
	cin >> n;
	vector<int> v(10001);
	for(int i = 0; i < n; i++){
		cin >> num;
		v[num]++;
	}
	for(int i = 1; i <= 10000; i++){
		while(v[i] != 0){
			cout << i << "\n";
			v[i]--;
		}
	}
}