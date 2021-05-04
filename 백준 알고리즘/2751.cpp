#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, num; 
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> num;
		v[i] = num;
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++)
		cout << v[i] << "\n";
}