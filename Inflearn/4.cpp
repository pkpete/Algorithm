#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	vector<int> v;
	cin >> n;
	int max = -1, min = 1000000;
	for(int i = 0 ; i < n; i++){
		int age;
		cin >> age;
		v.push_back(age);
		if(age > max)
			max = age;
		if(age < min)
			min = age;
	}
	cout << max - min;
}