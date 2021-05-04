#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> pocketmon;
string mp2[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int index = 1;
	while (index <= n) {
		string str;
		cin >> str;
		pocketmon[str] = index;
		mp2[index] = str;
		index++;
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9') {
			cout << mp2[stoi(str)] << "\n";
		}
		else {
			cout << pocketmon[str] << "\n";
		}
	}
}