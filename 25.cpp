#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> arr(n), check(n,0);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i!=j){
				if(arr[i] < arr[j])
					check[i]++;
			}
		}
	}
	for(int i = 0; i < n; i++)
		cout << check[i]+1 << " ";
}