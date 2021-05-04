#include <iostream>
#include <vector>

using namespace std;

int town;
vector<int> dist, price;
long long min_price = 10000000000, ans = 0;;

void input() {
	cin >> town;
	dist = vector<int>(town - 1);
	price = vector<int>(town);
	for (int i = 0; i < town - 1; i++) 
		cin >> dist[i];
	for (int i = 0; i < town; i++)
		cin >> price[i];
}

int main() {
	input();
	for (int i = 0; i < town - 1; i++) {
		if (price[i] < min_price){
			min_price = price[i];
		}
		ans += min_price * dist[i];
	}
	cout << ans << "\n";
}