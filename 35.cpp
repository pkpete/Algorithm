#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pos, neg;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		if(num > 0)
			pos.push_back(num);
		else neg.push_back(num);
	}

	for(int i = 0; i < neg.size(); i++)
		cout << neg[i] << " ";
	for(int i = 0; i < pos.size(); i++)
		cout << pos[i] << " ";
}