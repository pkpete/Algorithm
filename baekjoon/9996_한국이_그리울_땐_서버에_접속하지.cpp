#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool visit[100];
int main() {
	int n;
	cin >> n;
	string pattern, tmp;
	cin >> pattern;
	cin.ignore();
	int check=0;
	string first="", second="";
	for (int i = 0; i < pattern.size(); i++) {
		if (pattern[i] == '*') {
			check = 1;
			continue;
		}
		if (check == 0)
			first += pattern[i];
		else
			second += pattern[i];
	}
	reverse(second.begin(), second.end());
	for (int i = 0; i < n; i++) {
		getline(cin,tmp);
		
		bool aws = true;
		for (int j = 0; j < first.size(); j++) {
			visit[j] = true;
			if (first[j] != tmp[j]) {
				aws = false;
				break;
			}
		}
		for (int j = 0; j < second.size(); j++) {
			if (visit[tmp.size() - 1 - j]) {
				aws = false;
				break;
			}
			if (second[j] != tmp[tmp.size() - 1 - j]) {
				aws = false;
			}
		}
		if (aws)
			cout << "DA\n";
		else
			cout << "NE\n";
		for (int j = 0; j < 100; j++)
			visit[j] = false;
	}
}