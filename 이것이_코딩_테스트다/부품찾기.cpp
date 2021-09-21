#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		int left = 0, right = n - 1;
		bool aws = false;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[mid] == tmp) {
				aws = true;
				break;
			}
			if (arr[mid] < tmp)
				left = mid + 1;
			else if(tmp < arr[mid])
				right = mid - 1;
		}
		if (aws)
			cout << "yes" << " ";
		else
			cout << "no" << " ";
	}	
}