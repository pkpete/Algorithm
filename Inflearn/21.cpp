#include <iostream>
using namespace std;
int a[10], b[10];
int main(){
	for(int i = 0; i < 10; i++)
		cin >> a[i];
	for(int i = 0; i < 10; i++)
		cin >> b[i];

	int a_point = 0, b_point = 0;
	char str[2] = "D";
	for(int i = 0; i < 10; i++){
		if(a[i] > b[i]){
			a_point += 3;
			str[0] = 'A';
		}
		else if(a[i] < b[i]){
			b_point += 3;
			str[0] = 'B';
		}
		else{
			a_point++;
			b_point++;
		}
	}
	cout << a_point << " " << b_point << "\n";
	if(a_point == b_point)
		cout << str[0];
	else if(a_point>b_point)
		cout << "A";
	else cout << "B";
}