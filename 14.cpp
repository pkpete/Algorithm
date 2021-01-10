#include <iostream>
using namespace std;

int reverse(int x){
	int num = 0;
	while(x > 0){
		num = num * 10 + x%10;
		x /= 10;
	}
	return num;
}

bool isPrime(int x){
	int cnt = 0;
	for(int i = 1; i <= x; i++){
		if(x%i==0)
			cnt++;
	}
	if(cnt == 2) return true;
	else return false;
}

int main(){
	int test, num; 
	cin >> test;
	for(int i = 0; i < test; i++){
		cin >> num;
		int tmp = reverse(num);
		if(isPrime(tmp))
			cout << tmp << endl;
	}
}