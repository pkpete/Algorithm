#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a,b;
void find(int x){
	int start = 0, end = a.size()-1, mid;
	while(start <= end){
		mid = (start+end)/2;
		if(x == a[mid]){
			cout << x << " ";
			break;
		}
		else if(x < a[mid])
			end = mid -1;
		else if(x > a[mid])
			start = mid + 1;
	}
}
int main(){
	int n, m;
	cin >> n;
	a = vector<int> (n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	b = vector<int> (m);
	for(int i = 0; i < m; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for(int i = 0; i < m; i++){
		find(b[i]);
	}
}