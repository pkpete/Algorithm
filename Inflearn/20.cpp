#include <iostream>
using namespace std;
int a[100], b[100];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++){
		if(abs(a[i] - b[i]) == 1){
			if(a[i] > b[i])
				cout << "A" << "\n";
			else cout << "B" << "\n";
		}
		else if(abs(a[i] - b[i]) == 2){
			if(a[i] < b[i])
				cout << "A" << "\n";
			else cout << "B" << "\n";
		}
		else cout << "D" << "\n";
	}
}