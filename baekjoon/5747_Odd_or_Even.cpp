#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<int> mary, john;	//mary Â¦¼ö john È¦¼ö
int main() {
	while (1) {
		int n; cin >> n;
		if (n == 0) break;
		int tmp, m_even = 0, j_odd = 0;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			if (tmp % 2 == 0 || tmp == 0)
				m_even++;

		}
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			if (tmp % 2 != 0)
				j_odd++;
		}
		cout << abs(m_even - j_odd) << endl;
	}
}