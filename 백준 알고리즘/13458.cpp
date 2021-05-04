#include <iostream>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, main, sub;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> main >> sub;
	long long answer = n;
	for(int i = 0; i < n; i++){
		arr[i] -= main;
		if(arr[i] > 0){
			if(arr[i] % sub == 0){
				answer += arr[i] / sub;
			}else{
				answer += arr[i] / sub + 1;
			}
		}
	}
	cout << answer;
}