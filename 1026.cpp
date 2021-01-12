#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int x, int y){
	return x > y;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), cmp);

	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i] * b[i];
	}
	cout << sum;
}