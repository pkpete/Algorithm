#include <iostream>
using namespace std;
int arr[1000001];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	arr[1] = 1;
	for(int i = 2; i < 1000001; i++){
		if(arr[i] == 0){
			for(int j = i*2; j < 1000001; j=j+i){
				arr[j] = 1;
			}
		}
	}
	int num;
	cin >> num;
	while(num != 0){
		bool goldbach = false;
		for(int i = num-1; i >= 2; i--){
			if(arr[i] == 0){
				int tmp = num - i;
				if(arr[tmp] == 0){
					cout << num << " = ";
					cout << tmp << " + " << i << "\n";
					goldbach = true;
					break;
				}
			}
		}
		if(!goldbach)
			cout << "Goldbach's conjecture is wrong." << "\n";
		cin >> num;
	}
}