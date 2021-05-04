#include <iostream>
#include <stack>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	stack<int> st;
	char arr[20] = "0123456789ABCDEF";
	while (n > 0) {
		st.push(n % k);
		n /= k;
	}
	while (!st.empty()) {
		cout << arr[st.top()];
		st.pop();
	}
}