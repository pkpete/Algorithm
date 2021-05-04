#include <iostream>
using namespace std;

int gcd(int x, int y){
	int tmp;
	while(y!=0){
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

int main(){
	int x, y;
	cin >> x >> y;
	cout << gcd(x,y) << " " << x*y/gcd(x,y);
}