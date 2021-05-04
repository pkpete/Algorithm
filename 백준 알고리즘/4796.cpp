#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main() {
	int l, p, v;
	int i = 1;
	while (1) {
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)
			break;
		cout << "Case " << i << ": ";
		int num = v / p * l;
		int day = v % p;
		if (day >= l) num += l;
		else num += day;
		cout << num << endl;
		i++;
	}
	
}