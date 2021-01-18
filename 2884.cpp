#include <iostream>
using namespace std;
int main(){
	int h, m;
	cin >> h >> m;
	int hour, min;
	hour = h;
	min = m - 45;
	if(min < 0){
		min = 60 - abs(min);
		hour = hour - 1;
		if(hour < 0)
			hour = 24 - abs(hour);
	}
	cout << hour << " " << min;
}