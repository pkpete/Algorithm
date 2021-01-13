#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> card, number;
int main(){
	cin >> n;
	card = vector<int>(n);
	for(int i = 0; i < n; i++)
		cin >> card[i];
	sort(card.begin(), card.end());	// card Á¤·Ä

	cin >> m;
	number = vector<int>(m);
	for(int i = 0; i < m; i++)
		cin >> number[i];

	for(int i = 0; i < m; i++){
		cout << upper_bound(card.begin(), card.end(), number[i]) - lower_bound(card.begin(), card.end(), number[i]) << " ";
	}
}