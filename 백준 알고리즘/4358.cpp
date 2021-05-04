#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, float> m;
int main() {
	string str;
	float cnt = 0;
	while (getline(cin, str)) {
		cnt++;
		if (m.find(str) == m.end()) {
			m[str] = 1;
		}
		else
			m[str]++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = m.begin(); it != m.end(); it++) {
		float val = (it->second / cnt) * 100;
		cout << it->first << " " << val << "\n";
	}
}