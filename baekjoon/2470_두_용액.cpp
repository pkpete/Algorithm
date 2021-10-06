#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int left = 0, right = n - 1;
	int min_sum = 2000000000;
	int n1 = 0, n2 = 0;
	while (left < right) {
		int sum = arr[left] + arr[right];
		if (abs(sum) < min_sum) {
			min_sum = abs(sum);
			n1 = arr[left];
			n2 = arr[right];
			if (sum == 0) break;
		}
		if (sum < 0)
			left++;
		else right--;
	}
	cout << n1 << " " << n2;
	
}