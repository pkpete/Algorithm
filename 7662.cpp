#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
void input() {
	int test;
	cin >> test;
	while (test > 0) {
		int k;
		cin >> k;
		multiset<int> ms;
		for (int i = 0; i < k; i++) {
			char c;
			int tmp;
			cin >> c >> tmp;
			if (c == 'I') {
				ms.insert(tmp);
			}
			else if( c == 'D'){
				if (ms.empty()) continue;
				else if (tmp == 1) {
					ms.erase(--ms.end());
				}
				else if (tmp == -1) {
					ms.erase(ms.begin());
				}
			}
		}

		if (ms.empty())
			cout << "EMPTY" << "\n";
		else {
			cout << *(--ms.end()) << " " << *(ms.begin()) << "\n";
		}
		test--;
	}
}
int main() {
	input();
}