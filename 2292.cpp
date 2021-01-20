#include <iostream>
using namespace std;
int main(){
	long long n;
	cin >> n;
	long long sum = 1;
	long long tmp;
	long long i=1;
	while(1){
		if(sum >= n)
			break;
		tmp = 6*(i++);
		sum += tmp;
	}
	cout << i;
}