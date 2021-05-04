#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n, num;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++){
		cin >> num;
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if(cnt == num){
				if(arr[j] == 0)
					arr[j] = i+1;
				else{
					int tmp = j+1;
					while(1){
						if(arr[tmp] == 0){
							arr[tmp] = i+1;
							break;
						}
						tmp++;
					}
				}
				break;
			}
			if(arr[j] == 0){
				cnt++;
			}
			
		}
	}
	for(int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
}