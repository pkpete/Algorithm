#include <iostream>
#include <vector>
using namespace std;
vector<int> tree, length;
int gcd(int a, int b){
	while(b!=0){
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}
int main(){
	int n;
	cin >> n;
	tree = vector<int> (n);
	for(int i =0; i < n; i++){
		cin >> tree[i];
		if(i>0){
			int tmp = tree[i] - tree[i-1];
			length.push_back(tmp);
		}
	}
	int cmp = 1000000000;
	for(int i = 1; i < length.size(); i++){
		int tmp = gcd(length[i-1], length[i]);
		if(cmp > tmp)
			cmp = tmp;
	}
	int answer = (tree[n-1] - tree[0]) / cmp - n + 1;
	cout << answer;
}