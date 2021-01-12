#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> arr(n), rank(n,1);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << rank[0] << " ";
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] <= arr[j]) rank[i]++;
		}
		cout << rank[i] << " ";
	}
}