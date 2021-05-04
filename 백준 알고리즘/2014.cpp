#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> answer;
vector<int> arr;
int main(){
	int k, n, num;
	cin >> k >> n;
	for(int i = 0; i < k; i++){
		cin >> num;
		answer.push(num);
		arr.push_back(num);
	}
	int cnt = 0;
	long long tmp = 0;
	while(cnt < n-1){
		cnt++;
		tmp = answer.top();
		answer.pop();
		for(int i = 0; i < arr.size(); i++){
			if(tmp * arr[i] < pow(2.0,31))
				answer.push(tmp*arr[i]);
		}
		while(tmp == answer.top()){
			answer.pop();
		}
	}
	cout << answer.top();
}