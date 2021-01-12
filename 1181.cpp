#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string x, string y){
	if(x.size() == y.size()){
		for(int i = 0; i < x.size(); i++){
			if(x[i]-'0' < y[i]-'0')
				return true;
			else if(x[i]-'0' > y[i]-'0')
				return false;
		}
	}
	return x.size() < y.size();
}

int main(){
	int n;
	cin >> n;
	string str, tmp;
	vector<string> v;
	for(int i = 0; i < n; i++){
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), cmp);
	//sort(v.begin(), v.end(), cmp2);

	for(int i = 0; i < v.size(); i++){
		if(tmp == v[i]) continue;
		cout << v[i] << "\n";
		tmp = v[i];
	}
}