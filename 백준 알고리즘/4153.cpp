#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
	int arr[3];
	while (1) {
		for (int i = 0; i < 3; i++)
			cin >> arr[i];
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;
		sort(arr, arr + 3);
		if (pow(arr[2], 2) == pow(arr[0], 2) + pow(arr[1], 2))
			cout << "right" << endl;
		else cout << "wrong" << endl;
		
	}
}