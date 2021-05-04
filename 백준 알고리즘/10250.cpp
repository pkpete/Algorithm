#include <iostream>
using namespace std;
int main(){
	int t, h, w, n;
	cin >> t;
	for(int i = 0 ; i < t; i++){
		cin >> h >> w >> n;
		int floor = n % h;
		int room = n / h;
		if(floor>0) room++;
		else floor = h;
		cout << floor*100+room << endl;
	}
}