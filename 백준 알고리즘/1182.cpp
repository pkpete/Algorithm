#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int n, s;
int cnt = 0;

void find_sum(int index, int sum){
	if(sum == s)cnt++;
	for(int i = index+1; i < n; i++){
		find_sum(i ,sum+arr[i]);
	}
}

int main(){
	cin >> n >> s;
	arr = vector<int> (n);
	for(int i = 0 ; i< n; i++)
		cin >> arr[i];
	for(int i = 0; i < n; i++)
		find_sum(i, arr[i]);
	cout << cnt;
}